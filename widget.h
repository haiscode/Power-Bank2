#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QBrush>
#include <QPalette>

#include "serial.h"
#include "goldfinger.h"
#include "mycamera.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void weather_init();


    //读取数据库数据刷新table
    void sqlite_flush();

    void flush_tab();

    void addit(QString tablename,QTableWidget * table);

    void show_baltime(QString Ncarid,QString inuse,QString storage);

    void updateele(float usemin,QString inuse,QString storage);

    void setstatues(QString inuse,QString statues,QString storage,int flag);

    void updatebal(QString Ncarid,float usebal);



private slots:
    void on_pushButton_3_clicked();
    void recvhttp(QNetworkReply* reply);

    //管理员登录
    void on_pushButton_clicked();


    void rentime();





    void on_caridline_textChanged(const QString &arg1);

    void on_rent_clicked();



private:
    Ui::Widget *ui;
    QNetworkAccessManager manager;
    enum chargers{colseries= 0,colstatus,colelectric};
    QSqlDatabase *mybase;

    serial *arun;

    //rent租借按钮计数器
    QTimer *renttimer;
    int Nrentime;

    //管理员卡号
    QString managercarid;
    //管理员界面
    Goldfinger * managerinterface;

    QTableWidget * table;
    //摄像头
    mycamera * CA;

};
#endif // WIDGET_H
