#include "so_long.h"

int check_walls(Map *map)
{
         int i;

    // Vérifier première et dernière ligne
        i = 0;
        while (i < map->width)
        {
            if (map->grid[0][i] != '1' || 
                map->grid[map->height - 1][i] != '1')
                return (0);
            i++;
        }
    // Vérifier première et dernière colonne
        i = 0;
        while (i < map->height)
        {
            if (map->grid[i][0] != '1' || 
                map->grid[i][map->width - 1] != '1')
                return (0);
            i++;
        }
        return (1);
}