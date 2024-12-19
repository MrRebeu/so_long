#include "ft_printf.h"

int ft_putnbr_fdd(int n, int fd) 
{
    int count;
    long nb;

    count = 0;
    nb = n;
    if (nb == -2147483648)
    {
        count += ft_putstr_fd("-2147483648", fd);
        return (count);
    }
    if (nb < 0) 
    {
        count += ft_putchar_fd('-', fd);
        nb = -nb;
    }
    if (nb >= 10)
    {
        count += ft_putnbr_fd(nb / 10, fd);
        count += ft_putchar_fd(nb % 10 + '0', fd);
    }
    else
        count += ft_putchar_fd(nb + '0', fd);
    return (count);
}