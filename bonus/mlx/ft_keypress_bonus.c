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

#include "../incl/cub3d.h"

int	collision(t_game *game, int x, int y)
{
	if (game->map.xymap[((int)y / SCALE)][((int)x / SCALE)] == '1'
	|| game->map.xymap[((int)y / SCALE)][((int)x / SCALE)] == '2')
		return (1);
	return (0);
}

/*
* player up down movement, with wall collision
* check 4 pixels ahead if encounter wall, reverse 2 pixels
*/
void	plyr_up_down(int keycode, t_game *game)
{
	int	tmpx;
	int	tmpy;

	if (keycode == W)
	{
		game->player.x += cos(game->ray.p_angle) * 2;
		game->player.y += sin(game->ray.p_angle) * 2;
		tmpx = game->player.x + cos(game->ray.p_angle) * 4;
		tmpy = game->player.y + sin(game->ray.p_angle) * 4;
		if (collision(game, tmpx, tmpy) == 1)
		{
			game->player.x -= cos(game->ray.p_angle) * 2;
			game->player.y -= sin(game->ray.p_angle) * 2;
		}
		return ;
	}
	game->player.x -= cos(game->ray.p_angle) * 2;
	game->player.y -= sin(game->ray.p_angle) * 2;
	tmpx = game->player.x - cos(game->ray.p_angle) * 4;
	tmpy = game->player.y - sin(game->ray.p_angle) * 4;
	if (collision(game, tmpx, tmpy) == 1)
	{
		game->player.x += cos(game->ray.p_angle) * 2;
		game->player.y += sin(game->ray.p_angle) * 2;
	}
}
	// if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '1'
	// || game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '2')

/*
* player left right movement, with wall collision
* check 4 pixels ahead if encounter wall, reverse 2 pixels
*/
void	plyr_left_right(int keycode, t_game *game)
{
	int	tmpx;
	int	tmpy;

	if (keycode == A)
	{
		game->player.x += sin(game->ray.p_angle) * 2;
		game->player.y -= cos(game->ray.p_angle) * 2;
		tmpx = game->player.x + sin(game->ray.p_angle) * 4;
		tmpy = game->player.y - cos(game->ray.p_angle) * 4;
		if (collision(game, tmpx, tmpy) == 1)
		{
			game->player.x -= sin(game->ray.p_angle) * 2;
			game->player.y += cos(game->ray.p_angle) * 2;
		}
		return ;
	}
	game->player.x -= sin(game->ray.p_angle) * 2;
	game->player.y += cos(game->ray.p_angle) * 2;
	tmpx = game->player.x - sin(game->ray.p_angle) * 4;
	tmpy = game->player.y + cos(game->ray.p_angle) * 4;
	if (collision(game, tmpx, tmpy) == 1)
	{
		game->player.x += sin(game->ray.p_angle) * 2;
		game->player.y -= cos(game->ray.p_angle) * 2;
	}
}

/*
*door interaction, cursor toggle, minimap toggle, esc to exit
*player movement with wall collision, player rotation*/
int	keypress(int keycode, t_game *game)
{
	if (keycode == E)
		interact_door(game);
	if (keycode == M)
		toggle_cursor(game);
	if (keycode == L)
		game->toggle_m = (game->toggle_m + 1) % 2;
	if (keycode == W || keycode == S)
		plyr_up_down(keycode, game);
	if (keycode == A || keycode == D)
		plyr_left_right(keycode, game);
	if (keycode == LEFT)
		rotation(LEFT, *game, &game->ray);
	if (keycode == RIGHT)
		rotation(RIGHT, *game, &game->ray);
	if (keycode == ESC)
		exit(1);
	ft_render(game);
	return (0);
}

void	ft_keypress(t_game *game)
{
	mlx_hook(game->win, (02), (1L << 0), keypress, game);
	mlx_hook(game->win, (06), (1L << 6), mouse_move, game);
	mlx_hook(game->win, (17), (1L << 0), ft_end, game);
	mlx_loop_hook(game->mlx, ft_fps, game);
}
