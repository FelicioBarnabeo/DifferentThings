#include <QCoreApplication>
#include "termios.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "errno.h"
#include "QDebug"
#include <asm-generic/ioctls.h>
#include <sys/ioctl.h>
#include <linux/serial.h>
#include "stdio.h"
#include "cstring"

//struct serial_struct ser_info;

struct termios config;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //ser_info.baud_base = B115200;
    const char * serial_device = "/dev/ttyUSB0";
    int fd = open(serial_device,O_RDWR | O_NOCTTY | O_NDELAY);
    if(fd == -1)
    {
        perror("failed to open port ");
    }

//    int res = ioctl(fd,TIOCSSERIAL, &ser_info);
//    if(res == -1){
//        perror("ioctl");
//        printf("cant ioctl TIOCSSERIAL\n");
//    }
    //check if device is serial device
    if(isatty(fd)) qDebug()<< serial_device << "It's serial device";
    // get current configuration of sd (serial device) interface
    if(tcgetattr(fd, &config) != -1 )
    {
        qDebug()<< "c_cc : "     << config.c_cc << endl
                << "c_flag : "   << config.c_cflag << endl
                << "c_iflag : "  << config.c_iflag << endl
                << "c_ispedd : " << config.c_ispeed << endl
                << "c_lflag : "  << config.c_lflag << endl
                << "c_line : "   << config.c_line << endl
                << "c_oflag : "  << config.c_oflag << endl
                << "c_ospeed : " << config.c_ospeed;
    }
    else( perror("failed tcgetattr()"));

    //SET CONFIGURATION
    // Input flags - Turn off input processing
     //
     // convert break to null byte, no CR to NL translation,
     // no NL to CR translation, don't mark parity errors or breaks
     // no input parity check, don't strip high bit off,
     // no XON/XOFF software flow control
     //
     //config.c_iflag &= ~(IGNBRK | BRKINT | ICRNL | INLCR | PARMRK | INPCK | ISTRIP | IXON);

     //
     // Output flags - Turn off output processing
     //
     // no CR to NL translation, no NL to CR-NL translation,
     // no NL to CR translation, no column 0 CR suppression,
     // no Ctrl-D suppression, no fill characters, no case mapping,
     // no local output processing
     //
     // config.c_oflag &= ~(OCRNL | ONLCR | ONLRET |
     //                     ONOCR | ONOEOT| OFILL | OLCUC | OPOST);
     //config.c_oflag = 0;

     //
     // No line processing
     //
     // echo off, echo newline off, canonical mode off,
     // extended input processing off, signal chars off
     //
     //config.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);

     //
     // Turn off character processing
     //
     // clear current char size mask, no parity checking,
     // no output processing, force 8 bit input
     //
     //config.c_cflag &= ~(CSIZE | PARENB);
     //config.c_cflag |= CS8;

     //
     // One input byte is enough to return from read()
     // Inter-character timer off
     //
     config.c_cc[VMIN]  = 1;
     config.c_cc[VTIME] = 2;

     //
     // Communication speed (simple version, using the predefined
     // constants)
     //
     if(cfsetispeed(&config, B115200) < 0 || cfsetospeed(&config, B115200) < 0) {
        perror("Cant set right baudrate speed, cfsetispeed or cfsetospeed failed ");
     }

     //
     // Finally, apply the configuration
     //
     if(tcsetattr(fd, TCSAFLUSH, &config) < 0) {
        perror("Cant set configuration, tcsetattr() failed ");
     }

     const char *transmitting_file =  "transmit";
     int file = open(transmitting_file,O_RDONLY);
     if(file==-1)
         perror("failed to open transmit");
     int res = 0;
     int read_bytes, all_bytes = 0;
     int wr_bytes = 0;
     char buf[1024];
     char c;
     printf("sizeof(buf) %d\n",sizeof(buf));
     while(read(file,&c,1) == 1)
     {
         //printf("%c",c);
         all_bytes ++;
         if(write(fd,&c,1)) wr_bytes++;
         else perror("write()");
     }
//     if((res = write(fd,transmitting_file,strlen(transmitting_file)+1)) == -1)
//        perror("write");
//     else{
//         printf("Transmitted bytes: %d",res);
//     }
     printf("allbytes = %d\n", all_bytes);
     printf("wr_bytes = %d\n", wr_bytes);
     close(file);
     //close(fd);

    return 0;
}
