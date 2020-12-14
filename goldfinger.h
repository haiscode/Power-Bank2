#ifndef GOLDFINGER_H
#define GOLDFINGER_H

#include <QWidget>
#include <QDialog>
#include <QColorDialog>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QListWidgetItem>
#include <QTreeWidgetItem>
#include <QTreeWidget>


#include "mycamera.h"

namespace Ui {
class Goldfinger;
}

class Goldfinger : public QDialog
{
    Q_OBJECT

public:
    explicit Goldfinger(QWidget *parent = nullptr);
    ~Goldfinger();

    void setmanagercarid(QString carid);

    void flushuserlist();

    void flushstrogalist();

    void getmybase(QSqlDatabase * base);

    void flush_com();

    QString getFinalFolderName(const QString & Filepathname);

    void getCA(mycamera *ca);

//    void cap(char * filename);

private slots:
    void on_pushButton_3_clicked();

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();



    void on_pushButton_5_clicked();



    void on_comboBox_activated(int index);



private:
    Ui::Goldfinger *ui;

    //管理员卡号
    QString managercarid;
    //数据库
    QSqlDatabase *mybase;

    QTreeWidgetItem * itemA;
    QTreeWidgetItem * itemB;
    //摄像头
    mycamera * CA;

};

#endif // GOLDFINGER_H
