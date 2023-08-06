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

#include "cub3d.h"

char	*bstrdup(t_game *game)
{
	char	*str;
	char	*dup;
	int		i;
	int		len;

	len = game->map.n_col;
	dup = (char *) malloc(sizeof(char) * (len + 3));
	dup[len + 2] = 0x00;;
	i = 0;
	while (dup[i] != 0x00)
	{
		dup[i] = ' ';
		i++;
	}
	dup[i] = 0x00;
	return (dup);
}

char	*mstrdup(char *src)
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
	tmp[j++] = bstrdup(game); // a row of ' ' for top
	while (i < game->map.n_row)
	{
		tmp[j] = mstrdup(game->map.xymap[i]); //include ' ' for < & >
		j++;
		i++;
	}
	//printf("here-%d\n", j);
	tmp[j++] = bstrdup(game); // a row of ' ' for bottum
	tmp[j] = 0x00;
	return (tmp);
	//game->map.ffmap = tmp;
}

void ft_dup_ffmap(t_game *game)
{
	game->map.ffomap = dup_map(game);
	game->map.ffimap = dup_map(game);
	// int i = 0;
	// while(game->map.ffimap[i] != 0x00)
	// 	printf("%s\n",game->map.ffimap[i++]);
}