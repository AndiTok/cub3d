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

/*player angle from t_raycast*/
void	rotation(int keycode, t_game game, t_raycast *ray)
{
	(void) game;
	// static float angle;
	if (keycode == LEFT)
	{
		// ray->ra -= 0.104719;
		ray->ra -= DEG * 5;
		if (ray->ra < 0)
			ray->ra = M_PI * 2;// - 0.0005;
		printf("ray->ra: %f\n", ray->ra);
		printf("ft_round(ray->ra): %f\n", ft_round(ray->ra));
		ray->dir_x = cos(ray->ra) * 25; // multiply to draw longer line
		ray->dir_y = sin(ray->ra) * 25;
		// mlx_pixel_put(game.mlx, game.win, game.player.x + ray->dir_x , game.player.y + ray->dir_y , game.player.color);
	}
	if (keycode == RIGHT)
	{
		// ray->ra += 0.104719;
		ray->ra += DEG * 5;
        if (ray->ra > M_PI * 2)
            ray->ra = 0.0;//0.10472 - 0.0005;
		printf("ray->ra: %f\n", ray->ra);
		printf("ft_round(ray->ra): %f\n", ft_round(ray->ra));
		ray->dir_x = cos(ray->ra) * 25; // multiply to draw longer line
		ray->dir_y = sin(ray->ra) * 25;
		// mlx_pixel_put(game.mlx, game.win, game.player.x + ray->dir_x, game.player.y + ray->dir_y , game.player.color);
	}
	// return (0);
}
