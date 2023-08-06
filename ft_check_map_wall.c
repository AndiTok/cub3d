/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 02:17:52 by atok              #+#    #+#             */
/*   Updated: 2023/08/06 02:17:52 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_top_wall(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map.n_col)
	{
		i = 0;
		while (game->map.xymap[i][j] == ' ')
			i++;
		if (game->map.xymap[i][j] == '1')
			j++;
		else 
			ft_exit_error("Error\nmissing /\\ wall\n");
	}
}

void	check_bottum_wall(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map.n_col)
	{
		i = game->map.n_row - 1;
		while (game->map.xymap[i][j] == ' ')
			i--;
		if (game->map.xymap[i][j] == '1')
			j++;
		else 
			ft_exit_error("Error\nmissing \\/ wall\n");
	}
}

void	check_left_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.xymap[i] != 0x00)
	{
		j = 0;
		while (game->map.xymap[i][j] == ' ')
			j++;
		if (game->map.xymap[i][j] == '1')
			i++;
		else 
			ft_exit_error("Error\nmissing < wall\n");
	}
}

void	check_right_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.xymap[i] != 0x00)
	{
		j = ft_strlen(game->map.xymap[i]) - 1;
		while (game->map.xymap[i][j] == ' ')
			j--;
		if (game->map.xymap[i][j] == '1')
			i++;
		else 
			ft_exit_error("Error\nmissing > wall\n");
	}
}

void	ft_check_map_wall(t_game *game)
{
	check_left_wall(game);
	check_right_wall(game);
	check_top_wall(game);
	check_bottum_wall(game);
}
