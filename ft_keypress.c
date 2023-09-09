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
	// mlx_pixel_put(game->mlx, game->win, game->player.x + game->ray.dir_x, game->player.y + game->ray.dir_y , game->player.color);
	int xs = game->player.x;
	int xe = game->player.x + game->ray.dir_x;
	int ys = game->player.y;
	int ye = game->player.y + game->ray.dir_y;

	// Compute the differences between the start and end points
	int dx = xe - xs;
	int dy = ye - ys;

	// Determine whether the line is steeper in the x or y direction
	// which is longer x or y?
	int steps;
	if (abs(dx) > abs(dy)) 
		steps = abs(dx);
	else 
		steps = abs(dy);

	// Calculate the increments for x and y
	float x_increment = (float)dx / steps;
	float y_increment = (float)dy / steps;

	int i = 0;
	float j = xs, y = ys;
	while (i <= steps) 
	{
		mlx_pixel_put(game->mlx, game->win, (int)j, (int)y, game->player.color);
		j += x_increment;
		y += y_increment;
		i++;
	}
}

void	draw_cell(t_game *game, int x, int y, int color)
{
	int x_start;
	int y_start;
	int x_end;
	int y_end;
	int	tmp;

	x_start = x * TILESCALE;
	y_start = y * TILESCALE;
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
			if (game->map.xymap[i][j] == '0')
				draw_cell(game, j, i, 0x828782);
			if (game->map.xymap[i][j] == 'N' || game->map.xymap[i][j] == 'S' ||
				game->map.xymap[i][j] == 'E' || game->map.xymap[i][j] == 'W')
				draw_cell(game, j, i, 0x828782);
			j++;
		}
		i++;
	}
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.y -= 4;
	if (keycode == S)
		game->player.y += 4;
	if (keycode == A)
		game->player.x -= 4;
	if (keycode == D)
		game->player.x += 4;
	if (keycode == LEFT)
		rotation(LEFT, *game, &game->ray);
	if (keycode == RIGHT)
		rotation(RIGHT, *game, &game->ray);
	if (keycode == ESC)
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
