/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 02:36:36 by wyap              #+#    #+#             */
/*   Updated: 2023/09/07 02:36:36 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
* handle player rotation, player vector calc from player angle
* must not calc from ray->ra because will affect multi-ray casting
*/
void	rotation(int keycode, t_game game, t_raycast *ray)
{
	(void) game;
	if (keycode == LEFT)
	{
		ray->p_angle -= DEG * 5;
		if (ray->p_angle < 0)
			ray->p_angle += M_PI * 2;
		ray->dir_x = cos(ray->p_angle) * 25;
		ray->dir_y = sin(ray->p_angle) * 25;
	}
	if (keycode == RIGHT)
	{
		ray->p_angle += DEG * 5;
		if (ray->p_angle > M_PI * 2)
			ray->p_angle -= M_PI * 2;
		ray->dir_x = cos(ray->p_angle) * 25;
		ray->dir_y = sin(ray->p_angle) * 25;
	}
}
// printf("ray->p_angle: %f\n", ray->p_angle);

/*
*		 ----270 (3*PI/2)----
*		/					 \	
*	   /					  \
* 180 (PI)					0 / 360 (2*PI)
*	   \					 /
*		\					/
*		  ----90 (PI/2)----
*
* In mlx display window
* the lesser the y, the more upwards the index is
* the lesser the x, the more left the index is
* 
* In 2d graph
* the lesser the y, the more *downwards* the index is
* the lesser the x, the more left the index is
*/
