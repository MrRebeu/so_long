#include "so_long.h"

int setup_game(t_game *game)
{
    // Initialiser la MLX
    game->mlx = mlx_init();
    if (!game->mlx)
        return (0);
    
    // Créer la fenêtre (taille = nombre de cases * taille d'une case)
    game->window = mlx_new_window(game->mlx, 
                                 game->map->width * 42,
                                 game->map->height * 42,
                                 "so_long");
    if (!game->window)
        return (0);

    // Charger les images
    if (!init_images(game, &game->imgs))
        return (0);
        
    // Configurer la gestion des touches
    mlx_hook(game->window, 2, 1L<<0, handle_keypress, game);
    
    // Afficher la map initiale
    render_map(game, &game->imgs);
    
    return (1);
}