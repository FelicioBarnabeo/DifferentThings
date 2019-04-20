#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

static void pabort(const char *s)
{
    perror(s);
    abort();
}

static uint8_t mode = SPI_MODE_0;
static uint8_t bits = 0;
static uint32_t speed = 500000;

int main(int argc, char *argv[])
{
    const char * dev = "/dev/spidev32766.0";
    int ret = 0;
    int fd;
    uint8_t tx[] = { 0x81, 0x18 };
    uint8_t rx[] = {0, 0 };

    /*if(argc!=2) {
        fprintf(stderr, "Usage: %s <spidev>\n", argv[0]);
        exit(1);
    }*/

    fd = open(dev, O_RDWR);
    if (fd < 0)
        pabort("can't open device");

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

    /* full-duplex transfer */
    struct spi_ioc_transfer tr = {
        .tx_buf = (unsigned long)tx,
        .rx_buf = (unsigned long)rx,
        .len = 2,
        .delay_usecs = 0,
        .speed_hz = 0,
        .bits_per_word = bits,
    };

    ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
    if (ret < 1)
        pabort("can't send spi message");

    for (ret = 0; ret < 2; ret++) {
        printf("%.2X ", rx[ret]);
    }
    puts("");

    close(fd);

    return ret;
}
