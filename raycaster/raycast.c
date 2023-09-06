/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:29:52 by wyap              #+#    #+#             */
/*   Updated: 2023/09/06 15:53:40 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	ray_init(t_raycast ray, t_player player)
{
	ray.px = player.x;
	ray.py = player.y;
	ray.dir_x = -1;
	ray.dir_y = 0;
	ray.plane_x = 0;
	ray.plane_y = 0.66;
	ray.cam_x = 0;
	ray.ray_dir_x = 0;
	ray.ray_dir_y = 0;
	ray.delta_x = 0;
	ray.delta_y = 0;
	ray.side_x = 0;
	ray.side_y = 0;
	ray.step_x = 0;
	ray.step_y = 0;
}

//set next x and y points
void	set_delta(t_raycast ray)
{
	if (ray.ray_dir_x != 0 && ray.ray_dir_y != 0)
	{
		ray.delta_x = abs(1 / ray.ray_dir_x);
		ray.delta_y = abs(1 / ray.ray_dir_y);
		return ;
	}
	printf("ray direction is 0\nrayDirX: %lf\nrayDirY: %lf\n", ray.ray_dir_x, ray.ray_dir_y);
}

//calculate ray movement in 2D array, 
void	calc_step(t_raycast ray)
{
	if (ray.ray_dir_x < 0)
	{
		ray.step_x = -1;
		ray.side_x = (ray.px - ray.map_x) * ray.delta_x;
	}
	else
	{
		ray.step_x = 1;
		ray.side_x = (ray.map_x + 1.0 - ray.px) * ray.delta_x;		
	}
	if (ray.ray_dir_y < 0)
	{
		ray.step_y = -1;
		ray.side_y = (ray.py - ray.map_y) * ray.delta_y;
	}
	else
	{
		ray.step_y = 1;
		ray.side_y = (ray.map_y + 1.0 - ray.py) * ray.delta_y;		
	}
}
//DDA Algorithm: Digital Differential Analyzer
//generates a line segment from start to the next grid intersection
void	dda(t_map map, t_raycast ray)
{
	int	wall_hit;
	wall_hit = 0;

	calc_step(ray);
	while (wall_hit == 0)
	{
		if (ray.side_x < ray.side_y)
		{
			ray.side_x += ray.delta_x;
			ray.map_x += ray.step_x;
			ray.side = 0;
		}
		else //(ray.side_x > ray.side_y)
		{
			ray.side_y += ray.delta_y;
			ray.map_y += ray.step_y;
			ray.side = 1;	
		}
		//check if ray hits a wall
		if (map.xymap[ray.map_x][ray.map_y] == '1')
			wall_hit = 1;
	}
}
//calculate how high the wall is drawn, use distance from wall to camera plane
void	calc_wall_dist(t_raycast ray)
{
	if (ray.side == 0)
		ray.wall_dist = ray.side_x - ray.delta_x;
	else
		ray.wall_dist = ray.side_y - ray.delta_y;
	
	int h = 50; //test length, not fixed yet
	int line_h = (int)(h / ray.wall_dist);

	int draw_start = (line_h / 2) + (h / 2) * -1;
	if (draw_start < 0)
		draw_start = 0;
	int draw_end = (line_h / 2) + (h / 2);
	if (draw_end >= h)
		draw_end = h - 1;
}

int	raycast(t_map map, t_player player){
	t_raycast ray;
	ray_init(ray, player);

	int x;
	x = 0;
	int w = 1280; //win width
	while (x < w)
	{
		ray.cam_x = 2 * x / (double)w - 1;
		ray.ray_dir_x = ray.dir_x + ray.plane_x * ray.cam_x;
		ray.ray_dir_y = ray.dir_y + ray.plane_y * ray.cam_x;

		ray.map_x = (int)ray.px;
		ray.map_y = (int)ray.py;

		set_delta(ray);
		dda(map, ray);
		calc_wall_dist(ray);
		x++;
	}
}
