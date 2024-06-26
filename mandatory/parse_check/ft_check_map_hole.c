/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_hole.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:36:38 by atok              #+#    #+#             */
/*   Updated: 2023/08/06 09:36:38 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	ft_check_map_hole(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.ffomap[i] != 0x00)
	{
		j = 0;
		while (game->map.ffomap[i][j] != 0x00)
		{
			if (game->map.ffomap[i][j] == ' ')
			{
				printf("on [%d][%d]\n", i - 1, j - 1);
				ft_exit_error("Error: hole in map\n");
			}
			j++;
		}
		i++;
	}
}
	/*show map*/
	//	int	i;
	// i = 0;
	// while (game->map.xymap[i] != 0x00)
	// 	printf("%s\n", game->map.xymap[i++]);
	// printf("%d\n", i);