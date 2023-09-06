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

void	draw_dot(t_game *game)
{
	// mlx_clear_window(game->mlx, game->win);
	//mlx_pixel_put(game.mlx, game.win, game.player.y, game.player.y, game.player.color); // 1 pixle dot
	int x = game->player.x - 2; // 5 x 5 dot
    while (x <= game->player.x + 2) 
	{
		int y = game->player.y - 2;
		while (y <= game->player.y + 2) 
		{
			mlx_pixel_put(game->mlx, game->win, x, y, game->player.color);
			y++;
		}
		x++;
	}
	// mlx_do_sync(game->mlx); // Ensure smooth window management
}

void	draw_cell(t_game *game, int x, int y, int color)
{
	int x_start;
	int y_start;
	int x_end;
	int y_end;
	int	tmp;

	x_start = x * TILESCALE + 1;
	y_start = y * TILESCALE + 1;
	x_end = (x + 1) * TILESCALE - 1;
	y_end = (y + 1) * TILESCALE - 1;

	while (y_start < y_end)
	{
		tmp = x_start;
		while (tmp < x_end)
		{
			mlx_pixel_put(game->mlx, game->win, tmp, y_start, color);
			tmp++;
		}
		y_start++;
	}
}

void	draw_2dmap(t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	while (game->map.xymap[i] != 0x00)
	{
		j = 0;
		while (game->map.xymap[i][j] != 0x00)
		{
			if (game->map.xymap[i][j] == '1')
				draw_cell(game, j, i, 0x0000FF);
			else if (game->map.xymap[i][j] == '0')
				draw_cell(game, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == W)
	{
		game->player.y -= 4;
		printf("W pressed\n");
	}
	else if (keycode == S)
		game->player.y += 4;
	else if (keycode == A)
		game->player.x -= 4;
	else if (keycode == D)
		game->player.x += 4;
	else if (keycode == LEFT)
	{
		rotation(LEFT, game->ray);
		printf("<- pressed\n");
	}
	else if (keycode == RIGHT)
	{
		rotation(RIGHT, game->ray);
		printf("-> pressed\n");
	}
	else if (keycode == ESC)
		exit(1);
	mlx_clear_window(game->mlx, game->win);
	draw_2dmap(game);
	draw_dot(game);
	mlx_do_sync(game->mlx);
	return (0);
}

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
