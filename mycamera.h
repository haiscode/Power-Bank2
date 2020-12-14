#ifndef MYCAMERA_H
#define MYCAMERA_H
#include <stdio.h>
#include <sys/mman.h>
#include <linux/videodev2.h> //摄像头有关的头文件
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <QThread>
#include <stdio.h>
#include <sys/mman.h>
#include <linux/videodev2.h> //摄像头有关的头文件
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <QLabel>
#include <QPixmap>
#include <QPixmapCache>
#include <QScrollArea>

#include <QMutex>

#include "jpeglib.h"   //jpg库的头文件

#define W 320
#define H 240
//自定义一个结构体把每个缓冲块的首地址和大小保存起来
struct camerabuf
{
    void *start;    //指向每个缓冲块首地址
    int somelength; //保存每个缓冲块大小
};

class mycamera:public QThread
{
public:
    mycamera();
    int camera_init();
    int camera_capture(int flag,const char * capjpgname);
    int camera_close();

    void get_monitoring(QLabel * la);


    void get_scro(QScrollArea * scr);

    //重写父类QThread的run();
    void run();

    void threadPause();//暂停线程

    void threadResume();//继续线程
private:
    int camerafd;
    int lcdfd;
    int *lcdmem;
    //定义结构体数组存放四个缓冲块的信息
    struct camerabuf array[4];
    QLabel * LA;

    QScrollArea * scr;

    QMutex m_mutex;//互斥量
};

#endif // MYCAMERA_H
