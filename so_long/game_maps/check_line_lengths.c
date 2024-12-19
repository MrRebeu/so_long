#include "so_long.h"

int check_line_lengths(char *filename, int *width)
{
    int     fd;
    char    *line;
    int     len;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    line = get_next_line(fd);
    if (!line)
    {
        close (fd);
        return (0);
    }
    len = ft_strlen(line);
    if (line[len - 1] == '\n')
        len--;
    *width = len;
    free(line);
    while ((line = get_next_line(fd)))
    {
        len = ft_strlen(line);
        if (line[len - 1] == '\n')
            len--;
        if (*width != len)
        {
            free(line);
            close (fd);
            return (0);
        }
        free(line);
    }
    close (fd);
    return (0);
}