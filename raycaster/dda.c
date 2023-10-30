/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:23:07 by wyap              #+#    #+#             */
/*   Updated: 2023/09/11 16:23:07 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_dist_h(t_map *map, t_raycast *ray)
{
	while (ray->dof < map->n_row)
	{
		ray->mx = (int)ray->rx / SCALE;
		ray->my = (int)ray->ry / SCALE;
		limit_2dmap_index(map, ray);
		if (map->xymap[ray->my][ray->mx] == '1'
			|| map->xymap[ray->my][ray->mx] == ' ')
		{
			ray->hx = ray->rx;
			ray->hy = ray->ry;
			ray->dist_h = sqrt((ray->hx - ray->px) * (ray->hx - ray->px)
					+ (ray->hy - ray->py) * (ray->hy - ray->py));
			ray->dof = map->n_row;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
	}
}
// printf("H: ray_rx: %f, ray_ry: %f\n", ray->rx, ray->ry);
// printf("H: ray_mx: %d, ray_my: %d\n", ray->mx, ray->my);

/*
* DDA Algorithm, stops stepping at horizontal wall
*
* if (ray->ra < M_PI) //looking down
* if (ray->ra > M_PI) //looking up
* if (ft_round(ray->ra) == ft_round(M_PI * 2)
*	|| ft_round(ray->ra) == ft_round(M_PI)) //straight left/right
*/
void	ray_horiz(t_map *map, t_raycast *ray, float atan)
{
	if (ray->ra < M_PI)
	{
		ray->ry = (((int)ray->py / SCALE) * SCALE) + SCALE;
		ray->rx = (ray->py - ray->ry) * atan + ray->px;
		ray->yo = SCALE;
		ray->xo = -1 * ray->yo * atan;
	}
	if (ray->ra > M_PI)
	{
		ray->ry = (((int)ray->py / SCALE) * SCALE) - 0.0000001;
		ray->rx = (ray->py - ray->ry) * atan + ray->px;
		ray->yo = -SCALE;
		ray->xo = -1 * ray->yo * atan;
	}
	if (ft_round(ray->ra) == ft_round(M_PI * 2)
		|| ft_round(ray->ra) == ft_round(M_PI))
	{
		if (ft_round(ray->ra) == ft_round(M_PI * 2))
			ray->rx = map->n_col * SCALE;
		else
			ray->rx = 0;
		ray->ry = ray->py;
		return ;
	}
	get_dist_h(map, ray);
}

void	get_dist_v(t_map *map, t_raycast *ray)
{
	while (ray->dof < map->n_col)
	{
		ray->mx = (int)ray->rx / SCALE;
		ray->my = (int)ray->ry / SCALE;
		limit_2dmap_index(map, ray);
		if (map->xymap[ray->my][ray->mx] == '1'
			|| map->xymap[ray->my][ray->mx] == ' ')
		{
			ray->vx = ray->rx;
			ray->vy = ray->ry;
			ray->dist_v = sqrt((ray->vx - ray->px) * (ray->vx - ray->px)
					+ (ray->vy - ray->py) * (ray->vy - ray->py));
			ray->dof = map->n_col;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
	}	
}
// printf("V: ray_mx: %d, ray_my: %d\n", ray->mx, ray->my);

/*
* DDA Algorithm, stops stepping at vertical wall
*
*	if (ray->ra > M_PI_2 && ray->ra < PI3) //looking left
*	if (ray->ra < M_PI_2 || ray->ra > PI3) //looking right
*	if (ft_round(ray->ra) == ft_round(M_PI_2)
*		|| ft_round(ray->ra) == ft_round(PI3)) //straight up and down
*/
void	ray_vert(t_map *map, t_raycast *ray, float ntan)
{
	if (ray->ra > M_PI_2 && ray->ra < PI3)
	{
		ray->rx = (((int)ray->px / SCALE) * SCALE) - 0.0000001;
		ray->ry = (ray->px - ray->rx) * ntan + ray->py;
		ray->xo = -SCALE;
		ray->yo = -1 * ray->xo * ntan;
	}
	if (ray->ra < M_PI_2 || ray->ra > PI3)
	{
		ray->rx = (((int)ray->px / SCALE) * SCALE) + SCALE;
		ray->ry = (ray->px - ray->rx) * ntan + ray->py;
		ray->xo = SCALE;
		ray->yo = -1 * ray->xo * ntan;
	}
	if (ft_round(ray->ra) == ft_round(M_PI_2)
		|| ft_round(ray->ra) == ft_round(PI3))
	{
		ray->rx = ray->px;
		if (ft_round(ray->ra) == ft_round(M_PI_2))
			ray->ry = map->n_row * SCALE;
		else
			ray->ry = 0;
		return ;
	}
	get_dist_v(map, ray);
}

/*perform DDA: vertical and horizontal DDA*/
void	dda(t_map *map, t_raycast *ray)
{
	double	atan;
	double	ntan;

	ray->dof = 0;
	ray->hx = ray->px;
	ray->hy = ray->py;
	atan = -1 / tan(ray->ra);
	ray_horiz(map, ray, atan);
	ray->dof = 0;
	ray->vx = ray->px;
	ray->vy = ray->py;
	ntan = -tan(ray->ra);
	ray_vert(map, ray, ntan);
}

// /* raycast demo, to see wall color, comment out dda() when demo*/
// void	raycast(t_game *game, t_raycast *ray)
// {
// 	double	atan;
// 	double	ntan;
// 	int		r;
// 	int		t;

// 	r = 0;
// 	ray->ra = ray->p_angle - (30.0 * DEG);
// 	ray->ra = angle_reset(ray->ra);
// 	ray->px = game->player.x;
// 	ray->py = game->player.y;

// 	while (r < 1260)
// 	{
// 		ray->dof = 0;
// 		ray->hx = ray->px;
// 		ray->hy = ray->py;
// 		atan = -1/tan(ray->ra);
// 		ray_horiz(&game->map, ray, atan);
// 		// draw_line(game, game->ray.rx, game->ray.ry, YELLOW);
// 		ray->dof = 0;
// 		ray->vx = ray->px;
// 		ray->vy = ray->py;
// 		ntan = -tan(ray->ra);
// 		ray_vert(&game->map, ray, ntan);
// 		// draw_line(game, game->ray.rx, game->ray.ry, GREEN);
// 		// printf("distH %f, distV %f\n", ray->dist_h, ray->dist_v );
// 		if (ray->dist_h > ray->dist_v)
// 		{
// 			ray->rx = ray->vx;
// 			ray->ry = ray->vy;
// 			ray->dist_t = ray->dist_v; //3d
// 			if (ray->ra > M_PI_2 && ray->ra < PI3) // look left mm E wall
// 			{
// 				t = 'E';
// 				draw_wall(game, ray, r, RED);
// 			}
// 			if (ray->ra < M_PI_2 || ray->ra > PI3)  // look right mm W wall
// 			{
// 				t = 'W';
// 				draw_wall(game, ray, r, YELLOW);
// 			}
// 		}
// 		if (ray->dist_h < ray->dist_v)
// 		{
// 			ray->rx = ray->hx;
// 			ray->ry = ray->hy;
// 			ray->dist_t = ray->dist_h; //3d
// 			if (ray->ra > M_PI) // look up mm N wall
// 			{
// 				t = 'N';
// 				draw_wall(game, ray, r, GREEN);
// 			}
// 			if (ray->ra < M_PI) // look down mm S wall
// 			{
// 				t = 'S';
// 				draw_wall(game, ray, r, BLUE);
// 			}
// 		}
// 		// draw_line(game, ray->rx, ray->ry, 0x00FFFF); //light blue
// 		fix_fisheye(ray);
// 			// draw_wall(game, ray, r, color);
// 			// draw_texture(game, ray, r, color);
// 			draw_xpm(game, ray, r, t);
// 		ray->ra += (DEG / 21);
// 		ray->ra = angle_reset(ray->ra);
// 		r++;
// 	}
// }