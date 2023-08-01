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
	mlx_clear_window(game->mlx, game->win);
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
	mlx_do_sync(game->mlx); // Ensure smooth window management
}

/*
keycode vary depending on LINUX/MACOS
*/
int	keypress(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.y -= 4;
	else if (keycode == S)
		game->player.y += 4;
	else if (keycode == A)
		game->player.x -= 4;
	else if (keycode == D)
		game->player.x += 4;
	else if (keycode == ESC)
		exit(1);
	draw_dot(game);
	return (0);
}

int	ft_end(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}

void	ft_keypress(t_game *game)
{
	mlx_hook(game->win, (02), (1L << 0), keypress, game);
	mlx_hook(game->win, (17), (1L << 0), ft_end, game);
}
