#include "ft_printf.h"

int ft_lenptr(unsigned long nbr)
{
    int     len;

    len = 0;
    if (nbr == 0)
        return (1);
    while (nbr)
    {
        len++;
        nbr /= 16;
    }
    return (len);
}