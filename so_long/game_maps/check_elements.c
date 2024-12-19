#include "so_long.h"

int check_elements(Map *map)
{
    int player_count;
    int exit_count;
    int collect_count;
    int i;
    int j;
    
    player_count = 0;
    exit_count = 0;
    collect_count = 0;
    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->grid[i][j] == 'P')
                player_count++;
            else if (map->grid[i][j] == 'E')
                exit_count++;
            else if (map->grid[i][j] == 'C')
                collect_count++;
            j++;
        }
        i++;
    }
    if (player_count != 1 || exit_count != 1 || collect_count < 1)
        return (0);
    return (1);
}