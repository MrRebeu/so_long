#include "ft_printf.h"

int	ft_toupperr(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}