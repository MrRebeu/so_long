#include "ft_printf.h"

int     ft_puthex(unsigned int nbr, char type)
{
    ft_printhex(nbr, type);
    return(ft_lenhex(nbr));
}