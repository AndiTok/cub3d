/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:48:55 by atok              #+#    #+#             */
/*   Updated: 2023/08/01 10:48:55 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_game *game)
{
	//int	screen_width;
	//int	screen_height;
	game->mlx = mlx_init();
	//mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	game->win_width = 400; //screen_width * 0.5;
	game->win_height = 400; //screen_height * 0.5;
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height,
			"cub3D");
}
