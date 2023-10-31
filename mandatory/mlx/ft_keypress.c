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

/*keeps player in minimap, can pass through walls*/
void	stay_in_map(t_game *game)
{
	if (game->player.x - 2 < 0)
		game->player.x += 2;
	if (game->player.y - 2 < 0)
		game->player.y += 2;
	if (game->player.x + 2 > game->map.n_col * SCALE)
		game->player.x -= 2;
	if (game->player.y + 2 > game->map.n_row * SCALE)
		game->player.y -= 2;
}

void	plyr_movment(int keycode, t_game *game)
{
	if (keycode == W)
	{
		game->player.x += cos(game->ray.p_angle) * 2;
		game->player.y += sin(game->ray.p_angle) * 2;
	}
	if (keycode == S)
	{
		game->player.x -= cos(game->ray.p_angle) * 2;
		game->player.y -= sin(game->ray.p_angle) * 2;
	}
	if (keycode == A)
	{
		game->player.x += sin(game->ray.p_angle) * 2;
		game->player.y -= cos(game->ray.p_angle) * 2;
	}
	if (keycode == D)
	{
		game->player.x -= sin(game->ray.p_angle) * 2;
		game->player.y += cos(game->ray.p_angle) * 2;
	}
}

/*player movement based on player vector*/
int	keypress(int keycode, t_game *game)
{
	stay_in_map(game);
	if (keycode == L)
		game->toggle_m = (game->toggle_m + 1) % 2;
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		plyr_movment(keycode, game);
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
