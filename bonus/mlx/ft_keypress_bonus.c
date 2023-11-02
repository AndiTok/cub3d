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

void	plyr_up(t_game *game)//(int trigger, t_game *game)
{
	int	tmpx;
	int	tmpy;

	// if (trigger == 1)
	// {
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
		// ft_render(game);
	// }
}

void	plyr_down(int trigger, t_game *game)
{
	int	tmpx;
	int	tmpy;

	if (trigger == 1)
	{
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
}

/*
* player up down movement, with wall collision
* check 4 pixels ahead if encounter wall, reverse 2 pixels
*/
// void	plyr_up_down(int keycode, t_game *game)
// {
// 	int	tmpx;
// 	int	tmpy;

// 	if (keycode == W)
// 	{
// 		game->player.x += cos(game->ray.p_angle) * 2;
// 		game->player.y += sin(game->ray.p_angle) * 2;
// 		tmpx = game->player.x + cos(game->ray.p_angle) * 4;
// 		tmpy = game->player.y + sin(game->ray.p_angle) * 4;
// 		if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '1'
// 		|| game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '2')
// 		{
// 			game->player.x -= cos(game->ray.p_angle) * 2;
// 			game->player.y -= sin(game->ray.p_angle) * 2;
// 		}
// 		return ;
// 	}
// 	game->player.x -= cos(game->ray.p_angle) * 2;
// 	game->player.y -= sin(game->ray.p_angle) * 2;
// 	tmpx = game->player.x - cos(game->ray.p_angle) * 4;
// 	tmpy = game->player.y - sin(game->ray.p_angle) * 4;
// 	if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '1'
// 	|| game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '2')
// 	{
// 		game->player.x += cos(game->ray.p_angle) * 2;
// 		game->player.y += sin(game->ray.p_angle) * 2;
// 	}
// }

void	plyr_left(int trigger, t_game *game)
{
	int	tmpx;
	int	tmpy;

	if (trigger == 1)
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
	}
}

void	plyr_right(int trigger, t_game *game)
{
	int	tmpx;
	int	tmpy;

	if (trigger == 1)
	{
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
}

/*
* player left right movement, with wall collision
* check 4 pixels ahead if encounter wall, reverse 2 pixels
*/
// void	plyr_left_right(int keycode, t_game *game)
// {
// 	int	tmpx;
// 	int	tmpy;

// 	if (keycode == A)
// 	{
// 		game->player.x += sin(game->ray.p_angle) * 2;
// 		game->player.y -= cos(game->ray.p_angle) * 2;
// 		tmpx = game->player.x + sin(game->ray.p_angle) * 4;
// 		tmpy = game->player.y - cos(game->ray.p_angle) * 4;
// 		if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '1'
// 		|| game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '2')
// 		{
// 			game->player.x -= sin(game->ray.p_angle) * 2;
// 			game->player.y += cos(game->ray.p_angle) * 2;
// 		}
// 		return ;
// 	}
// 	game->player.x -= sin(game->ray.p_angle) * 2;
// 	game->player.y += cos(game->ray.p_angle) * 2;
// 	tmpx = game->player.x - sin(game->ray.p_angle) * 4;
// 	tmpy = game->player.y + cos(game->ray.p_angle) * 4;
// 	if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '1'
// 	|| game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '2')
// 	{
// 		game->player.x += sin(game->ray.p_angle) * 2;
// 		game->player.y -= cos(game->ray.p_angle) * 2;
// 	}
// }

void	wasd2(t_game *game)
{
	// printf("w? %d\n", game->key.w);
	if (game->key.w == 1)
		plyr_up(game);
}

void	wasd(int keycode, t_game *game)
{
	// printf("wasd: ");
	if (keycode == W)
	{
		// printf("W\n");
		game->key.w = 1;
		// plyr_up(game->key.w, game);
	}
	if (keycode == A)
	{
		// printf("A\n");
		game->key.a = 1;
		plyr_left(game->key.a, game);
	}
	if (keycode == S)
	{
		// printf("S\n");
		game->key.s = 1;
		plyr_down(game->key.s, game);
	}
	if (keycode == D)
	{
		// printf("D\n");
		game->key.d = 1;
		plyr_right(game->key.d, game);
	}
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->key.w = 0;
	if (keycode == A)
		game->key.a = 0;
	if (keycode == S)
		game->key.s = 0;
	if (keycode == D)
		game->key.d = 0;
	return (0);
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
			game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] = '3';
		else if (game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] == '3')
			game->map.xymap[((int)tmpy / SCALE)][((int)tmpx / SCALE)] = '2';
	}	
	// if (keycode == M)
		// mlx_mouse_move(game->mlx,game->win, 630, 360);
	if (keycode == L)
		game->toggle_m = (game->toggle_m + 1) % 2;
	if (keycode == W || keycode == S || keycode == A || keycode == D)
	{
		wasd(keycode, game);
		wasd2(game);
	}
	// if (keycode == W || keycode == S)
	// 	plyr_up_down(keycode, game);
	// if (keycode == A || keycode == D)
	// 	plyr_left_right(keycode, game);
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

//to chg param to t_ray *ray
int mouse_move(int x, int y, t_game *game)
{
    (void) y; // We're not using the y-coordinate

    // Initialize prev_x the first time the function is called
    static int prev_x = 630;

    // Calculate the change in the x-coordinate
    int delta_x = x - prev_x;
    
    // Define the rotation speed
    float rotation_speed = 0.0042; // Adjust this value as needed
    
    // Update the view angle based on the change in the x-coordinate
    game->ray.p_angle += delta_x * rotation_speed;
    
    // Ensure the view angle stays within the range [0, 2 * PI]
	game->ray.p_angle = angle_reset(game->ray.p_angle);
    // printf("%f\n", game->ray.p_angle);
    
    // Update the direction vector
    game->ray.dir_x = cos(game->ray.p_angle) * 25;
    game->ray.dir_y = sin(game->ray.p_angle) * 25;
    
    // Update the previous x-coordinate
    prev_x = 630;
	mlx_mouse_move(game->win, 630, 360);
	mlx_mouse_hide();
    // Redraw the scene with the updated view angle
    // Call your rendering function here to display the scene
	ft_render(game);

    return (0);
}

void	ft_keypress(t_game *game)
{
	mlx_loop_hook(game->mlx, ft_fps, game);
	// mlx_hook(game->win, (06), (1L << 6), mouse_move, game);
	mlx_hook(game->win, (02), (1L << 0), keypress, game);
	mlx_hook(game->win, (03), (1L << 1), key_release, game);
	mlx_hook(game->win, (17), (1L << 0), ft_end, game);
}
