#include "so_long.h"

int move_player(t_game *game, int direction)
{
    int next_x;
    int next_y;

    next_x = game->player_x;
    next_y = game->player_y;
    if (direction == UP && game->map->grid[next_y][next_x] != '1' )
        next_y = game->player_y - 1;
    else if (direction == DOWN && game->map->grid[next_y][next_x] != '1' )
        next_y = game->player_y - 1;
    else if (direction == LEFT && game->map->grid[next_y][next_x] != '1' )
        next_x = game->player_x - 1;
    else if (direction == RIGHT && game->map->grid[next_y][next_x] != '1' )
        next_x = game->player_x + 1;
    if (game->map->grid[next_y][next_x] != 1)
    {
            game->player_y = next_y;
            game->player_x = next_x;
            game->moves++;
            return (1);
    }
    return (0);
}