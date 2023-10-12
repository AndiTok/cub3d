#include "../cub3d.h"

void	draw_wall(t_game *game, t_raycast *ray, int r, int color)
{
    (void) color;
	// //will overlap minimap
	// ray->line_h = (game->map.n_row * game->map.n_col) * 1280 / ray->dist_t;
	// if (ray->line_h > 1280)
	// 	ray->line_h = 1280;
	// ray->line_o = 640 - ray->line_h / 2;
	// for (double y = 0; y < ray->line_h; y++)
	// 	for (double x = 0; x < 21; x++)
	// 		// mlx_pixel_put(game->mlx, game->win, r * 21 + x, (int)(y), 0x0FFF00);
	// 		mlx_pixel_put(game->mlx, game->win, r * 21 + x, (int)(y + ray->line_o), 0x0FFF00);
	// printf("ray_rx: %f, ray_ry: %f\n", ray->rx, ray->ry);

	//~~~~****test code that see minimap****~~~~
	ray->line_h = (game->map.n_row * game->map.n_col) * SCALE / ray->dist_t;
	if (ray->line_h > 320)
		ray->line_h = 320;
	ray->line_o = 160 - ray->line_h / 2;
		// y: vertical wall line pixel length; x: vertical wall line thickness
		// start x: mlx_pixel_put 3rd param 
	// for (double y = 0; y < ray->line_h + 400.00; y++)
	for (double y = 0; y < ray->line_h + 350.00; y++)
		for (double x = 0; x < 15; x++)
			// mlx_pixel_put(game->mlx, game->win, r * 21 + x, (int)(y), 0x0FFF00);
			img_pix_put(&game->img, r * 16 + x + 300, (int)(y + ray->line_o), 0x0FFF00);
			// mlx_pixel_put(game->mlx, game->win, r * 16 + x + 300, (int)(y + ray->line_o), 0x0FFF00);
	//~~~~********************************~~~~

}