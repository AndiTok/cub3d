/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:23:01 by atok              #+#    #+#             */
/*   Updated: 2023/08/01 18:02:23 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_char(t_game *game)
{
	int i;
	int j;

	i = 0;
	while(game->map.xymap[i][j] != 0x00)
	{
		// printf("%s",game->map.xymap[i]);
		j = 0;
		while(game->map.xymap[i][j] != 0x00)
		{
			if(game->map.xymap[i][j] == '0' || game->map.xymap[i][j] == '1')
				j++;
			else if(game->map.xymap[i][j] == 'N' || game->map.xymap[i][j] == 'S' ||
				game->map.xymap[i][j] == 'E' || game->map.xymap[i][j] == 'W')
				j++;
			else 
				ft_exit_error("ERROR\n map\n");
			j++;
		}
		i++;
	}
}
// 13 is last
void ft_check_map(t_game *game)
{
	int i = 0;
	int j = 0;
	while(game->map.xymap[i] != 0x00)
	{
		printf("%s\n",game->map.xymap[i]);
		//write(1,&game->map.xymap[i][j],1);
		//printf("%c",game->map.xymap[i][j]);
		i++;
	}
	printf("\n");
	// write(1, "\n", 1);

	// check_char(game);
}