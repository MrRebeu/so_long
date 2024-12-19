#include "ft_printf.h"

int	ft_isdigitt(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}