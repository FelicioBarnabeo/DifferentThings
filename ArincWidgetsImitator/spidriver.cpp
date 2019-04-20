#include "spidriver.h"
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

static uint8_t mode = SPI_MODE_0;
static uint8_t bits = 0;
static uint32_t speed = 10000000;
const char * dev = "/dev/spidev32766.0";

void pabort(const char *s)
{
    perror(s);
    abort();
}

/* Open spi device by default /dev/spidev32766.0 */
int open_device(const char *dev = "/dev/spidev32766.0")
{
    int fd = open(dev,O_RDWR);
    return fd;
}

void set_spi_config(int fd)
{
    int ret = 0;
    /* spi mode */
    ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
    if (ret == -1);
        printf("can't set spi mode\n");

    ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
    if (ret == -1);
        printf("can't get spi mode\n");

    /* bits per word */
    ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
    if (ret == -1);
        printf("can't set bits per word\n");

    ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
    if (ret == -1);
        printf("can't get bits per word\n");

    /* max speed hz */
    ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
    if (ret == -1);
        printf("can't set max speed hz\n");

    ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
    if (ret == -1);
        printf("can't get max speed hz\n");

//    printf("spi mode: %d\n", mode);
//    printf("bits per word: %d\n", bits);
//    printf("max speed: %d Hz (%d KHz)\n", speed, speed/1000);
}

/*
 * Write function where fd-file descriptor wr_op-Op_code_for_write_operation
 * point value to massiv for writing and len of this massiv
*/
int write_bit(int fd, u_int8_t wr_op, u_int8_t *value, int len)
{
    int size = len + 1;
    u_int8_t tx[size];
    tx[0] = wr_op;
    int ret = 1;
    for(;ret<size;ret++){
        tx[ret] = value[ret-1];
    }

    spi_ioc_transfer tr =
    {
        (unsigned long)tx,          //__u64           tx_buf;
        (unsigned long)NULL,        //__u64           rx_buf;
        (u_int32_t)size,            //__u32           len;
        0,                          //__u32           speed_hz;
        0,                          //__u16           delay_usecs;
        0,                          //__u8            bits_per_word;
        0,                          //__u8            cs_change;
        0,                          //__u16           pad;
    };

    ret = ioctl(fd,SPI_IOC_MESSAGE(1),&tr);
    //if(ret<0) pabort("Can't write to register %0.2X ");
    //printf("To reg %.2X write : ", wr_op);
    for(ret=0; ret<len; ret++)
        printf("%.2X,",value[ret]);
    printf("\n");
    return ret;
}

/*
 * Read operation where fd-file descriptor
 * Read-op -Op-code for read operation
 * Len - length of byte massiv for read
*/
int read_bit(int fd, u_int8_t read_op, u_int8_t *rx, const int len){
    u_int8_t tx[] = { read_op };
    struct spi_ioc_transfer tr1 = {
        (unsigned long)tx,
        (unsigned long)NULL,
        1,
        0,
        0,
        0,
        0,
        0,
    };

    struct spi_ioc_transfer tr2 = {
        (unsigned long)NULL,
        (unsigned long)rx,
        (u_int32_t)len,
        0,
        0,
        0,
        0,
        0,
    };
    struct spi_ioc_transfer tr[] = {tr1, tr2};
    int ret = 0;
    ret = ioctl(fd,SPI_IOC_MESSAGE(2),&tr);
    for(ret=0; ret < len; ret++){
        printf("read_bit : %.2X,", rx[ret]);
    }
    printf("\n");
    return ret;
}
