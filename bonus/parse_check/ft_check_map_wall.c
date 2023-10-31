/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_ffmap_wall.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:00:05 by atok              #+#    #+#             */
/*   Updated: 2023/08/06 10:00:05 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	ff_outer_map(t_game *game, char **ffmap, int x, int y)
{
	if ((y < 0 || y >= game->map.n_row + 2) || \
		(x < 0 || x >= game->map.n_col + 2))
		return ;
	if (ffmap[y][x] == '0')
	{
		ft_exit_error("Error\n map not enclosed/surounded by '1'\n");
		return ;
	}
	if (ffmap[y][x] == ' ')
	{
		ffmap[y][x] = 'F';
		ff_outer_map(game, ffmap, x + 1, y);
		ff_outer_map(game, ffmap, x - 1, y);
		ff_outer_map(game, ffmap, x, y + 1);
		ff_outer_map(game, ffmap, x, y - 1);
	}
	else
		return ;
}

void	ft_check_map_wall(t_game *game)
{
	ff_outer_map(game, game->map.ffomap, 0, 0);
}

	// /*view flood fill map*/
	// int	i = 0;
	// while(game->map.ffomap[i] != 0x00)
	// 	printf("%s\n",game->map.ffomap[i++]);
	// make map surounded by ' ' to ff outside;