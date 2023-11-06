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

#include "../incl/cub3d.h"

void	ft_init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win_width = WIN_WIDTH;
	game->win_height = WIN_HEIGHT;
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height,
			"cub3D_bonus");
}
