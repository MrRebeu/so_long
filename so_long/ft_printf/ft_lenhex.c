#include "ft_printf.h"

int     ft_lenhex(unsigned  nbr)
{
    int     len;

    len = 0;
    if (nbr == 0)
        return (1);
    while (nbr)
    {
        nbr /= 16;
        len++;
    }
    return (len);
}