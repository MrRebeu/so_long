#include "ft_printf.h"


int ft_putstr_fd(char *s, int fd) {
    int count = 0;
    if (!s)  
        return (ft_putstr_fd("(null)", fd));
    while (*s) {
        ft_putchar_fd(*s, fd);
        s++;
        count++;
    }
    return count;
}