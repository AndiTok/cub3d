/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:23:01 by atok              #+#    #+#             */
/*   Updated: 2023/10/31 00:54:59 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//chekc inside wiht FF
	// dupe an ffmap
	// player postition start 
	// error if ' ' or  '\t'
	// move trough '0'
	// wall '1' as limit

	//check ffmap for any 0
	// all 0 and player pos should be F
	// done

//can str8 do the above no need check_wall
/* void ff_wall(t_game *game, char **ffmap, int x, int y)
{
	if ((y < 0 || y >= game->map.row) || \
		(x < 0 || x >= game->map.col))
	return ;
	if (ffmap[y][x] == '1')
	{
		ffmap[y][x] = 'F';
		ff_wall(game, ffmap, x + 1, y);
		ff_wall(game, ffmap, x - 1, y);
		ff_wall(game, ffmap, x , y + 1);
		ff_wall(game, ffmap, x , y - 1);
	}
	else
		return;
}

void validate_wall(t_game *game)
{
	int j;

	j = 0;
	while(game->map.xymap[0][j] != 0x00)
	{
		if(game->map.xymap[0][j] == '1' && 
			(game->map.xymap[1][j] == '1' || 
				game->map.xymap[0][j + 1] == '1'))
			break;
		j++;
	}
	ff_wall(game,game->map.ffmap, j, 0);
} */

void	check_shape(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = ft_strlen(game->map.xymap[0]);
	while (game->map.xymap[i] != 0x00)
	{
		k = ft_strlen(game->map.xymap[i]);
		if (j != k)
			ft_exit_error("Error: Wrong map shape\n");
		i++;
	}
	game->map.n_col = j;
}

int	check_map_char(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 1;
	while (game->map.xymap[++i] != 0x00)
	{
		j = 0;
		while (game->map.xymap[i][++j] != 0x00)
		{
			if (game->map.xymap[i][j] != ' ' &&
				game->map.xymap[i][j] != '0' && game->map.xymap[i][j] != '1' &&
				game->map.xymap[i][j] != 'N' && game->map.xymap[i][j] != 'S' &&
				game->map.xymap[i][j] != 'E' && game->map.xymap[i][j] != 'W')
				ft_exit_error("ERROR: invalid char in map\n");
			if (game->map.xymap[i][j] == 'N' || game->map.xymap[i][j] == 'S' ||
				game->map.xymap[i][j] == 'E' || game->map.xymap[i][j] == 'W')
			{
				k -= 1;
				game->player.p_dir = game->map.xymap[i][j];
			}
		}
	}
	return (k);
}

void	ft_check_map_char(t_game *game)
{
	if (check_map_char(game) != 0)
		ft_exit_error("ERROR\nmore than 1 player spawn location\n");
	check_shape(game);
}

/* NOTE
map do not take in '\t' only ' '
len on each row must be same filled by ' '
BECAUSE ' ' are valid part of map only ' ' 
SO
FF 1 outside to F
FF insdie 0 1 & N/S/E/W to X 
ft_exit if found ' ' or \t' on the inside
verify whole map only of have F & X  ' '*/