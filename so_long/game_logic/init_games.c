#include "so_long.h"

t_game *init_game(Map *map)
{
    t_game *game;

    game = malloc(sizeof(t_game));
    if (!game)
        return (NULL);
    game->map = map;
    game->player_x = map->start_pos[0];
    game->player_y = map->exit_pos[1];
    game->collected = 0;
    game->moves = 0;
    game->mlx = NULL;
    game->window = NULL;
    return (game);
}