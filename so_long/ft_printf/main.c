#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
    printf("\n=== Test nombres basiques ===\n");
    printf("printf    : %u\n", 0);
    ft_printf("ft_printf : %u\n", 0);
    
    
    printf("\n=== Test valeurs limites ===\n");
    printf("printf    : %u\n", 9223372036854775807LL);
    ft_printf("ft_printf : %u\n",9223372036854775807L );
    
    printf("printf    : %u\n", LONG_MIN);
    ft_printf("ft_printf : %u\n", LONG_MIN);
    
    
    return 0;
}