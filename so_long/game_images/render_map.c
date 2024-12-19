#include "so_long.h"

void render_map(t_game *game, t_images *imgs)
{
    int     x;
    int     y;
    
    y = 0;
    while(y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            mlx_put_image_to_window(game->mlx, game->window, imgs->floor, 
                x * imgs->size, y * imgs->size);
            if (game->map->grid[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->window, imgs->wall, 
                    x * imgs->size, y * imgs->size);
            if (game->map->grid[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->window, imgs->exit, 
                    x * imgs->size, y * imgs->size);
            if (game->map->grid[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, imgs->collect, 
                    x * imgs->size, y * imgs->size);
            if (game->map->grid[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->window, imgs->player, 
                    x * imgs->size, y * imgs->size);
            x++;
        }
        y++;
    }
}