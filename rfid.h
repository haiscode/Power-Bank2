#ifndef RFID_H
#define RFID_H


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/select.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <strings.h>
#include <linux/input.h>

class rfid
{
public:
    rfid();
    void init_tty(int fd);
    unsigned char CalBCC(unsigned char *buf, int n);
    int PiccRequest(int fd);
    int PiccAnticoll(int fd);
    int open_serial();


    struct timeval timeout;
    volatile unsigned int cardid ;
private:

};

#endif // RFID_H
