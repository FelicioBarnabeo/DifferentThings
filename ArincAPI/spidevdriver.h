#ifndef ARINCDRIVER
#define ARINCDRIVER

#include <fcntl.h>

int read_bit(int fd, u_int8_t read_op, u_int8_t *rx, const int len);
int write_bit(int fd, u_int8_t wr_op, u_int8_t *value, int len);
int open_device(const char *dev);

#endif // ARINCDRIVER

