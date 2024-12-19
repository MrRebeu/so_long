#include "ft_printf.h"

int     ft_putnbr(int i)
{
    char    *nb;
    int     len;

    nb = ft_itoaa(i);

    if (!nb)
        return (0);
    len = ft_putstr(nb);
    free(nb);
    return (len);
}