#include "so_long.h"

void free_map(Map *map)
{
    int i;
    
    if (!map)
        return;
        
    if (map->grid)
    {
        i = 0;
        while (i < map->height)
        {
            if (map->grid[i])
                free(map->grid[i]);
            i++;
        }
        free(map->grid);
    }
    free(map);
}