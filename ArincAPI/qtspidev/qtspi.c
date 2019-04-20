#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

static uint8_t mode = SPI_MODE_0;
static uint8_t bits = 0;
static uint32_t speed = 12000000;
const char * dev = "/dev/spidev32766.0";

static void pabort(const char *s)
{
    perror(s);
    abort();
}

void set_spi_config(int fd)
{
    int ret = 0;
    /* spi mode */
    ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
    if (ret == -1)
        pabort("can't set spi mode");

    ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
    if (ret == -1)
        pabort("can't get spi mode");

    /* bits per word */
    ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
    if (ret == -1)
        pabort("can't set bits per word");

    ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
    if (ret == -1)
        pabort("can't get bits per word");

    /* max speed hz */
    ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
    if (ret == -1)
        pabort("can't set max speed hz");

    ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
    if (ret == -1)
        pabort("can't get max speed hz");

    printf("spi mode: %d\n", mode);
    printf("bits per word: %d\n", bits);
    printf("max speed: %d Hz (%d KHz)\n", speed, speed/1000);
}

static void write_bit(int fd, u_int8_t wr_op, u_int8_t *value, int len)
{
    int size = len + 1;
    u_int8_t tx[size];
    tx[0] = wr_op;
    int ret = 1;
    for(;ret<size;ret++){
        tx[ret] = value[ret-1];
    }

    struct spi_ioc_transfer tr =
    {
        .tx_buf = (unsigned long)tx,
        .rx_buf = (unsigned long)NULL,
        .len = size,
        .delay_usecs = 0,
        .speed_hz = 0,
        .bits_per_word = bits,
    };

    ret = ioctl(fd,SPI_IOC_MESSAGE(1),&tr);
    if(ret<0) pabort("Can't write to register %0.2X ");
    printf("To reg %.2X write : ", wr_op);
    for(ret=0; ret<len; ret++)
        printf("%.2X,",value[ret]);
    printf("\n");
}

static void read_bit(int fd, u_int8_t read_op, const int len){
    uint8_t tx[] = { read_op };
    struct spi_ioc_transfer tr1 = {
        .tx_buf = (unsigned long)tx,
        .rx_buf = (unsigned long)NULL,
        .len = 1,
        .delay_usecs = 0,
        .speed_hz = 0,
        .bits_per_word = bits,
    };

    u_int8_t rx[32] = {0,};
    struct spi_ioc_transfer tr2 = {
        .tx_buf = (unsigned long)NULL,
        .rx_buf = (unsigned long)rx,
        .len = len,
        .delay_usecs = 0,
        .speed_hz = 0,
        .bits_per_word = bits,
    };
    struct spi_ioc_transfer tr[] = {tr1, tr2};
    int ret = 0;
    ret = ioctl(fd,SPI_IOC_MESSAGE(2),&tr);
    if(ret<0) pabort("Can't write to register %0.2X ");
     printf("reg %.2X = ",read_op);
    for(ret=0; ret < len; ret++){
        printf("%.2X,", rx[ret]);
    }
    printf("\n");
}

static void word32_to20(int word){

}

int main()
{
    int ret = 0;
    int fd;
    /* open device spi */
    fd = open(dev, O_RDWR);
    if (fd < 0)
        pabort("can't open device");
    /* configure device */
    set_spi_config(fd);

    /*  write & read aclk */
    uint8_t mas[] = {0x04};
    write_bit(fd,0x38,mas,1);
    //read_bit(fd,0xD4,1);
    /*  write transmit control register RATE & TMODE & SELFTEST & TFLIP*/
    mas[0] = 0x71;
    write_bit(fd,0x08, mas, 1);

    /* write receiver1 control register set RFLIP and RATE and Labrec*/
    mas[0] = 0x85;
    write_bit(fd,0x10,mas,1);
    /* read receiver1 control register */
    //read_bit(fd,0x94,1);

    //write Look-up table
    uint8_t word[32] = {0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,
                        0x00,0x01,0x00,0x00,0x00,0x00,0x08,0x08,
                        0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,};
    //write_bit(fd,0x14,word,32);

    //read Look-up table
    //read_bit(fd,0x98,32);

    for(ret=0;ret<1000000;ret++){
        /* read Look-up table */
        //read_bit(fd,0x98,32);
        uint8_t arr[4] = {0x33,0x55,0x55,0xC8};
        write_bit(fd,0x0C,arr,4);
        /*read receiver1 status register */
        read_bit(fd,0x90,1);
        /* read receiver1 buffer FIFO */
        read_bit(fd, 0xA0, 4);
        /* software reset */
        //write_bit(fd,0x44,NULL,0);

    }
    close(fd);
    return 0;
}
