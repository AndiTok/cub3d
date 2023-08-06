/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 03:12:26 by atok              #+#    #+#             */
/*   Updated: 2023/08/06 03:12:26 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ff_map(t_game *game, char **ffmap, int x, int y)
{
	if ((y < 0 || y >= game->map.n_row) || \
		(x < 0 || x >= game->map.n_col))
		return ;
	if (ffmap[y][x] == '1' || ffmap[y][x] == '0' ||
		ffmap[y][x] == 'N' || ffmap[y][x] == 'S' ||
		ffmap[y][x] == 'E' || ffmap[y][x] == 'W')
	{
		ffmap[y][x] = 'F';
		ff_map(game, ffmap, x + 1, y);
		ff_map(game, ffmap, x - 1, y);
		ff_map(game, ffmap, x, y + 1);
		ff_map(game, ffmap, x, y - 1);
	}
	else
		return ;
}

void	verify_ff(t_game *game)
{
	int	i;
	int	j;

	// i = 0;
	// while(game->map.ffmap[i] != 0x00)
	// 	printf("%s\n",game->map.ffmap[i++]);
	// i = 0;
	// while(game->map.xymap[i] != 0x00)
	// 	printf("%s\n",game->map.xymap[i++]);
	i = 0;
	while (game->map.ffmap[i] != 0x00)
	{
		j = 0;
		while (game->map.ffmap[i][j] != 0x00)
		{
			if (game->map.ffmap[i][j] == ' ' || game->map.ffmap[i][j] == 'F')
				j++;
			else
				ft_exit_error("Error\nstray map found\n");
		}
		i++;
	}
}

void	check_stray(t_game *game)
{
	int	j;

	j = 0;
	while (game->map.ffmap[0][j] != 0x00)
	{
		if (game->map.ffmap[0][j] == '1')
			break ;
		j++;
	}
	ff_map(game, game->map.ffmap, j, 0);
	verify_ff(game);
}

void	dup_map(t_game *game)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = (char **)malloc(sizeof(char *) * (game->map.n_row + 1));
	while (i < game->map.n_row)
	{
		tmp[j] = ft_strdup(game->map.xymap[i]);
		j++;
		i++;
	}
	tmp[j] = 0x00;
	game->map.ffmap = tmp;
}

void	ft_check_stray_map(t_game *game)
{
	// printf("row -%d\n",game->map.n_row);
	// printf("col -%d\n",game->map.n_col);
		// int i = 0;
		// while(game->map.xymap[i] != 0x00)
		// {
		// 	printf("%s\n", game->map.xymap[i]);
		// 	i++;
		// }
		// printf("%d\n",i); 
	dup_map(game);
	check_stray(game);
}
