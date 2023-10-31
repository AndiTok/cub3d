/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_ffmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:03:45 by atok              #+#    #+#             */
/*   Updated: 2023/08/06 14:03:45 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

/*
* add a row of whitespace on top & bot of map body
* to set up for floodfill
*/
char	*add_row_padding(t_game *game)
{
	char	*dup;
	int		i;
	int		len;

	len = game->map.n_col;
	dup = (char *) malloc(sizeof(char) * (len + 3));
	dup[len + 2] = 0x00;
	i = 0;
	while (dup[i] != 0x00)
	{
		dup[i] = ' ';
		i++;
	}
	dup[i] = 0x00;
	return (dup);
}

/*
* add a column of whitespace on left & right of map body
* to set up for floodfill
*/
char	*left_right_padding(char *src)
{
	char	*dup;
	int		i;
	int		j;
	int		len;

	len = 0;
	while (src[len])
		len++;
	dup = (char *) malloc(sizeof(char) * (len + 3));
	if (dup == (NULL))
		return (NULL);
	i = 0;
	j = 0;
	dup[i++] = ' ';
	while (src[j])
	{
		dup[i] = src[j];
		i++;
		j++;
	}
	dup[i++] = ' ';
	dup[i] = 0x00;
	return (dup);
}

char	**dup_map(t_game *game)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = (char **)malloc(sizeof(char *) * (game->map.n_row + 3));
	tmp[j++] = add_row_padding(game);
	while (i < game->map.n_row)
	{
		tmp[j] = left_right_padding(game->map.xymap[i]);
		j++;
		i++;
	}
	tmp[j++] = add_row_padding(game);
	tmp[j] = 0x00;
	return (tmp);
}

void	ft_dup_ffmap(t_game *game)
{
	game->map.ffomap = dup_map(game);
	game->map.ffimap = dup_map(game);
}
