/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:23:07 by wyap              #+#    #+#             */
/*   Updated: 2023/09/11 16:23:07 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_init(t_raycast *ray, t_player *player)
{
	ray->p_angle = 0;
	get_start_pa(ray, player);
	ray->mx = 0;
	ray->my = 0;
	ray->rx = 0;
	ray->ry = 0;
	ray->xo = 0;
	ray->yo = 0;
	ray->dist_h = 1000000;
	ray->dist_v = 1000000;
	ray->dist_t = 0;

	ray->line_h = 0;
	ray->line_o = 0;
	ray->fish = 0;
}

double	ft_round(double val)
{
	return (round(val * 1000000) / 1000000);
}

void	limit_2dmap_index(t_map *map, t_raycast *ray)
{
	if (ray->mx >= map->n_col || ray->my >= map->n_row)//avoid beyond boundary
	{
		// printf("exceeded max mx/my\n");
		if (ray->my >= map->n_row)
			ray->my = map->n_row - 1;
		if (ray->mx >= map->n_col)
			ray->mx = map->n_col - 1;
	}
	if (ray->mx < 0|| ray->my < 0)
	{
		// printf("negative mx/my\n");
		if (ray->my < 0)
			ray->my = 0;
		if (ray->mx < 0)
			ray->mx = 0;
	}
}

void	ray_horiz(t_map *map, t_raycast *ray, float atan)
{
	if (ray->ra < M_PI) //looking down
	{
		ray->ry = (((int)ray->py / SCALE)*SCALE) + SCALE;
		ray->rx = (ray->py - ray->ry) * atan + ray->px;
		ray->yo = SCALE;
		ray->xo = -1 * ray->yo * atan;
	}
	if (ray->ra > M_PI) //looking up
	{
		ray->ry = (((int)ray->py / SCALE)*SCALE) - 0.0001;
		ray->rx = (ray->py - ray->ry) * atan + ray->px;
		ray->yo = -SCALE;
		ray->xo = -1 * ray->yo * atan;
	}
	if (ft_round(ray->ra) == ft_round(M_PI * 2) || ft_round(ray->ra) == ft_round(M_PI)) //straight left/right
	{
		if (ft_round(ray->ra) == ft_round(M_PI * 2))
			ray->rx = map->n_col * SCALE;
		else
			ray->rx = 0;
		ray->ry = ray->py;
		return ;
	}
    while (ray->dof < map->n_row)
    {
        ray->mx = (int)ray->rx / SCALE;
        ray->my = (int)ray->ry / SCALE;
		limit_2dmap_index(map, ray);
        if (map->xymap[ray->my][ray->mx] == '1' || map->xymap[ray->my][ray->mx] == ' ')
        {
			if (ray->ra > M_PI)
				ray->ry = (((int)ray->ry / SCALE)*SCALE) + SCALE;
			if (ray->ra < M_PI)
				ray->ry = (((int)ray->ry / SCALE)*SCALE);
			ray->hx = ray->rx;
			ray->hy = ray->ry;
			// ray->dist_h = fabs(cos(ray->ra) * (ray->hx - ray->px) - sin(ray->ra) * (ray->hy - ray->py));
			// ray->dist_h = fabs(sqrt((ray->hx - ray->px)*(ray->hx - ray->px) + (ray->hy - ray->py)*(ray->hy - ray->py)));
			ray->dist_h = sqrt((ray->hx - ray->px)*(ray->hx - ray->px) + (ray->hy - ray->py)*(ray->hy - ray->py));
		// printf("\tH: distH %f\n", ray->dist_h);
			ray->dof = map->n_row;
			// break;
		}
        else
        {
            ray->rx += ray->xo;
            ray->ry += ray->yo;
            ray->dof++;
        }
	}
	// printf("H: ray_rx: %f, ray_ry: %f\n", ray->rx, ray->ry);
	// printf("H: ray_mx: %d, ray_my: %d\n", ray->mx, ray->my);
}

void	ray_vert(t_map *map, t_raycast *ray, float ntan)
{
	if (ray->ra > M_PI_2 && ray->ra < PI3) //looking left
	{
		ray->rx = (((int)ray->px / SCALE)*SCALE) - 0.0001; //B
		ray->ry = (ray->px - ray->rx) * ntan + ray->py;
		ray->xo = -SCALE;
		ray->yo = -1 * ray->xo * ntan;
	}
	if (ray->ra < M_PI_2 || ray->ra > PI3) //looking right
	{
		ray->rx = (((int)ray->px / SCALE)*SCALE) + SCALE; //B
		ray->ry = (ray->px - ray->rx) * ntan + ray->py;
		ray->xo = SCALE;
		ray->yo = -1 * ray->xo * ntan;
	}
	if (ft_round(ray->ra) == ft_round(M_PI_2) || ft_round(ray->ra) == ft_round(PI3)) //straight up and down
	{
		ray->rx = ray->px;
		if (ft_round(ray->ra) == ft_round(M_PI_2))
			ray->ry = map->n_row * SCALE;
		else
			ray->ry = 0;
		return;
	}
	while (ray->dof < map->n_col)
	{
		ray->mx = (int)ray->rx / SCALE;
		ray->my = (int)ray->ry / SCALE;
		limit_2dmap_index(map, ray);
        if (map->xymap[ray->my][ray->mx] == '1' || map->xymap[ray->my][ray->mx] == ' ')
		{
			if (ray->ra > M_PI_2 && ray->ra < PI3) //left
				ray->rx = (((int)ray->rx / SCALE)*SCALE) + SCALE;
			if ((ray->ra < M_PI_2 && ray->ra > 0) || ray->ra > PI3) //right
				ray->rx = (((int)ray->rx / SCALE)*SCALE);
			ray->vx = ray->rx;
			ray->vy = ray->ry;
			// ray->dist_v = fabs(cos(ray->ra) * (ray->vx - ray->px) - sin(ray->ra) * (ray->vy - ray->py));
			// ray->dist_v = fabs(sqrt((ray->vx - ray->px)*(ray->vx - ray->px) + (ray->vy - ray->py)*(ray->vy - ray->py)));
			ray->dist_v = sqrt((ray->vx - ray->px)*(ray->vx - ray->px) + (ray->vy - ray->py)*(ray->vy - ray->py));
			// printf("\tV: distV %f\n", ray->dist_v );
			ray->dof = map->n_col;
			// break;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
	}	
    // printf("V: ray_mx: %d, ray_my: %d\n", ray->mx, ray->my);
}

double	angle_reset(double angle)
{
	if (angle < 0)
		angle += M_PI * 2;
	if (angle > M_PI * 2)
		angle -= M_PI * 2;
	return (angle);
}

void	raycast(t_game *game, t_raycast *ray)
{
	double	atan;
	double	ntan;
	int		r;

	r = 0;
	ray->ra = ray->p_angle - (30.0 * DEG); //multi-ray
	ray->ra = angle_reset(ray->ra);
	ray->px = game->player.x;
	ray->py = game->player.y;
	while (r < 60) // (r < 1)
	{
		ray->dof = 0;
		ray->hx = ray->px;
		ray->hy = ray->py;
		atan = -1/tan(ray->ra);
		ray_horiz(&game->map, ray, atan);
		// draw_line(game, game->ray.rx, game->ray.ry, 0xF7F731); //yellow
		ray->dof = 0;
		ray->vx = ray->px;
		ray->vy = ray->py;
		ntan = -tan(ray->ra);
		ray_vert(&game->map, ray, ntan);
		// draw_line(game, game->ray.rx, game->ray.ry, 0x00FF00); //green
		// printf("distH %f, distV %f\n", ray->dist_h, ray->dist_v );
		if (ray->dist_h > ray->dist_v)
		{
			// printf("vx %f, vy %f\n", ray->vx, ray->vy);
			ray->rx = ray->vx;
			ray->ry = ray->vy;
			ray->dist_t = ray->dist_v; //3d
		}
		if (ray->dist_h < ray->dist_v)
		{
			// printf("hx %f, hy %f\n", ray->hx, ray->hy);
			ray->rx = ray->hx;
			ray->ry = ray->hy;
			ray->dist_t = ray->dist_v; //3d
		}
		draw_line(game, ray->rx, ray->ry, 0x00FFFF); //blue

		//3D*********************************
		ray->fish = ray->p_angle - ray->ra;
		ray->fish = angle_reset(ray->fish);
		ray->dist_t *= cos(ray->fish);
		ray->line_h = (game->map.n_row * game->map.n_col) * 320 / ray->dist_t;
		if (ray->line_h > 320)
			ray->line_h = 320;
		ray->line_o = 160 - ray->line_h / 2;
		// draw_line(game, ray->line_o, ray->line_h + ray->line_o, 0x0FFF00); //3D line test *Wrong* (green)
		// printf("ray_rx: %f, ray_ry: %f\n", ray->rx, ray->ry);
		//***********************************
		ray->ra += DEG; //multi-ray
		ray->ra = angle_reset(ray->ra);
		// printf("r: %d\n", r);
		r++;
	}
}