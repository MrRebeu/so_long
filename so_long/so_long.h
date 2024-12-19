#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct {
    int     width;
    int     height;
    char    **grid;
    int     start_pos[2];
    int     exit_pos[2];
    int     collectible_count;
} Map;

typedef struct {
    void    *wall;      // Image du mur
    void    *floor;     // Image du sol
    void    *player;    // Image du joueur
    void    *collect;   // Image du collectible
    void    *exit;      // Image de la sortie
    int     size;       // Taille des images (42 pixels)
} t_images;

typedef struct s_game {
    Map     *map;           // Notre map existante
    int     player_x;       // Position X actuelle du joueur
    int     player_y;       // Position Y actuelle du joueur
    int     moves;          // Nombre de mouvements
    int     collected;      // Nombre d'items collectés
    void    *mlx;           // Pour plus tard avec la MLX
    void    *window;        // Pour plus tard avec la MLX
} t_game;

# define UP      1
# define DOWN    2
# define LEFT    3
# define RIGHT   4

int setup_game(t_game *game);
int init_images(t_game *game, t_images *imgs);
void render_map(t_game *game, t_images *imgs);
int check_elements(Map *map);
int check_file_extension(char *filename);
int check_line_lengths(char *filename, int *width);
int check_walls(Map *map);
int count_map_lines(char *filename);
int fill_map_data(Map *map, char *filename);
Map *init_map_structure(int height, int width);
Map *load_map(char *filename);
void free_map(Map *map);
int move_player(t_game *game, int direction);
t_game *init_games(Map *map);
int handle_keypress(int keycode, t_game *game);
int collect_item(t_game *game);
int check_win(t_game *game);

#endif