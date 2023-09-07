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

void	rotation(int keycode, t_game game, t_raycast ray)
{
	static double angle;
	if (keycode == LEFT)
	{
		angle -= 0.1;
		printf("angle: %f\n", angle);
		if (angle < 0)
			angle += PI * 2; //reset to 2 PI
		ray.dir_x = cos(angle) * 5; // multiply 5 to see significant value
		ray.dir_y = sin(angle) * 5;
		mlx_pixel_put(game.mlx, game.win, game.player.x + ray.dir_x , game.player.y + ray.dir_y , game.player.color);

	}
	if (keycode == RIGHT)
	{
		angle += 0.1;
		printf("angle: %f\n", angle);
		if (angle > PI * 2)
			angle -= PI * 2; //reset to 2 PI
		ray.dir_x = cos(angle) * 5; // multiply 5 to see significant value
		ray.dir_y = sin(angle) * 5;
		mlx_pixel_put(game.mlx, game.win, game.player.x + ray.dir_x, game.player.y + ray.dir_y , game.player.color);
	}
	// return (0);
}

