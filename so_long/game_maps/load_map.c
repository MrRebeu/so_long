#include "so_long.h"

Map *load_map(char *filename)
{
    int fd;
    char *line;
    int width;
    Map *map;
    int height;
    
    height = count_map_lines(filename);
    if (height <= 0 || !check_line_lengths(filename, &width))
        return (NULL);
        
    map = init_map_structure(height, width);
    if (!map)
        return (NULL);
        
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        free_map(map);
        return (NULL);
    }
    
    // Remplir la map
    int i = 0;
    while ((line = get_next_line(fd)))
        map->grid[i++] = line;
    
    close(fd);
    return (map);
}