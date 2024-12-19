#include "ft_printf.h"

void	ft_printhex(unsigned int n, const char type)
{
    if (!type)
        return ;
    char    *hex;

    hex = "0123456789abcdef";
    if (n >= 16)
        ft_printhex(n / 16, type);
    if (type == 'X')
        ft_putchar(ft_toupperr(hex[n % 16]));
    else
        ft_putchar(hex[n % 16]);
}