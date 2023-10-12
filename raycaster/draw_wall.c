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
	ray->line_h = (game->map.n_row * game->map.n_col) * SCALE / ray->dist_t;
	if (ray->line_h > 320)
		ray->line_h = 320;
	ray->line_o = 160 - ray->line_h / 2;
	while (y < ray->line_h + 200.00)
	{
		img_pix_put(&game->img, r, (int)(y + ray->line_o + 100), color);
		y++;
	}
}