#include "so_long.h"

static void handle_movement(t_game *game)
{
    collect_item(game);
    if (check_win(game))
    {
        ft_printf("Well play, you win in %d movements", game->moves);
        exit(0);
    }
    render_map(game, &game->imgs);
}
int handle_keypress(int keycode, t_game *game)
{
            // w ou flech du haut
    if (keycode == 13 || keycode == 126)
    {
        if(move_player(game, UP))
            handle_movement(game);
    }
    if (keycode == 1 || keycode == 125)
    {
        if(move_player(game, DOWN))
            handle_movement(game);
    }
    if (keycode == 0 || keycode == 123)
    {
        if(move_player(game, LEFT))
            handle_movement(game);
    }
    if (keycode == 2 || keycode == 124)
    {
        if(move_player(game, RIGHT))
            handle_movement(game);
    }
    if ( keycode == 53) // esc
        exit (0);
    return (0);
}
