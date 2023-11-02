/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:40:31 by wyap              #+#    #+#             */
/*   Updated: 2023/10/30 12:40:31 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	take_dist_h(t_map *map, t_raycast *ray, int texture)
{
	ray->rx = ray->hx;
	ray->ry = ray->hy;
	ray->dist_t = ray->dist_h;
	if (ray->ra > M_PI)
	{
		if (map->xymap[(int)ray->ry / SCALE][(int)ray->rx / SCALE] == '1')
			texture = 'N';
		if (map->xymap[(int)ray->ry / SCALE][(int)ray->rx / SCALE] == '2')
			texture = 'n';
	}
	if (ray->ra < M_PI)
	{
		if (map->xymap[(int)ray->ry / SCALE][(int)ray->rx / SCALE] == '1')
			texture = 'S';
		if (map->xymap[(int)ray->ry / SCALE][(int)ray->rx / SCALE] == '2')
			texture = 's';
	}
	return (texture);
}

/*
* get correct wall distance and set texture to draw
*
*   PI3 = 3*M_PI/2 or 3*M_PI_2 (couldnt define on .h due to 42 norm)
*	if (ray->ra > M_PI_2 && ray->ra < PI3): look left mm E wall
*	if (ray->ra < M_PI_2 || ray->ra > PI3): look right mm W wall
*	if (ray->ra > M_PI): look up mm N wall
*	if (ray->ra < M_PI): look down mm S wall
*/
int	set_dist_t_texture(t_map *map, t_raycast *ray)
{
	int	texture;

	if (ray->dist_h > ray->dist_v)
	{
		ray->rx = ray->vx;
		ray->ry = ray->vy;
		ray->dist_t = ray->dist_v;
		if (ray->ra > M_PI_2 && ray->ra < M_PI_2 * 3)
		{
			if (map->xymap[(int)ray->ry / SCALE][(int)ray->rx / SCALE] == '1')
				texture = 'E';
			if (map->xymap[(int)ray->ry / SCALE][(int)ray->rx / SCALE] == '2')
				texture = 'e';
		}
		if (ray->ra < M_PI_2 || ray->ra > M_PI_2 * 3)
		{
			if (map->xymap[(int)ray->ry / SCALE][(int)ray->rx / SCALE] == '1')
				texture = 'W';
			if (map->xymap[(int)ray->ry / SCALE][(int)ray->rx / SCALE] == '2')
				texture = 'w';
		}
	}
	if (ray->dist_h < ray->dist_v)
		texture = take_dist_h(map, ray, texture);
	return (texture);
}
// {
	// ray->rx = ray->hx;
	// ray->ry = ray->hy;
	// ray->dist_t = ray->dist_h;
	// if (ray->ra > M_PI)
	// {
	// 	if (map->xymap[(int)ray->ry / SCALE][(int)ray->rx / SCALE] == '1')
	// 		texture = 'N';
	// 	if (map->xymap[(int)ray->ry / SCALE][(int)ray->rx / SCALE] == '2')
	// 		texture = 'n';
	// }
	// if (ray->ra < M_PI)
	// {
	// 	if (map->xymap[(int)ray->ry / SCALE][(int)ray->rx / SCALE] == '1')
	// 		texture = 'S';
	// 	if (map->xymap[(int)ray->ry / SCALE][(int)ray->rx / SCALE] == '2')
	// 		texture = 's';
	// }
// }

/*prevent mx my exceeding map boundary (pointing to NULL)*/
void	limit_2dmap_index(t_map *map, t_raycast *ray)
{
	if (ray->mx >= map->n_col || ray->my >= map->n_row)
	{
		if (ray->my >= map->n_row)
			ray->my = map->n_row - 1;
		if (ray->mx >= map->n_col)
			ray->mx = map->n_col - 1;
	}
	if (ray->mx < 0 || ray->my < 0)
	{
		if (ray->my < 0)
			ray->my = 0;
		if (ray->mx < 0)
			ray->mx = 0;
	}
}

double	ft_round(double val)
{
	return (round(val * 1000000) / 1000000);
}

double	angle_reset(double angle)
{
	if (angle < 0)
		angle += M_PI * 2;
	if (angle > M_PI * 2)
		angle -= M_PI * 2;
	return (angle);
}
