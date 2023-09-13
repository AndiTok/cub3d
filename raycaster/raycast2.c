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
	// ray->px = player->x;
	// ray->py = player->y;
	ray->mx = 0;
	ray->my = 0;
	ray->ra = 0.0001;
	
	ray->rx = 0;
	ray->ry = 0;
	ray->ra = 0;
	ray->xo = 0;
	ray->yo = 0;
}

//round to 3 decimal points
double	ft_round(double val)
{
	return (round(val * 1000) / 1000);
}

void	ray_horiz(t_map *map, t_raycast *ray, float atan)
{
	if (ray->ra < PI) //looking down
	{
		ray->ry = (int)ray->py + TILESCALE;
		ray->rx = (ray->py - ray->ry) * atan + ray->px;
		ray->yo = TILESCALE;
		ray->xo = -1 * ray->yo * atan;
	}
	if (ray->ra > PI) //looking up
	{
		ray->ry = (int)ray->py - 0.0001;
		ray->rx = (ray->py - ray->ry) * atan + ray->px;
		ray->yo = -TILESCALE;
		ray->xo = -1 * ray->yo * atan;
	}
	if (ray->ra == 0 || ray->ra == PI * 2 || ray->ra == PI) //straight left/right
	{
		ray->rx = ray->px;
		ray->ry = ray->py;
		ray->dof = map->n_row; //map_column_size
	}
    while (ray->dof < map->n_row)
    {
        ray->mx = (int)ray->rx / TILESCALE;
        ray->my = (int)ray->ry / TILESCALE;
		if (ray->mx > map->n_col || ray->my > map->n_row )
        {
            // printf("H: ray_mx: %d\nray_my: %d\n", ray->mx, ray->my);
            return;
        }
		if (ray->rx < 0)
			ray->mx = 0;
        if (map->xymap[ray->my][ray->mx] == '1')// || (map->xymap[ray->mx][ray->my] == ' ')
        {
			if (ray->ra > PI)
				ray->ry = (((int)ray->ry / 16)*16) + TILESCALE;
				// ray->ry = (((int)ray->ry>>4)<<4) + TILESCALE;
			if (ray->ra < PI)
				ray->ry = (((int)ray->ry / 16)*16);
				// ray->ry = (((int)ray->ry>>4)<<4);
			break;
		}
        else
        {
            ray->rx += ray->xo;
            ray->ry += ray->yo;
            ray->dof++;
        }
	}
	printf("H: ray_rx: %f, ray_ry: %f\n", ray->rx, ray->ry);
	printf("H: ray_mx: %d, ray_my: %d\n", ray->mx, ray->my);
}

void	ray_vert(t_map *map, t_raycast *ray, float ntan)
{
	if (ray->ra > PI_HALF && ray->ra < PI3) //looking left
	{
		// ray->rx = (((int)ray->px / 16) * 16) - 0.0001; //A
		ray->rx = (int)ray->px - 0.0001; //B
		ray->ry = (ray->px - ray->rx) * ntan + ray->py;
		ray->xo = -TILESCALE;
		ray->yo = -1 * ray->xo * ntan;
	}
	if (ray->ra < PI_HALF || ray->ra > PI3) //looking right
	{
		// ray->rx = (((int)ray->px / 16) * 16) + TILESCALE; //A
		ray->rx = (int)ray->px + TILESCALE; //B
		ray->ry = (ray->px - ray->rx) * ntan + ray->py;
		ray->xo = TILESCALE;
		ray->yo = -1 * ray->xo * ntan;
	}
	if (ft_round(ray->ra) == ft_round(PI_HALF) || ft_round(ray->ra) == ft_round(PI3))
	{
		ray->rx = ray->px;
		ray->ry = ray->py;
		ray->dof = map->n_col;
	}
	printf("V: ray_rx: %f, ray_ry: %f, dof: %d\n", ray->rx, ray->ry, ray->dof);
	while (ray->dof < map->n_col)
	{
		ray->mx = (int)ray->rx / TILESCALE;
		ray->my = (int)ray->ry / TILESCALE;
		if (ray->mx > map->n_col || ray->my > map->n_row)
		{
			printf("exceeded\n");
			printf("V: ray_rx: %f, ray_ry: %f\n", ray->rx, ray->ry);
			printf("V: ray_mx: %d, ray_my: %d\n", ray->mx, ray->my);
			if (ray->my > map->n_row)
				ray->my = map->n_row - 1;
			if (ray->mx > map->n_col)
				ray->mx = map->n_col - 1;
			printf("adjust\nV: ray_mx: %d, ray_my: %d\n", ray->mx, ray->my);
			// return;
		}
		if (ray->rx < 0)
			ray->mx = 0;
		if (ray->ry < 0)
			ray->my = 0;
		// printf("V: ray_mx: %d, ray_my: %d, dof: %d\n", ray->mx, ray->my, ray->dof);
		if (map->xymap[ray->my][ray->mx] == '1')
		{
			if (ray->ra > PI_HALF && ray->ra < PI3) //left
				ray->rx = (((int)ray->rx / 16)*16) + TILESCALE;
			if ((ray->ra < PI_HALF && ray->ra > 0) || ray->ra > PI3) //right
				ray->rx = (((int)ray->rx / 16)*16);
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

void	raycast(t_game *game, t_raycast *ray)
{
	double	atan;
	double	ntan;
	int		r;

	r = 0;
	ray->px = game->player.x;
	ray->py = game->player.y;
	while (r < 1)
	{
		ray->dof = 0;
		atan = -1/tan(ray->ra);
		// ray_horiz(&game->map, ray, atan);
		// draw_line(game, game->ray.rx, game->ray.ry, 0x00FFFF); //blue
		ray->dof = 0;
		ntan = -tan(ray->ra);
			ray_vert(&game->map, ray, ntan);
			draw_line(game, game->ray.rx, game->ray.ry, 0x00FF00); //green
		r++;
	}
}