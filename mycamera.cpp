#include "mycamera.h"
//封装一个函数把一组YUV数据转换成RGB
int yuvtorgb(int y,int u,int v)
{
    int r,g,b;
    unsigned int pix; //保存一个像素点的ARGB数据
    //r g b正常取值0--255
    r = (298*y + 411 * v - 57344)>>8;
   g = (298*y - 101* u - 211* v+ 34739)>>8;
   b = (298*y + 519* u- 71117)>>8;

    //修正结果
    if(r>255)
        r=255;
    if(g>255)
        g=255;
    if(b>255)
        b=255;

    if(r<0)
        r=0;
    if(g<0)
        g=0;
    if(b<0)
        b=0;
    //好人做到底--》我得知lcd需要ARGB，一步到位
    pix=0x00<<24|r<<16|g<<8|b;
    return pix;
}

//把一帧完整的YUV数据转换成ARGB数据
int allyuvtorgb(char *yuvdata,int *argbdata)
{
    /*
        yuvdata[0]---yuvdata[3]
        argbdata[0] argbdata[1]

    */
    int i,j;
    for(i=0,j=0; j<W*H; i+=4,j+=2) //总共需要640*480组ARGB
    {
        //一组YUYV转换成两组ARGB
        argbdata[j]=yuvtorgb(yuvdata[i],yuvdata[i+1],yuvdata[i+3]);
        argbdata[j+1]=yuvtorgb(yuvdata[i+2],yuvdata[i+1],yuvdata[i+3]);
    }
    return 0;
}
//把一帧完整的YUV数据转换成RGB数据
int allyuvtorgb2(char *yuvdata,char *rgbdata)
{
    /*
        yuvdata[0]---yuvdata[3]
        argbdata[0] argbdata[1]

    */
    int i,j;
    int pix;
    char *p=NULL;
    for(i=0,j=0; i<W*H*3; i+=6,j+=4)  //总共需要W*H组RGB
    {
        //一组YUYV转换成两组ARGB
        pix=yuvtorgb(yuvdata[j],yuvdata[j+1],yuvdata[j+3]);
        //pix存放的是ARGB数据
        p=(char *)&pix;  //p指向pix四个字节中的最低字节(蓝色)
        rgbdata[i]=*(p+2);
        rgbdata[i+1]=*(p+1);
        rgbdata[i+2]=*p;


        pix=yuvtorgb(yuvdata[j+2],yuvdata[j+1],yuvdata[j+3]);
        p=(char *)&pix;  //p指向pix四个字节中的最低字节(蓝色)
        rgbdata[i+3]=*(p+2);
        rgbdata[i+4]=*(p+1);
        rgbdata[i+5]=*p;
    }
}

//封装函数，实现把RGB数据保存成jpg图片
int rgbtojpg(char *rgbdata,const char * jpgname)
{
    int i;
    //定义压缩结构体变量和错误处理变量并初始化
    struct jpeg_compress_struct mycom;
    jpeg_create_compress(&mycom);
    struct jpeg_error_mgr myerr;
    mycom.err=jpeg_std_error(&myerr);

    //设置压缩参数
    mycom.image_width=W;
    mycom.image_height=H;
    mycom.input_components=3;
    mycom.in_color_space=JCS_RGB; //RGB格式
    jpeg_set_defaults(&mycom);

    //设置压缩比例
    jpeg_set_quality(&mycom,78,true);

    //新建空白的jpg文件
    FILE *myfile=fopen(jpgname,"wb");
    if(myfile==NULL)
    {
        perror("新建jpg失败！\n");
        return -1;
    }

    //绑定输出
    jpeg_stdio_dest(&mycom,myfile);

    //开始压缩
    jpeg_start_compress(&mycom,true);

    //定义数组存放要写入jpg中的数据
    JSAMPROW array[1];

    //把压缩后的数据写入到空白的jpg文件中
    /*
        typedef JSAMPLE FAR *JSAMPROW;
        typedef JSAMPROW *JSAMPARRAY;

        rgbdata[0]----rgbdata[W-1]
        rgbdata[W]----rgbdata[2*W-1]
    */
    for(i=0; i<H; i++)
    {

        array[0]=(JSAMPROW )(rgbdata+i*W*3);
        jpeg_write_scanlines(&mycom,array,1);
    }

    //收尾
    jpeg_finish_compress(&mycom);
    jpeg_destroy_compress(&mycom);
    fclose(myfile);
    return 0;
}
mycamera::mycamera()
{

}
//摄像头初始化
int mycamera::camera_init()
{
    int ret;
    int i;
    //打开摄像头的驱动
    camerafd=open("/dev/video7",O_RDWR);
    if(camerafd==-1)
    {
        perror("打开摄像头失败!\n");
        return -1;
    }

    //打开lcd的驱动
//    lcdfd=open("/dev/fb0",O_RDWR);
//    if(lcdfd==-1)
//    {
//        perror("打开lcd失败！\n");
//        return -1;
//    }

//    //映射得到lcd的首地址
//    lcdmem=(int *)mmap(NULL,800*480*4,PROT_READ|PROT_WRITE,MAP_SHARED,lcdfd,0);
//    if(lcdmem==NULL)
//    {
//        perror("映射得到lcd的首地址失败!\n");
//        return -1;
//    }

    //设置摄像头的采集格式
    struct v4l2_format  myfmt;
    bzero(&myfmt,sizeof(myfmt));
    myfmt.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    myfmt.fmt.pix.width=W;
    myfmt.fmt.pix.height=H;
    myfmt.fmt.pix.pixelformat=V4L2_PIX_FMT_YUYV;
    ret=ioctl(camerafd,VIDIOC_S_FMT,&myfmt);
    if(ret==-1)
    {
        perror("设置采集格式失败!\n");
        return -1;
    }

    //跟驱动申请缓冲块
    struct v4l2_requestbuffers mybuf;
    bzero(&mybuf,sizeof(mybuf));
    mybuf.count=4; //4个缓冲块
    mybuf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    mybuf.memory=V4L2_MEMORY_MMAP;
    ret=ioctl(camerafd,VIDIOC_REQBUFS,&mybuf);
    if(ret==-1)
    {
        perror("申请缓冲块失败!\n");
        return -1;
    }

    //分配刚才你申请的4个缓冲块--》循环分配四次
    //顺便映射得到每个缓冲块的首地址
    struct v4l2_buffer otherbuf;
    for(i=0; i<4; i++)
    {
        bzero(&otherbuf,sizeof(otherbuf));
        otherbuf.index=i;
        otherbuf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
        otherbuf.memory=V4L2_MEMORY_MMAP;
        ret=ioctl(camerafd,VIDIOC_QUERYBUF,&otherbuf);
        if(ret==-1)
        {
            perror("分配缓冲块失败!\n");
            return -1;
        }
        //顺便映射得到每个缓冲块的首地址
        array[i].start=mmap(NULL,otherbuf.length,PROT_READ|PROT_WRITE,MAP_SHARED,camerafd,otherbuf.m.offset);
        if(array[i].start==NULL)
        {
            perror("映射缓冲块失败!\n");
            return -1;
        }
        array[i].somelength=otherbuf.length;
        //画面入队
        ret=ioctl(camerafd,VIDIOC_QBUF,&otherbuf);
        if(ret==-1)
        {
            perror("入队失败!\n");
            return -1;
        }
    }

    //启动摄像头采集
    enum v4l2_buf_type mytype=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    ret=ioctl(camerafd,VIDIOC_STREAMON,&mytype);
    if(ret==-1)
    {
        perror("启动摄像头采集失败!\n");
        return -1;
    }
    return 0;
}
//摄像头捕捉
int mycamera::camera_capture(int flag,const char * capjpgname)
{
    int i;
    int ret;
    struct v4l2_buffer otherbuf;
    int argbbuf[W*H];
    char rgbbuf[W*H*3];
    //循环的入队出队显示视频流
    for(i=0; i<4; i++)
    {
        bzero(&otherbuf,sizeof(otherbuf));
        otherbuf.index=i;
        otherbuf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
        otherbuf.memory=V4L2_MEMORY_MMAP;
        //画面出队
        ret=ioctl(camerafd,VIDIOC_DQBUF,&otherbuf);
        if(ret==-1)
        {
            perror("出队失败!\n");
            return -1;
        }
        //画面入队
        ret=ioctl(camerafd,VIDIOC_QBUF,&otherbuf);
        if(ret==-1)
        {
            perror("入队失败!\n");
            return -1;
        }

        //把出队的画面在lcd上显示出来
        //array[i].start(YUV格式) -->填充到lcdmem(ARGB格式)中
        //思路分析：YUV和RGB属于两种不同的颜色编码方式 --》它们之间是可以相互转换
        //yuvtorgb(array[i].start[0],array[i].start[1],array[i].start[3]);
        //yuvtorgb(array[i].start[2],array[i].start[1],array[i].start[3]);
        //把一帧完整的YUV数据转换成ARGB数据
        allyuvtorgb((char *)(array[i].start),argbbuf);
        //把完整的ARGB数据填充到lcd
        /*
            argbbuf[0]  ---argbbuf[640*1-1]        第一行
            lcdmem      ---lcdmem+639
            argbbuf[640]---argbbuf[640*2-1]        第二行
            lcdmem+800  ---lcdmem+
        */
        if(flag == 1)
        {
            allyuvtorgb2((char *)(array[0].start),rgbbuf);
            rgbtojpg(rgbbuf,capjpgname);
            return 0;
        }

        if(flag == 0)
        {


            allyuvtorgb2((char *)(array[i].start),rgbbuf);
            rgbtojpg(rgbbuf,capjpgname);
        }

        /*for(i=0; i<H; i++)
            memcpy(lcdmem+800*i,&argbbuf[W*i],W*4);*/  //内存拷贝，每次把一行画面数据直接拷贝到lcd的地址中
    }

    return 0;
}



int mycamera::camera_close()
{
    int ret;
    //关闭摄像头采集
    enum v4l2_buf_type mytype=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    ret=ioctl(camerafd,VIDIOC_STREAMOFF,&mytype);
    if(ret==-1)
    {
        perror("关闭摄像头采集失败!\n");
        return -1;
    }
//    close(lcdfd);
    close(camerafd);
//    munmap(lcdmem,800*480*4);
    return 0;
}
//重写父类的run()
void mycamera::run()
{
    while(1)
    {
//        m_mutex.lock();
        camera_capture(0,(char *)"monitoring.jpg");

        QPixmap curPixmap;
        curPixmap.load("./monitoring.jpg");
        int iW = this->scr->width();
        QPixmap Npixmap = curPixmap.scaledToWidth(iW);
        LA->setPixmap(Npixmap);
//        m_mutex.unlock();


    }
}

void mycamera::get_monitoring(QLabel * la)
{
    LA = la;
}

void mycamera::get_scro(QScrollArea * scr)
{
    this->scr = scr;

}


void mycamera::threadPause()//暂停线程
{
    this->m_mutex.lock();
}

void mycamera::threadResume()//继续线程
{

    this->m_mutex.unlock();

}

