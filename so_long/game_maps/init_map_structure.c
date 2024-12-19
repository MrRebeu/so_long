#include "so_long.h"

Map *init_map_structure(int height, int width)
{
    Map     *map;
    
    map = malloc(sizeof(Map));
    if (!map)
        return (NULL);
    map->grid = malloc(sizeof(char*) * (height * width));
    if (!map->grid)
    {
        free(map);
        return (NULL);
    }
    map->height = height;
    map->width = width;
    map->collectible_count = 0;
    map->start_pos[0] = -1;
    map->start_pos[1] = -1;
    map->exit_pos[0] = -1;
    map->exit_pos[1] = -1;
    return(map);
}