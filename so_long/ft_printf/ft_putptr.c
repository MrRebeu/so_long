#include "ft_printf.h"

int ft_putptr(void *ptr)
{
    int len;

    if (!ptr)
        return (ft_putstr_fd("(nil)", 1));
    len = write(1, "0x", 2);
    ft_printptr((unsigned long)ptr);
    len += ft_lenptr((unsigned long)ptr);
    return (len);
}