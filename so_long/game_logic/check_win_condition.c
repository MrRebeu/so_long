#include "so_long.h"

int check_win(t_game *game)
{
    if (game->map->grid[game->player_y][game->player_x] == 'E')
    {
        if (game->collected == game->collectible_count)
            return (1);
    }
    return (0);
}