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
	ray->px = player->x;
	ray->py = player->y;
	ray->mx = 0;
	ray->my = 0;
	// ray->mp = 0;
	ray->dof = 0;
	ray->ra = 0;
	
	ray->rx = 0;
	ray->ry = 0;
	ray->ra = 0;
	ray->xo = 0;
	ray->yo = 0;
}

void	ray_horiz(char **map, t_raycast *ray, float atan)
{
	if (ray->ra < PI) //looking up
	{
		ray->ry = ray->py + TILESCALE;
		ray->rx = (ray->py - ray->ry) * atan + ray->px;
		ray->yo = TILESCALE;
		ray->xo = ray->yo * atan;
	}
	if (ray->ra > PI) //looking down
	{
		ray->ry = ray->py - 0.0001;
		ray->rx = (ray->py - ray->ry) * atan + ray->px;
		ray->yo = -TILESCALE;
		ray->xo = ray->yo * atan;
	}
	if (ray->ra == 0 || ray->ra == PI) //straight left/right
	{
		ray->rx = ray->px;
		ray->ry = ray->px;
		ray->dof = 10; //map_column_size
	}
	while (ray->dof < 10)
	{
		ray->mx = ray->rx / TILESCALE;
		ray->my = ray->ry / TILESCALE;
		if (map[ray->mx][ray->my] == 1)
			ray->dof = 10;
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
	}
}

void	ray_vert(char **map, t_raycast *ray, float atan)
{
	if (ray->ra > PI_HALF && ray->ra < PI3) //looking left
	{
		ray->rx = ray->px - 0.0001;
		ray->ry = (ray->px - ray->rx) * atan + ray->py;
		ray->xo = -TILESCALE;
		ray->yo = ray->xo * atan;
	}
	if ((ray->ra < PI_HALF && ray->ra > 0) || ray->ra > PI3) //looking right
	{
		ray->rx = ray->px + TILESCALE;
		ray->ry = (ray->px - ray->rx) * atan + ray->py;
		ray->xo = TILESCALE;
		ray->yo = ray->xo * atan;
	}
	if (ray->ra == 0 || ray->ra == PI) //straight left/right
	{
		ray->rx = ray->px;
		ray->ry = ray->px;
		ray->dof = 10; //map_column_size
	}
	while (ray->dof < 10)
	{
		ray->mx = ray->rx / TILESCALE;
		ray->my = ray->ry / TILESCALE;
		if (map[ray->mx][ray->my] == 1)
			ray->dof = 10;
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
	while (r < 1)
	{
		atan = -1/tan(ray->ra);
		ray_horiz(game->map.xymap, ray, atan);
		//draw line
		ray->dof = 0;
		atan = -1/tan(ray->ra);
		ray_vert(game->map.xymap, ray, atan);
		//draw line		
		r++;
	}
}


// void raycast(t_game *game, t_raycast *ray)
// {
// 	float atan;
// 	int r;

// 	ray_init(ray, &game->player);
// 	// atan = 0;
// 	r = 0;
// 	while (r < 1)
// 	{
// 		atan = -1/tan(ray->ra);
// 		//check horizontal line
// 		if (ray->ra < PI) //looking up
// 		{
// 			ray->ry = ray->py + TILESCALE;
// 			ray->rx = (ray->py - ray->ry) * atan + ray->px;
// 			ray->yo = TILESCALE;
// 			ray->xo = ray->yo * atan;
// 		}
// 		if (ray->ra > PI) //looking down
// 		{
// 			ray->ry = ray->py - 0.0001;
// 			ray->rx = (ray->py - ray->ry) * atan + ray->px;
// 			ray->yo = -TILESCALE;
// 			ray->xo = ray->yo * atan;
// 		}
// 		if (ray->ra == 0 || ray->ra == PI) //straight left/right
// 		{
// 			ray->rx = ray->px;
// 			ray->ry = ray->px;
// 			ray->dof = 10; //map_column_size
// 		}
// 		while (ray->dof < 10)
// 		{
// 			ray->mx = ray->rx/TILESCALE;
// 			ray->my = ray->ry/TILESCALE;
// 			// mp = my * 10 + mx;
// 			// if (mp < 10 * 10 && //map[mp] == 1)
// 			// 	dof = 10;
// 			if (game->map.xymap[ray->mx][ray->my] == 1)
// 				ray->dof = 10;
// 			else
// 			{
// 				ray->rx += ray->xo;
// 				ray->ry += ray->yo;
// 				ray->dof++;
// 			}
// 		}
// 		//draw line
// 		ray->dof = 0;
// 		atan = -1/tan(ray->ra);
// 		//check vertical line
// 		if (ray->ra > PI_HALF && ray->ra < PI3) //looking left
// 		{
// 			ray->rx = ray->px - 0.0001;
// 			ray->ry = (ray->px - ray->rx) * atan + ray->py;
// 			ray->xo = -TILESCALE;
// 			ray->yo = ray->xo * atan;
// 		}
// 		if ((ray->ra < PI_HALF && ray->ra > 0) || ray->ra > PI3) //looking right
// 		{
// 			ray->rx = ray->px + TILESCALE;
// 			ray->ry = (ray->px - ray->rx) * atan + ray->py;
// 			ray->xo = TILESCALE;
// 			ray->yo = ray->xo * atan;
// 		}
// 		if (ray->ra == 0 || ray->ra == PI) //straight left/right
// 		{
// 			ray->rx = ray->px;
// 			ray->ry = ray->px;
// 			ray->dof = 10; //map_column_size
// 		}
// 		while (ray->dof < 10)
// 		{
// 			ray->mx = ray->rx/TILESCALE;
// 			ray->my = ray->ry/TILESCALE;
// 			// mp = my * 10 + mx;
// 			// if (mp < 10 * 10 && //map[mp] == 1)
// 			// 	dof = 10;
// 			if (game->map.xymap[ray->mx][ray->my] == 1)
// 				ray->dof = 10;
// 			else
// 			{
// 				ray->rx += ray->xo;
// 				ray->ry += ray->yo;
// 				ray->dof++;
// 			}
// 		}
// 		//draw line		
// 		r++;
// 	}
// }