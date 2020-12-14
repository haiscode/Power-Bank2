#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);




    this->setWindowTitle("共享电宝");

    //初始化摄像头
    CA = new mycamera;
    CA->camera_init();


    connect(&manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(recvhttp(QNetworkReply*)));
    //初始化天气
    weather_init();


    //初始化时间
    QTimer * timer = new QTimer(this);
    timer->start(1000);
    connect(timer,&QTimer::timeout,this,[=](){
        ui->datetime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    });
    QStringList list;

    list<<"电宝序号"<<"状态"<<"电量";

    ui->tableWidget->setColumnCount(list.count());
    ui->tableWidget->setHorizontalHeaderLabels(list);



    ui->tableWidget_2->setColumnCount(list.count());
    ui->tableWidget_2->setHorizontalHeaderLabels(list);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    mybase = new QSqlDatabase;
    //初始化数据库信息
    *mybase = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库名字
    mybase->setDatabaseName("shareblechargers.db");

    //打开数据库
    if(false == mybase->open())
    {
        QMessageBox::warning(this,NULL,"数据库打开失败");
        return ;
    }



    sqlite_flush();


    renttimer = new QTimer(this);
    connect(renttimer,SIGNAL(timeout()),this,SLOT(rentime()));

    //renttip字体颜色
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);
    ui->renttip->setPalette(pa);

    //开启线程
    arun= new serial;
    arun->carid = ui->caridline;
    arun->start();

    //设置管理员卡号
    managercarid = QString("2997629225");


}
void Widget::weather_init()
{



    //从lineEdit获取天气预报的地址

    QUrl url("http://t.weather.itboy.net/api/weather/city/101280101");
    //定义一个请求对象
    QNetworkRequest req(url);
    //发送请求
    manager.get(req);

}
void Widget::recvhttp(QNetworkReply* reply)
{
    //读取应答信息
    QByteArray buf=reply->readAll();
    QString str(buf);

    QJsonParseError err;

    QJsonDocument doc=QJsonDocument::fromJson(buf,&err);
        if(err.error!=QJsonParseError::NoError) //错误
        {
            qDebug()<<"json格式数据有问题";
            return;
        }

    //得到最外层的对象{}
    QJsonObject obj=doc.object();
    QJsonObject Mdata =obj.value("data").toObject();
    QJsonArray array =Mdata.value("forecast").toArray();
    QJsonObject Dataitem = array.at(0).toObject();//今天

    //显示今天天气
    ui->weather->setText(QString("广州天气  %1  %2  风向：%3   %4  %5")
            .arg(Dataitem["week"].toString())
            .arg(Dataitem["type"].toString())
            .arg(Dataitem["fx"].toString())
            .arg(Dataitem["high"].toString())
            .arg(Dataitem["low"].toString())

                         );



}
/*刷新数据*/
void Widget::sqlite_flush()
{



    //从数据库添加内容到table中
    flush_tab();

}


void Widget::flush_tab()
{
    //刷新货栏信息

    int i = ui->tableWidget->rowCount()-1 ;

    for (;i>=0;i--) {

            ui->tableWidget->removeRow(i);

        }
    i = ui->tableWidget_2->rowCount()-1;
    for (;i>=0;i--) {

            ui->tableWidget_2->removeRow(i);

        }


    addit("tableA",ui->tableWidget);
    addit("tableB",ui->tableWidget_2);
}

void Widget::addit(QString tablename,QTableWidget * table)
{
    QSqlQuery myquery(*mybase);
    myquery.exec(QString("select * from %1;").arg(tablename));
    //将数据库的内容添加到table中


    int count = 0;
    //电宝序列号  使用状态    电量
    while(myquery.next())
    {
        //开辟新空间
        int Addrow = table->rowCount();
        table->insertRow(Addrow);
        //新建序列号
        QTableWidgetItem *item = new QTableWidgetItem(myquery.value("series").toString(),1001);
        //文本居中
        item->setTextAlignment(Qt::AlignCenter);

        table->setItem(Addrow,Widget::colseries,item);
        //新建状态
        item = new QTableWidgetItem(myquery.value("status").toString(),1002);
        //文本居中
        item->setTextAlignment(Qt::AlignCenter);
        if(myquery.value("status").toString() == "空闲")
        {
            count ++;
            item->setBackground(QBrush(Qt::green));
        }else if(myquery.value("status").toString() == "租出")
        {
            item->setBackground(QBrush(Qt::red));
        }else if(myquery.value("status").toString() == "停用")
        {
            item->setBackground(QBrush(Qt::gray));
        }

        table->setItem(Addrow,Widget::colstatus,item);
        QString elevalue = QString("%1%").arg(myquery.value("electric").toString());

        //新建电量
        item = new QTableWidgetItem(elevalue,1003);
        //文本居中
        item->setTextAlignment(Qt::AlignCenter);

        table->setItem(Addrow,Widget::colelectric,item);
    }
    table->setToolTip(QString::number(count));


    return;
}
Widget::~Widget()
{
    delete ui;
//    CA->camera_close();
//    renttimer->stop();
//    arun->quit();
//    arun->wait();

//    delete mybase;
//    delete arun;
//    delete table;
//    delete renttimer;
//    delete managerinterface;
}

/*切换*/
void Widget::on_pushButton_3_clicked()
{
    int nCount = ui->stackedWidget->count();
    int nIndex = ui->stackedWidget->currentIndex();

    // 获取下一个需要显示的页面索引
    ++nIndex;
    // 当需要显示的页面索引大于等于总页面时，切换至首页
    if (nIndex >= nCount)
        nIndex = 0;

    ui->stackedWidget->setCurrentIndex(nIndex);
    //A
    if(nIndex == 1)
    {
        ui->enalbe->setText(QString("可用电宝：%1 货架A").arg(ui->tableWidget->toolTip()));
    }else if(nIndex == 0)//B
    {
        ui->enalbe->setText(QString("可用电宝：%1 货架B").arg(ui->tableWidget_2->toolTip()));
    }
}

/*二维码支付界面*/
void Widget::on_pushButton_clicked()
{


}



/*car改变则触发*/
//create table acctable(carid text unique not null,bal float not null,inuse text);  卡号  金额   货架|使用电宝
//create table onlineatlb(carid text unique not null,ontime text);  卡号  使用初时间
void Widget::on_caridline_textChanged(const QString &arg1)
{
    if(arg1 == QString("卡号："))
    {
        return;
    }

    /*管理人员刷卡 ----》进入管理界面*/
    if(ui->caridline->toolTip() == managercarid)
    {

        //管理员界面
        managerinterface = new Goldfinger(this);

        //管理界面数据库驱动、摄像头
        managerinterface->getmybase(mybase);
        managerinterface->getCA(CA);

        //管理员界面用户卡信息列表and 货架信息树列表刷新
        managerinterface->flushuserlist();
        managerinterface->flushstrogalist();




        ui->bal->setText(QString("卡内余额："));
        ui->caridline->setText(QString("卡号："));
        ui->caridline->setToolTip("");
//        this->hide();

        managerinterface->show();

        return;
    }

    //insert into acctable values("2997629225",87.1,"无");
    //读取数据库用户表信息acctable

    QSqlQuery myquery(*mybase);
    myquery.exec(QString("select * from acctable;"));

    while(myquery.next())
    {

        if(ui->caridline->toolTip() == myquery.value("carid").toString())
        {
            /*第二次刷卡----》归还*/
            if(myquery.value("inuse").toString() != QString("无"))
            {
                //获取货柜信息
                QStringList list = myquery.value("inuse").toString().split("@");
                QString storage = list.at(0);//所在货柜信息
                /*更新消费信息*/
                show_baltime(myquery.value("carid").toString(),myquery.value("inuse").toString(),storage);
                //显示使用的电宝
                ui->inuse->setText(QString("使用电宝：货架%1 %2")
                                   .arg(list.at(0))
                                   .arg(list.at(1)));
                //将该行从onlineatlb删除
                QSqlQuery todelquery(*mybase);
                todelquery.exec(QString("delete from onlineatlb where carid=\"%1\";")
                                .arg(myquery.value("carid").toString()));
                //更新acctable该用户使用电宝状态
                QSqlQuery toupdatquery(*mybase);
                toupdatquery.exec(QString("update acctable set inuse=\"无\" where carid=\"%1\" and inuse=\"%2\";")
                                .arg(myquery.value("carid").toString())
                                .arg(myquery.value("inuse").toString()));

                ui->bal->setText(QString("卡内余额："));
                ui->caridline->setText(QString("卡号："));
                ui->caridline->setToolTip("");

//                QMessageBox::information(NULL,"Ok",tr("归还成功"));



                //刷新表格
                flush_tab();
                //管理员界面用户卡信息列表and 货架信息树列表刷新
//                managerinterface->flushuserlist();
//                managerinterface->flushstrogalist();


                QMessageBox *box = new QMessageBox(QMessageBox::Information,"Ok",tr("归还成功"));
                QTimer::singleShot(3000,box,SLOT(close()));
                box->show();


                return;
            }
            /*第一次刷卡   ---->租借*/
            //获取用户个人信息和消费信息
            ui->bal->setText(QString("卡内余额：%1元").arg(myquery.value("bal").toString()));
            ui->usefultime->setText("本次使用时间：0");
            ui->usefulbal->setText("本次使用费用：0");
            ui->inuse->setText("使用电宝：待选");
            ui->renttip->clear();
            ui->rent->setEnabled(true);



            //开始租借按钮计时间
            Nrentime = 30;
            renttimer->start(1000);


            return;
        }
    }


}

/*显示使用时间、费用    一个月之内*/
void Widget::show_baltime(QString Ncarid,QString inuse,QString storage)
{
    QSqlQuery myquery(*mybase);
    myquery.exec(QString("select * from onlineatlb;"));
    while(myquery.next())
    {

        if(Ncarid == myquery.value("carid").toString())
        {
            //获得使用秒数
            QDateTime oldtime = QDateTime::fromString(myquery.value("ontime").toString(),"yyyy-MM-dd hh:mm:ss");
            QDateTime nowtime = QDateTime::fromString(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"),"yyyy-MM-dd hh:mm:ss");
            qint64 useSec =oldtime.secsTo(nowtime);

            //秒转成分钟
            float usemin = (float)useSec/60;
            ui->usefultime->setText(QString("本次使用时间：%1分").arg(usemin));
            //计算费用 --->一小时1元  不到1小时按1小时算
            float usebal = (float)usemin/60;
            ui->usefulbal->setText(QString("本次费用：%1元").arg(usebal));

            //更新卡内金额
            updatebal(Ncarid,usebal);


            //更新电宝电量   1分钟消耗电量电量0.1%
            updateele(usemin,inuse,storage);



            return;
        }
    }
}

void Widget::rentime()
{
    if(Nrentime == 0)
    {
        ui->rent->setText(QString("租借"));
        ui->rent->setEnabled(false);
        ui->bal->setText(QString("卡内余额："));
        ui->caridline->setText(QString("卡号："));
        ui->caridline->setToolTip("");
        ui->usefultime->setText("本次使用时间：");
        ui->usefulbal->setText("本次使用费用：");
        ui->inuse->setText("使用电宝：");
        renttimer->stop();
//        disconnect(renttimer,SIGNAL(timeout()),this,SLOT(rentime()));
//        delete  renttimer;
//        renttimer = NULL;
        return;
    }
    ui->rent->setText(QString("租借(%1)").arg(QString::number(Nrentime--)));
}

/*租借*/
void Widget::on_rent_clicked()
{

    renttimer->stop();
    QString tablename;
    /*获取当前表格*/
    if(ui->stackedWidget->currentIndex() == 1)
    {
        tablename=QString("A");
        table = ui->tableWidget;
    }else if(ui->stackedWidget->currentIndex() == 0)
    {
        tablename=QString("B");
        table = ui->tableWidget_2;
    }
    /*未选择*/
    if(table->currentRow() == -1)
    {
        ui->renttip->setText("请选择电宝");

        //重新开始
        Nrentime = 30;
        renttimer->start();
        return;
    }
    /*选择停用或者租出 则被拒绝*/
    if(table->item(table->currentRow(),Widget::colstatus)->text() == "租出" ||
           table->item(table->currentRow(),Widget::colstatus)->text() == "停用" )
    {

        ui->renttip->setText("该电宝已停用或者租出");

        //重新开始
        Nrentime = 30;
        renttimer->start();
        return;
    }
    ui->renttip->clear();
    //获取被选择电宝的序列号
    QString Bseries = table->item(table->currentRow(),Widget::colseries)->text();
    /*将信息与电宝序号信息添加入acctable、onlineatlb*/
    QSqlQuery myquery(*mybase);
    myquery.exec(QString("select * from acctable;"));
    while(myquery.next())
    {

        if(ui->caridline->toolTip() == myquery.value("carid").toString())
        {
            //修改卡号对应的使用电宝内容
            QSqlQuery toupdatquery(*mybase);
            QString NBseries = tablename + "@" + Bseries;
            toupdatquery.exec(QString("update acctable set inuse=\"%1\" where carid=\"%2\" and inuse=\"无\";")
                            .arg(NBseries)
                            .arg(myquery.value("carid").toString())
                              );
            //添加到onlineatlb --》记录的时间
            QSqlQuery toinequery(*mybase);
            QString Ntime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            toinequery.exec(QString("insert into onlineatlb values(\"%1\",\"%2\");")
                            .arg(ui->caridline->toolTip())
                            .arg(Ntime)
                            );
            //更新电宝状态

            setstatues(Bseries,"租出",tablename,1);

            //提示
//            QMessageBox::information(NULL,"Ok",tr("租借成功"));


            ui->rent->setText(QString("租借"));
            ui->rent->setEnabled(false);

            ui->bal->setText(QString("卡内余额："));
            ui->caridline->setText(QString("卡号："));
            ui->caridline->setToolTip("");
            ui->usefultime->setText("本次使用时间：");
            ui->usefulbal->setText("本次使用费用：");
            ui->inuse->setText("使用电宝：");


            Nrentime = 30;

            //刷新表格
            flush_tab();

            //管理员界面用户卡信息列表and 货架信息树列表刷新
//            managerinterface->flushuserlist();
//            managerinterface->flushstrogalist();



            //拍摄租借时的图片并存到本地
            CA->camera_capture(1,(QString("%1_%2.jpg")
                               .arg(myquery.value("carid").toString())
                               .arg(QDateTime::currentDateTime().toString("MMddhhmmyyyy")))
                               .toStdString().c_str()
                            );


            QMessageBox *box = new QMessageBox(QMessageBox::Information,"OK",tr("租借成功"));
            QTimer::singleShot(3000,box,SLOT(close()));
            box->show();
            return;
        }
    }

}

/*更新数据库电宝电量*/
void Widget::updateele(float usemin,QString inuse,QString storage)
{
    QSqlQuery myquery(*mybase);
    QString tablename;

    if(storage == "A")
    {

        tablename = QString("tableA");
        myquery.exec(QString("select * from tableA;"));
    }else if(storage == "B")
    {
        tablename = QString("tableB");
        myquery.exec(QString("select * from tableB;"));
    }
    QStringList list = inuse.split("@");
    QString Ninuse = list.at(1);//电宝序号
//    qDebug()<<Ninuse;
    //获取之前电量
    while(myquery.next())
    {
        if(myquery.value("series").toString() == Ninuse)
        {
            float oldseries = myquery.value("electric").toString().toFloat();
            float newseries = oldseries - usemin*0.1;
            if(newseries <=  0)
            {
                //设置停用

                newseries = 0;
                QSqlQuery toupdatquery(*mybase);
                toupdatquery.exec(QString("update %1 set status=\"停用\" where series=\"%2\" and status=\"租出\";")
                                .arg(tablename)
                                .arg(inuse)

                                  );
                //更新电量
                QSqlQuery Mtoupdatquery(*mybase);
                Mtoupdatquery.exec(QString("update %1 set electric=%2 where series=\"%3\" and electric=%4;")
                                .arg(tablename)
                                .arg(newseries)
                                .arg(Ninuse)
                                .arg(myquery.value("electric").toString())
                                  );
                return;
            }

            //更新电量
            QSqlQuery toupdatquery(*mybase);
            toupdatquery.exec(QString("update %1 set electric=%2 where series=\"%3\" and electric=%4;")
                              .arg(tablename)
                            .arg(newseries)
                            .arg(Ninuse)
                            .arg(myquery.value("electric").toString())
                              );
            //设置空闲

            newseries = 0;
            QSqlQuery Mtoupdatquery(*mybase);
            Mtoupdatquery.exec(QString("update %1 set status=\"空闲\" where series=\"%2\" and status=\"租出\";")
                               .arg(tablename)

                            .arg(Ninuse)

                              );


            return;
        }
    }

}

/*更新状态*/
void Widget::setstatues(QString inuse,QString statues,QString storage,int flag)
{
    QSqlQuery myquery(*mybase);
    QString tablename;
    if(storage == "A")
    {
        tablename = QString("tableA");
        myquery.exec(QString("select * from tableA;"));
    }else if(storage == "B")
    {
        tablename = QString("tableB");
        myquery.exec(QString("select * from tableB;"));
    }

    while(myquery.next())
    {
        if(myquery.value("series").toString() == inuse)
        {
            if(flag == 0)
            {
                QSqlQuery Mtoupdatquery(*mybase);
                Mtoupdatquery.exec(QString("update %1 set status=\"%2\" where series=\"%3\" and status=\"停用\";")
                                   .arg(tablename)
                                .arg(statues)
                                .arg(inuse)

                                  );
                return;
            }else if(flag == 1)
            {
                QSqlQuery Mtoupdatquery(*mybase);
                Mtoupdatquery.exec(QString("update %1 set status=\"%2\" where series=\"%3\" and status=\"空闲\";")
                                   .arg(tablename)
                                .arg(statues)
                                .arg(inuse)

                                  );
                 return;

            }else if(flag == 2)
            {
//                qDebug()<<tablename;
//                qDebug()<<statues;
//                qDebug()<<inuse;
                QSqlQuery Mtoupdatquery(*mybase);
                Mtoupdatquery.exec(QString("update %1 set status=\"%2\" where series=\"%3\" and status=\"租出\";")
                                 .arg(tablename)
                                .arg(statues)
                                .arg(inuse)

                                  );
                 return;

            }

        }

    }

}
/*更新余额*/
void Widget::updatebal(QString Ncarid,float usebal)
{
    QSqlQuery myquery(*mybase);
    myquery.exec(QString("select * from acctable;"));
    while(myquery.next())
    {
        if(Ncarid == myquery.value("carid").toString())
        {
            //获取余额
            float oldbal = myquery.value("bal").toString().toFloat();
            float newbal = oldbal - usebal;
            QSqlQuery Mtoupdatquery(*mybase);
            Mtoupdatquery.exec(QString("update acctable set bal=%1 where carid=\"%2\" and bal=%3;")
                             .arg(newbal)
                            .arg(Ncarid)
                            .arg(myquery.value("bal").toString())

                              );
            return;
        }


    }

}


