/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:39:37 by atok              #+#    #+#             */
/*   Updated: 2023/09/11 21:39:37 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_game *game)
{
	// mlx_clear_window(game->mlx, game->win);
	//mlx_pixel_put(game.mlx, game.win, game.player.y, game.player.y, game.player.color); // 1 pixle dot
	int	x;
	int	y;
	
	x = game->player.x - 2; // 5 x 5 dot
    while (x <= game->player.x + 2) 
	{
		y = game->player.y - 2;
		while (y <= game->player.y + 2) 
		{
			mlx_pixel_put(game->mlx, game->win, x, y, game->player.color);
			y++;
		}
		x++;
	}
	// mlx_do_sync(game->mlx); // Ensure smooth window management
	// mlx_pixel_put(game->mlx, game->win, game->player.x + game->ray.dir_x, game->player.y + game->ray.dir_y , game->player.color);
}

int step(int dx, int dy)
{
	if (ft_abs(dx) > ft_abs(dy)) // Determine whether the line is steeper in the x or y direction
		return(ft_abs(dx));		// which is longer x or y?
	else 
		return(ft_abs(dy));
}

void	draw_line(t_game *game, int xe, int ye, int color)
{
	float xs;
	float ys;
	int dx;
	int dy;
	int steps;
	float x_increment;
	float y_increment; 
	int i;
	 
	xs = game->player.x;
	ys = game->player.y;
	dx = xe - xs; // Compute the differences between the start and end points
	dy = ye - ys;
	// dx = (int)((float)xe - xs); // Compute the differences between the start and end points
	// dy = (int)((float)ye - ys);
	steps = step(dx,dy);
	x_increment = (float)dx / steps; 	// Calculate the increments for x and y
	y_increment = (float)dy / steps;
	i = 0;
	while (i <= steps) 
	{
		mlx_pixel_put(game->mlx, game->win, (int)xs, (int)ys, color);
		xs += x_increment;
		ys += y_increment;
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