#include "ft_printf.h"

int ft_putunbr_fd(unsigned int n, int fd)
{
    int i;

    i = n;
    if (n / 10)
		ft_putunbr(n / 10);
	ft_putchar(n % 10 + '0');
    return (ft_lenunbr(i));
}
