/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:04:17 by atok              #+#    #+#             */
/*   Updated: 2023/07/28 19:04:17 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//configured WASD movement based on player vector
//replaced ray->ra with ray->angle, otherwise cant casy multiple ray
int	keypress(int keycode, t_game *game)
{
	if (keycode == W)
	{
		game->player.x += cos(game->ray.p_angle) * 4;
		game->player.y += sin(game->ray.p_angle) * 4;
	}
	if (keycode == S)
	{
		game->player.x -= cos(game->ray.p_angle) * 4;
		game->player.y -= sin(game->ray.p_angle) * 4;
	}
	//move left right config
	if (keycode == A)
	{
		game->player.x += sin(game->ray.p_angle) * 2;
		game->player.y -= cos(game->ray.p_angle) * 2;
	}
	if (keycode == D)
	{
		game->player.x -= sin(game->ray.p_angle) * 2;
		game->player.y += cos(game->ray.p_angle) * 2;
	}
	if (keycode == LEFT)
		rotation(LEFT, *game, &game->ray);
	if (keycode == RIGHT)
		rotation(RIGHT, *game, &game->ray);
	if (keycode == ESC)
		exit(1);
	mlx_clear_window(game->mlx, game->win);
	draw_2dmap(game);
	draw_player(game);
	draw_line(game, game->player.x + game->ray.dir_x,  game->player.y + game->ray.dir_y, 0xFF00FF);
	// printf("P: dir_x: %f, dir_y %f\n", game->ray.dir_x, game->ray.dir_y);
	raycast(game,&game->ray);
		// draw_line(game, 0 , 0 , 0xFFFFFF); //test
	mlx_do_sync(game->mlx);
	return (0);
}

// //to: configure WASD movement based on player vector
// int	keypress(int keycode, t_game *game)
// {
// 	if (keycode == W)
// 	{
// 		game->player.x += cos(game->ray.ra) * 4;
// 		game->player.y += sin(game->ray.ra) * 4;
// 	}
// 	if (keycode == S)
// 	{
// 		game->player.x -= cos(game->ray.ra) * 4;
// 		game->player.y -= sin(game->ray.ra) * 4;
// 	}
// 	if (keycode == A)
// 		game->player.x -= 4;
// 	if (keycode == D)
// 		game->player.x += 4;
// 	if (keycode == LEFT)
// 		rotation(LEFT, *game, &game->ray);
// 	if (keycode == RIGHT)
// 		rotation(RIGHT, *game, &game->ray);
// 	if (keycode == ESC)
// 		exit(1);
// 	mlx_clear_window(game->mlx, game->win);
// 	draw_2dmap(game);
// 	draw_player(game);
// 	draw_line(game, game->player.x + game->ray.dir_x,  game->player.y + game->ray.dir_y, 0xFF00FF);
// 	// printf("P: dir_x: %f, dir_y %f\n", game->ray.dir_x, game->ray.dir_y);
// 	raycast(game,&game->ray);
// 		// draw_line(game, 0 , 0 , 0xFFFFFF); //test
// 	mlx_do_sync(game->mlx);
// 	return (0);
// }

int	ft_end(t_game *game)
{
	//mlx_destroy_window(game->mlx, game->win);
	//mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}

void	ft_keypress(t_game *game)
{
	mlx_hook(game->win, (02), (1L << 0), keypress, game);
	mlx_hook(game->win, (17), (1L << 0), ft_end, game);
}
