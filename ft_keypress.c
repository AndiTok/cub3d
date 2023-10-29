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

/*player movement with wall collision*/
int	keypress(int keycode, t_game *game)
{
	if (keycode == L)
		game->toggle_m = (game->toggle_m + 1) % 2;
	if (keycode == W)
	{
		game->player.x += cos(game->ray.p_angle) * 2; // move 2 pixles
		game->player.y += sin(game->ray.p_angle) * 2;
		int tmpx = game->player.x + cos(game->ray.p_angle) * 4; // check 4 pixles ahead
		int tmpy = game->player.y + sin(game->ray.p_angle) * 4; // modify value to manipulate distance
		// printf("x/j - %f, y/i %f\n",game->player.x,game->player.y);
		// printf("%dmx,%dmy\n",(int)game->player.x / SCALE,(int)game->player.y / SCALE);
		// printf("%c\n", game->map.xymap[(int)(game->player.y / SCALE)][(int)(game->player.x / SCALE)]);
		// if (game->map.xymap[((int)game->player.y / SCALE)][((int)game->player.x / SCALE)] == '1')
		if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '1')
		{
			game->player.x -= cos(game->ray.p_angle) * 2;// reverse the movement
			game->player.y -= sin(game->ray.p_angle) * 2;// if wall head
		}
	}
	if (keycode == S)
	{
		game->player.x -= cos(game->ray.p_angle) * 2;
		game->player.y -= sin(game->ray.p_angle) * 2;
		int tmpx = game->player.x - cos(game->ray.p_angle) * 4;
		int tmpy = game->player.y - sin(game->ray.p_angle) * 4;
		if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '1')
		{
			game->player.x += cos(game->ray.p_angle) * 2;
			game->player.y += sin(game->ray.p_angle) * 2;
		}
	}
	//move left right config
	if (keycode == A)
	{
		game->player.x += sin(game->ray.p_angle) * 2;
		game->player.y -= cos(game->ray.p_angle) * 2;
		int tmpx = game->player.x + sin(game->ray.p_angle) * 4;
		int tmpy = game->player.y - cos(game->ray.p_angle) * 4;
		if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '1')
		{
			game->player.x -= sin(game->ray.p_angle) * 2;
			game->player.y += cos(game->ray.p_angle) * 2;
		}
	}
	if (keycode == D)
	{
		game->player.x -= sin(game->ray.p_angle) * 2;
		game->player.y += cos(game->ray.p_angle) * 2;
		int tmpx = game->player.x - sin(game->ray.p_angle) * 4;
		int tmpy = game->player.y + cos(game->ray.p_angle) * 4;
		if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '1')
		{
			game->player.x += sin(game->ray.p_angle) * 2;
			game->player.y -= cos(game->ray.p_angle) * 2;
		}
	}
	if (keycode == LEFT)
		rotation(LEFT, *game, &game->ray);
	if (keycode == RIGHT)
		rotation(RIGHT, *game, &game->ray);
	if (keycode == ESC)
		exit(1);
	ft_render(game);
	return (0);
}

int	ft_end(t_game *game)
{
	free(game->mlx);
	exit(1);
}

void	ft_keypress(t_game *game)
{
	mlx_hook(game->win, (02), (1L << 0), keypress, game);
	mlx_hook(game->win, (17), (1L << 0), ft_end, game);
}
