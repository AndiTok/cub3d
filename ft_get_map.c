/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 03:41:40 by atok              #+#    #+#             */
/*   Updated: 2023/08/06 03:41:40 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	trim_map(t_game *game)
{
	int	i;
	int	eom;

	i = game->file.mid;
	eom = 0;
	while (game->file.xyfile[i] != 0x00)
	{
		if (game->file.xyfile[i][0] != 0x00)
			eom++;
		i++;
	}
	return (eom);
}

void	store_map(t_game *game)
{
	int		i;
	int		j;
	int		eom;
	int		max;
	char	**tmp;

	i = game->file.mid;
	eom = trim_map(game);
	max = game->file.mid + eom;
	tmp = (char **)malloc(sizeof (char *) * (eom + 1));
	j = 0;
	while (i < max)
	{
		tmp[j] = ft_strdup(game->file.xyfile[i]);
		game->map.n_row++;
		j++;
		i++;
	}
	tmp[j] = 0x00;
	game->map.xymap = tmp;
	//game->map.ffmap = tmp; // will link
}

void	ft_get_map(t_game *game)
{
	store_map(game);
}
