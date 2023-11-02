/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_vars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:03:41 by atok              #+#    #+#             */
/*   Updated: 2023/07/31 22:03:41 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	ft_initialize_vars(t_game *game)
{
	game->win_width = 0;
	game->win_height = 0;
	game->file.lines = 0;
	game->file.mid = 0;
	game->file.f = 0;
	game->file.c = 0;
	game->file.no = 0;
	game->file.so = 0;
	game->file.we = 0;
	game->file.ea = 0;
	game->map.n_row = 0;
	game->map.n_col = 0;
	game->toggle_m = 0;
	game->map.d = 0;
	game->fps = 0;
	game->mouse = 1;
}
