void handle_movement(t_game *game)
{
    collect_item(game);
    if (check_win(game))
    {
        ft_printf("Well play, you win in %d movements", game->moves);
        exit(0);
    }
    render_map(game, &game->imgs);
}