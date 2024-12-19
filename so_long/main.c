#include "so_long.h"
#include "./minilibx/mlx.h"  // Chemin direct vers mlx.h


int main(int argc, char **argv)
{
    t_game  *game;
    Map     *map;
    
    // 1. Vérifier les arguments
    if (argc != 2)
    {
        ft_printf("Error\nUsage: ./so_long map.ber\n");
        return (1);
    }
    
    // 2. Vérifier l'extension
    if (!check_file_extension(argv[1]))
    {
        ft_printf("Error\nInvalid file extension\n");
        return (1);
    }
    
    // 3. Charger et vérifier la map
    map = load_map(argv[1]);
    if (!map || !check_walls(map) || !check_elements(map))
    {
        ft_printf("Error\nInvalid map\n");
        if (map)
            free_map(map);
        return (1);
    }
    
    // 4. Initialiser le jeu
    game = init_games(map);
    if (!game)
    {
        free_map(map);
        return (1);
    }
    
    // 5. Setup MLX et lancer le jeu
    if (!setup_game(game))
    {
        // Nettoyer et quitter
        free_map(map);
        free(game);
        return (1);
    }
    
    // 6. Lancer la boucle principale
    mlx_loop(game->mlx);
    
    return (0);
}