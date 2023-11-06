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

#include "../incl/cub3d.h"

/*5 x 5 pixel player dot*/
void	draw_player(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x - 2;
	while (x <= game->player.x + 2)
	{
		y = game->player.y - 2;
		while (y <= game->player.y + 2)
		{
			img_pix_put(&game->img, x, y, game->player.color);
			y++;
		}
		x++;
	}
}

/*compare steepness between xe - xs and ye - ys*/
int	step(int dx, int dy)
{
	if (abs(dx) > abs(dy))
		return (abs(dx));
	return (abs(dy));
}

void	draw_line(t_game *game, int xe, int ye, int color)
{
	float	xs;
	float	ys;
	int		steps;
	int		i;

	xs = game->player.x;
	ys = game->player.y;
	steps = step((int)((float)xe - xs), (int)((float)ye - ys));
	i = 0;
	while (i <= steps)
	{
		img_pix_put(&game->img, (int)xs, (int)ys, color);
		xs += ((float)xe - xs) / steps;
		ys += ((float)ye - ys) / steps;
		i++;
	}
}

void	draw_cell(t_game *game, int x, int y, int color)
{
	int	x_start;
	int	y_start;

	y_start = y * SCALE;
	while (y_start < (y + 1) * SCALE)
	{
		x_start = x * SCALE;
		while (x_start < (x + 1) * SCALE)
			img_pix_put(&game->img, x_start++, y_start, color);
		y_start++;
	}
	x_start = x * SCALE;
	while (x_start < (x + 1) * SCALE)
		img_pix_put(&game->img, x_start++, y * SCALE, BLACK);
	y_start = y * SCALE;
	while (y_start < (y + 1) * SCALE)
	{
		img_pix_put(&game->img, x * SCALE, y_start, BLACK);
		img_pix_put(&game->img, (x + 1) * SCALE, y_start, BLACK);
		y_start++;
	}
	x_start = x * SCALE;
	while (x_start < (x + 1) * SCALE)
		img_pix_put(&game->img, x_start++, y_start, BLACK);
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
			if (game->map.xymap[i][j] == '2')
				draw_cell(game, j, i, BROWN);
			if (game->map.xymap[i][j] == '3')
				draw_cell(game, j, i, PINK);
			if (game->map.xymap[i][j] == '1')
				draw_cell(game, j, i, BLUE);
			if (game->map.xymap[i][j] == '0')
				draw_cell(game, j, i, GREY);
			if (game->map.xymap[i][j] == 'N' || game->map.xymap[i][j] == 'S' ||
				game->map.xymap[i][j] == 'E' || game->map.xymap[i][j] == 'W')
				draw_cell(game, j, i, GREY);
			j++;
		}
		i++;
	}
}

// void	draw_line(t_game *game, int xe, int ye, int color)
// {
// 	float xs;
// 	float ys;
// 	int dx;
// 	int dy;
// 	int steps;
// 	float x_increment;
// 	float y_increment; 
// 	int i;

// 	xs = game->player.x;
// 	ys = game->player.y;
// 	dx = xe - xs; // Compute the differences between the start and end points
// 	dy = ye - ys;
// 	steps = step(dx,dy);
// 	x_increment = (float)dx / steps; 	// Calculate the increments for x and y
// 	y_increment = (float)dy / steps;
// 	i = 0;
// 	while (i <= steps) 
// 	{
// 		img_pix_put(&game->img, (int)xs, (int)ys, color);
// 		xs += x_increment;
// 		ys += y_increment;
// 		i++;
// 	}
// }

// void	draw_cell(t_game *game, int x, int y, int color)
// {
// 	int	x_start;
// 	int	y_start;
// 	int	x_end;
// 	int	y_end;
// 	int	tmp;

// 	x_start = x * SCALE;
// 	y_start = y * SCALE;
// 	x_end = (x + 1) * SCALE;// - 1;
// 	y_end = (y + 1) * SCALE;// - 1;

// 	while (y_start < y_end)
// 	{
// 		tmp = x_start;
// 		while (tmp < x_end)
// 		{
// 			img_pix_put(&game->img, tmp, y_start, color);
// 			tmp++;
// 		}
// 		y_start++;
// 	}

// 	// checkerd black lines
// 	tmp = x * SCALE;
// 	while (tmp < x_end)
// 		img_pix_put(&game->img, tmp++, y * SCALE, BLACK);
// 	y_start = y * SCALE;
// 	while (y_start < y_end)
// 	{
// 		img_pix_put(&game->img, x * SCALE, y_start, BLACK);
// 		img_pix_put(&game->img, (x + 1) * SCALE, y_start, BLACK);
// 		y_start++;
// 	}
// 	tmp = x * SCALE;
// 	while (tmp < x_end)
// 		img_pix_put(&game->img, tmp++, y_start, BLACK);
// }