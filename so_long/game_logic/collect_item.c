#include "so_long.h"

int collect_item(t_game *game)
{
    if (game->map->grid[game->player_y][game->player_x]== 'C')
    {
        game->map->grid[game->player_y][game->player_x]= '0';
        game->collected++;
        return (1);
    }
    return (0);
}