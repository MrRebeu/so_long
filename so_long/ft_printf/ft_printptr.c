#include "ft_printf.h"

void ft_printptr(unsigned long n)
{
    char    *hex;

    hex = "0123456789abcdef";

    if (n >= 16)
        ft_printptr( n / 16);
    ft_putchar(hex[n % 16]);
}