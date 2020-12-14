#ifndef SERIAL_H
#define SERIAL_H
#include <QThread>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <strings.h>
#include <sys/select.h>
#include <QLineEdit>


class serial:public QThread
{
public:
    serial();

    int serial_init(int fd);
    unsigned char getBCC(unsigned char *buf, int n);
    int serial_mian(char * serial_drive);
    int send_A_order(int fd);
    int send_B_older(int fd);
    void run(); //重写

    int serial_fd;
    char buf[100] = "/dev/ttySAC1";

    volatile unsigned int cardid ;
    /*超时*/
    struct timeval timeout;

    //carid laber
    QLineEdit * carid;
private:


};

#endif // SERIAL_H
