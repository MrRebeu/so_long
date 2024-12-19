#include "so_long.h"

int check_file_extension(char *filename)
{
    int len;
    
    len = ft_strlen(filename);
    
    // La longueur doit être au moins 5 (.ber + 1 caractère)
    if (len < 5)
        return (0);
    if (filename[len - 4] == '.' &&
        filename[len - 3] == 'b' &&
        filename[len - 2] == 'e' &&
        filename[len - 1] == 'r')
        return (1);
    return (0);
}