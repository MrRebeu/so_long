#include "so_long.h"

int init_images(t_game *game, t_images *imgs)
{
    int img_width;
    int img_height;

    imgs->size = 42; // en piexl
    //chrg img wall(ft mlx deja implenter)-instance mlx, chemin du file  , ou stck lageur, et la hauteur
    imgs->wall = mlx_xpm_file_to_image(game->mlx,"./sprites/wall.xpm",&img_width, &img_height);
    if (!imgs->wall)
        return (0);
    imgs->floor = mlx_xpm_file_to_image(game->mlx,"./sprites/floor.xpm",&img_width, &img_height);
    if (!imgs->floor)
        return (0);
    imgs->player = mlx_xpm_file_to_image(game->mlx, "./sprites/floor.xpm", &img_width, &img_height);
    if (!imgs->player)
        return(0);
    imgs->collect = mlx_xpm_file_to_image(game->mlx, "./sprites/player.xpm", &img_width, &img_height);
    if (!imgs->collect)
        return (0);
    if (!imgs->exit)
        return (0);
    return(1); // all ok
}