/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:34:16 by wyap              #+#    #+#             */
/*   Updated: 2023/11/06 16:36:26 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

/*
* handle cursor movement and visibility
* 
* takes in x and y to set cursor position
* y value not needed for calculation hence (void)
* render frame after each movement
* rotation speed adjustable
*/
int	mouse_move(int x, int y, t_game *game)
{
	int		prev_x;
	int		delta_x;
	float	rotation_speed;

	(void) y;
	if (game->mouse == 1)
	{
		prev_x = 630;
		delta_x = x - prev_x;
		rotation_speed = 0.0042;
		game->ray.p_angle += delta_x * rotation_speed;
		game->ray.p_angle = angle_reset(game->ray.p_angle);
		game->ray.dir_x = cos(game->ray.p_angle) * 25;
		game->ray.dir_y = sin(game->ray.p_angle) * 25;
		prev_x = 630;
		mlx_mouse_move(game->win, 630, 360);
		ft_render(game);
	}
	return (0);
}
	// if(game->mouse == 0)
	// 	mlx_mouse_show();

void	toggle_cursor(t_game *game)
{
	game->mouse = (game->mouse + 1) % 2;
	mouse_move(631, 360, game);
	mouse_move(629, 360, game);
	if (game->mouse == 1)
		mlx_mouse_hide();
	if (game->mouse == 0)
		mlx_mouse_show();
}

/*open/close door*/
void	interact_door(t_game *game)
{
	int	tmpx;
	int	tmpy;

	tmpx = game->player.x + cos(game->ray.p_angle) * SCALE;
	tmpy = game->player.y + sin(game->ray.p_angle) * SCALE;
	if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '2')
		game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] = '3';
	else if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '3')
		game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] = '2';
}

/*x button*/
int	ft_end(t_game *game)
{
	free(game->mlx);
	exit(1);
}
