#include "ft_printf.h"

int ft_putunbr(unsigned int i)
{
    if (i >= 10)
        ft_putunbr(i / 10);
    ft_putchar((i % 10) + '0');
    return (ft_lenunbr(i));

}
/*
int     ft_putunbr(unsigned int i)
{
    char    *nb;
    int     len;

    nb = ft_itoaa(i);

    if (!nb)
        return (0);
    len = ft_putstr(nb);
    free(nb);
    return (len);
}*/