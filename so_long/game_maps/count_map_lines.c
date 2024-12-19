#include "so_long.h"

int count_map_lines(char *filename)
{
    int     totlines;
    int     fd;
    char    *line;
    
    totlines = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    while ((line = get_next_line(fd)))
    {
        totlines++;
        free(line);
    }
    close (fd);
    return (totlines);
}