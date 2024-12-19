#include "so_long.h"

int fill_map_data(Map *map, char *filename)
{
    int     fd;
    char    *line;
    int     i;
    int     j;

    i = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    while ((line = get_next_line(fd)))
    {
        map->grid[i] = line;
        j = 0;
        while (line[j])
        {
            if (line[j] == 'C')
                map->collectible_count++;
            if (line[j] == 'P')
            {
                map->start_pos[0] = j;// position X (colonne)
                map->start_pos[1] = i;// position Y (ligne)
            }
            if (line[j] == 'E')
            {
                map->exit_pos[0] = j;
                map->exit_pos[1] = i;
            }
            j++;
        }
        i++;
    }
    close (fd);
    return (0);
}
