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
		if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '1'
		|| game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '2')
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
	if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '1'
	|| game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '2')
	{
		game->player.x += cos(game->ray.p_angle) * 2;
		game->player.y += sin(game->ray.p_angle) * 2;
	}
}

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
		if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '1'
		|| game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '2')
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
	if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '1'
	|| game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '2')
	{
		game->player.x += sin(game->ray.p_angle) * 2;
		game->player.y -= cos(game->ray.p_angle) * 2;
	}
}

/*
*minimap toggle, esc to exit
*player movement with wall collision*/
int	keypress(int keycode, t_game *game)
{
	int	tmpx;
	int	tmpy;
	
	if (keycode == E)
	{
		tmpx = game->player.x + cos(game->ray.p_angle) * SCALE;
		tmpy = game->player.y + sin(game->ray.p_angle) * SCALE;
		if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '2')
			game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] = '0';
	}	
	if (keycode == M)
		mlx_mouse_move(game->mlx,game->win, 630, 360);
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

/*x button*/
int	ft_end(t_game *game)
{
	free(game->mlx);
	exit(1);
}

int mouse_move(int x, int y, t_game *game)
{
    (void) y; // We're not using the y-coordinate

    // Initialize prev_x the first time the function is called
    static int prev_x = 0;

    // Calculate the change in the x-coordinate
    int delta_x = x - prev_x;
    
    // Define the rotation speed
    float rotation_speed = 0.02; // Adjust this value as needed
    
    // Update the view angle based on the change in the x-coordinate
    game->ray.p_angle += delta_x * rotation_speed;
    
    // Ensure the view angle stays within the range [0, 2 * PI]
    if (game->ray.p_angle < 0)
        game->ray.p_angle += 2 * M_PI;
    else if (game->ray.p_angle >= 2 * M_PI)
        game->ray.p_angle -= 2 * M_PI;
    
    // Update the direction vector
    game->ray.dir_x = cos(game->ray.p_angle) * 25;
    game->ray.dir_y = sin(game->ray.p_angle) * 25;
    
    // Update the previous x-coordinate
    prev_x = x;

    // Redraw the scene with the updated view angle
    // Call your rendering function here to display the scene
	ft_render(game);
    return (0);
}

void	ft_keypress(t_game *game)
{
	mlx_loop_hook(game->mlx, ft_fps, game);
	mlx_hook(game->win, 6, (1L << 6), mouse_move, game);
	mlx_hook(game->win, (02), (1L << 0), keypress, game);
	mlx_hook(game->win, (17), (1L << 0), ft_end, game);
}
