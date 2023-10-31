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

#include "../incl/cub3d.h"

/*draw wall with color, for demo
* y: vertical wall line pixel length
**/
void	draw_wall(t_game *game, t_raycast *ray, int r, int color)
{
	double	y;

	y = 0;
	ray->line_h = (4 * 1440) / (ray->dist_t);
	if (ray->line_h > 720)
		ray->line_h = 720;
	ray->line_o = 360 - ray->line_h / 2;
	while (y < ray->line_h)
	{
		img_pix_put(&game->img, r, (int)(y + ray->line_o), color);
		y++;
	}
}

/*get pixel color from texture*/
char	*get_pix(t_map *map, double ty, int tx, int t)
{
	char	*dst;

	if (t == 'N')
		dst = map->north.addr + ((int)ty * (map->north.line_len)
				+ tx * (map->north.bpp / 8));
	if (t == 'S')
		dst = map->south.addr + ((int)ty * (map->south.line_len)
				+ tx * (map->south.bpp / 8));
	if (t == 'E')
		dst = map->east.addr + ((int)ty * (map->east.line_len)
				+ tx * (map->east.bpp / 8));
	if (t == 'W')
		dst = map->west.addr + ((int)ty * (map->west.line_len)
				+ tx * (map->west.bpp / 8));
	return (dst);
}

double	get_tx(t_raycast *ray, int t)
{
	int	tx;

	if (t == 'N')
		tx = (int)ray->rx % 16;
	if (t == 'S')
		tx = 15 - (int)ray->rx % 16;
	if (t == 'W')
		tx = (int)ray->ry % 16;
	if (t == 'E')
		tx = 15 -(int)ray->ry % 16;
	return (tx);
}

void	draw_xpm(t_game *game, t_raycast *ray, int r, int t)
{
	double	steps;
	double	line_h_off;
	double	y;
	double	ty;
	int		pix;

	y = 0;
	line_h_off = 0;
	ray->line_h = (4 * 1440) / (ray->dist_t);
	steps = 16.0 / ray->line_h;
	if (ray->line_h > 720)
	{
		line_h_off = (ray->line_h - 720) / 2.0;
		ray->line_h = 720;
	}
	ty = line_h_off * steps;
	ray->line_o = 360 - ray->line_h / 2;
	while (y < ray->line_h)
	{
		pix = *(unsigned int *)get_pix(&game->map, ty, get_tx(ray, t), t);
		img_pix_put(&game->img, r, (int)(y + ray->line_o), pix);
		ty += steps;
		y++;
	}
}

// void	draw_xpm(t_game *game, t_raycast *ray, int r, int t)
// {
// 	char	*dst;
// 	double	y;
// 	double	ty;
// 	int		tx;
// 	int		pix;

// 	y = 0;
// 	ray->line_h = (4 * 1440) / (ray->dist_t);
// 	double steps = 16.0 / ray->line_h;
// 	double line_h_off = 0;
// 	if (ray->line_h > 720)
// 	{
// 		line_h_off = (ray->line_h - 720) / 2.0;
// 		ray->line_h = 720;
// 	}
// 	ty = line_h_off * steps;
// 	ray->line_o = 360 - ray->line_h / 2;

// 	if (t == 'N')
// 		tx = (int)ray->rx % 16;
// 	if (t == 'S')
// 		tx = 15 - (int)ray->rx % 16;
// 	if (t == 'W')
// 		tx = (int)ray->ry % 16;
// 	if (t == 'E')
// 		tx = 15 -(int)ray->ry % 16;
// 	while (y < ray->line_h)
// 	{
// 		dst = get_pix(&game->map, ty, tx, t);
// 		pix = *(unsigned int *)dst;
// 		img_pix_put(&game->img, r, (int)(y + ray->line_o), pix);
// 		ty += steps;
// 		y++;
// 	}
// }

/*misc notes
// ray->line_h = ((game->map.n_row * game->map.n_col) * 720)
//		/ (ray->dist_t * sqrt(game->map.n_row * game->map.n_col));
// ray->line_h = ((game->map.n_row * game->map.n_col) * 720)
//		/ (ray->dist_t * (sqrt(pow(game->map.n_row,2) + pow(game->map.n_col,2))));
// ray->dist_t * value
// bigger value = futhur render distance, wall wider
// smaller vlaue = closer distance, wall thiner
// value = longest side of map??
*/
// void	draw_texture(t_game *game, t_raycast *ray, int r)
// {
// 	char	*dst;
// 	double	y;
// 	double	ty;
// 	int		tx;
// 	int		pix;

// 	y = 0;
// 	ray->line_h = (4 * 1440) / (ray->dist_t);
// 	double steps = 16.0 / ray->line_h;
// 	double line_h_off = 0;
// 	if (ray->line_h > 720)
// 	{
// 		line_h_off = (ray->line_h-720)/2.0;
// 		ray->line_h = 720;
// 	}
// 	ty = line_h_off * steps;
// 	ray->line_o = 360 - ray->line_h/2;
// 	tx = (int)ray->rx % 16;
// 	while (y < ray->line_h)
// 	{
// 		// int i = -1;
// 		dst = game->map.north.addr + ((int)ty * (game->map.north.line_len)
				// + tx * (game->map.north.bpp / 8));
// 		pix = *(unsigned int*)dst;

// 			img_pix_put(&game->img, r, (int)(y + ray->line_o), pix);

// 		ty += steps;
// 		y++;
// 	}
// }