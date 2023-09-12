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
	// ray->mp = 0;
	// ray->dof = 0;
	ray->ra = 0.0001;
	
	ray->rx = 0;
	ray->ry = 0;
	ray->ra = 0;
	ray->xo = 0;
	ray->yo = 0;
}

void	ray_horiz(t_map *map, t_raycast *ray, float atan)
{
	if (ray->ra < PI) //looking down
	{
		ray->ry = (int)ray->py + TILESCALE;
		ray->rx = (ray->py - ray->ry) * atan + ray->px;
		ray->yo = TILESCALE;
		// ray->yo = map->n_col * map->n_row;
		ray->xo = -1 * ray->yo * atan;
	}
	if (ray->ra > PI) //looking up
	{
		ray->ry = (int)ray->py - 0.0001;
		ray->rx = (ray->py - ray->ry) * atan + ray->px;
		ray->yo = -TILESCALE;
		// ray->yo = -1 * map->n_col * map->n_row;
		ray->xo = -1 * ray->yo * atan;
	}
	if (ray->ra == 0 || ray->ra == PI * 2 || ray->ra == PI) //straight left/right
	{
		ray->rx = ray->px;
		ray->ry = ray->py;
		ray->dof = map->n_col; //map_column_size
	}
    while (ray->dof < map->n_col)
    {
        ray->mx = (int)ray->rx / TILESCALE;
        ray->my = (int)ray->ry / TILESCALE;
        // printf("H: ray_rx: %f, ray_ry: %f\n", ray->rx, ray->ry);
        // printf("H: ray_mx: %d, ray_my: %d\n", ray->mx, ray->my);
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
}

void	ray_vert(t_map *map, t_raycast *ray, float atan)
{
	if (ray->ra > PI_HALF && ray->ra < PI3) //looking left
	{
		ray->rx = ray->px - 0.0001;
		ray->ry = (ray->px - ray->rx) * atan + ray->py;
		ray->xo = TILESCALE;
		ray->yo = ray->xo * atan * -1;
	}
	if ((ray->ra < PI_HALF && ray->ra > 0) || ray->ra > PI3) //looking right
	{
		ray->rx = ray->px + TILESCALE;
		ray->ry = (ray->px - ray->rx) * atan + ray->py;
		ray->xo = -1 * TILESCALE;
		ray->yo = ray->xo * atan * -1;
	}
	if (ray->ra == PI3 || ray->ra == PI_HALF) //straight left/right
	{
		ray->rx = ray->px;
		ray->ry = ray->py;
		ray->dof = map->n_row; //map_column_size
	}
	while (ray->dof < map->n_row)
	{
		ray->mx = ray->rx / TILESCALE;
		ray->my = ray->ry / TILESCALE;
		// ray->mx = 10;
		// ray->my = 10;
		if (ray->mx > map->n_col || ray->my > map->n_row)
		{
			printf("V: ray_mx: %d\nray_my: %d\n", ray->mx, ray->my);
			return;
		}
		if (map->xymap[ray->mx][ray->my] == '1')
			ray->dof = map->n_row;
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
	}	
}

void raycast(t_game *game, t_raycast *ray)
{
	float atan;
	int r;

	r = 0;
	ray->px = game->player.x;
	ray->py = game->player.y;
	while (r < 1)
	{
		atan = -1/tan(ray->ra);
		ray_horiz(&game->map, ray, atan);
		//draw line
		draw_line(game, game->ray.rx, game->ray.ry, 0x00FFFF);
		ray->dof = 0;
		atan = -1/tan(ray->ra);
			// ray_vert(&game->map, ray, atan);
		// draw_line(game, game->ray.rx, game->ray.ry, 0x00FF00);
		//draw line		
		r++;
	}
}