#include "ft_printf.h"

int ft_puthex_fd(unsigned int n, int fd, char format)
{
    int count = 0;
    if (n >= 16) {
        count += ft_puthex_fd(n / 16, fd, format);
    }
    char c;
    if (n % 16 < 10) {
        c = (n % 16) + '0';
    } else {
        c = (n % 16 - 10) + (format == 'x' ? 'a' : 'A');
    }
    write(fd, &c, 1);
    return count + 1;
}
