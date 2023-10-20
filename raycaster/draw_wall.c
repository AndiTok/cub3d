/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:43:45 by wyap              #+#    #+#             */
/*   Updated: 2023/10/12 15:43:45 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	textured_wall(t_game *game, t_raycast *ray, t_map *map, int r)
// {
// 	t_img	wall_t;
// 	// if (condition)
// 	//  wall_t = map->(texture)


// }

void	draw_wall(t_game *game, t_raycast *ray, int r, int color)
{
	double y;
		// y: vertical wall line pixel length;
	y = 0;
	ray->line_h = (4 * 1440) / (ray->dist_t);
	// ray->line_h = ((game->map.n_row * game->map.n_col) * 720) / (ray->dist_t * sqrt(game->map.n_row * game->map.n_col));
	// ray->line_h = ((game->map.n_row * game->map.n_col) * 720) / (ray->dist_t * (sqrt(pow(game->map.n_row,2) + pow(game->map.n_col,2))));
	// ray->dist_t * value
	// bigger value = futhur render distance, wall wider
	// smaller vlaue = closer distance, wall thiner
	// value = longest side of map??
	if (ray->line_h > 720)
		ray->line_h = 720;
	ray->line_o = 360 - ray->line_h/2;
	while (y < ray->line_h)
	{
		img_pix_put(&game->img, r, (int)(y + ray->line_o), color);
		y++;
	}
}

// void	draw_wall(t_game *game, t_raycast *ray, int r, int color)
// {
// 	double y;
// 		// y: vertical wall line pixel length;
// 	y = 0;
// 	ray->line_h = ((game->map.n_row * game->map.n_col) * 320) / (ray->dist_t * 16);
// 	// printf("%f\n",ray->dist_t);
// 	if (ray->line_h > 320)
// 		ray->line_h = 320;
// 	ray->line_o = 160 - ray->line_h/2;
// 	while (y < ray->line_h)
// 	{
// 		img_pix_put(&game->img, r + 530, (int)(y + ray->line_o)+200, color);
// 		y++;
// 	}
// }

void	draw_texture(t_game *game, t_raycast *ray, int r, int color)
{
	char *dst;
	double y;
		// y: vertical wall line pixel length;
	double ty;
	int tx;
	int pix;
	(void) color;

	y = 0;
	ray->line_h = (4 * 1440) / (ray->dist_t);
	// ray->line_h = ((game->map.n_row * game->map.n_col) * 720) / (ray->dist_t * sqrt(game->map.n_row * game->map.n_col));
	// ray->line_h = ((game->map.n_row * game->map.n_col) * 720) / (ray->dist_t * (sqrt(pow(game->map.n_row,2) + pow(game->map.n_col,2))));
	// ray->dist_t * value
	// bigger value = futhur render distance, wall wider
	// smaller vlaue = closer distance, wall thiner
	// value = longest side of map??
	double steps = 16.0 / ray->line_h;
	double line_h_off = 0;
	if (ray->line_h > 720)
	{
		line_h_off = (ray->line_h-720)/2.0;
		ray->line_h = 720;
	}
	ty = line_h_off * steps;
	ray->line_o = 360 - ray->line_h/2;
	tx = (int)ray->rx % 16;
	while (y < ray->line_h)
	{
		// int i = -1;
		dst = game->map.north.addr + ((int)ty * (game->map.north.line_len) + tx * (game->map.north.bpp / 8));
		pix = *(unsigned int*)dst;

			img_pix_put(&game->img, r, (int)(y + ray->line_o), pix);

		ty += steps;
		y++;
	}
}