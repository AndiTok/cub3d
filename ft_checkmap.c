/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:23:01 by atok              #+#    #+#             */
/*   Updated: 2023/08/03 19:55:42 by atok             ###   ########.fr       */
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
void check_wall(t_game *game)
{
	//check x axis < > for wall
	// then check y axis /\ \/ for wall
}

void check_char(t_game *game)
{
	int i;
	int j;
	//each line has null BUT NO "\n"
	i = 0;

	int k = 0;
	int l = 0;
	
	while(game->map.xymap[i] != 0x00)
	{
		j = 0;
		while(game->map.xymap[i][j] != 0x00)
		{
			// printf("%c",game->map.xymap[i][j]);
			// write(1,&game->map.xymap[i][j],1);
			if(game->map.xymap[i][j] == '0' || game->map.xymap[i][j] == '1' ||
				game->map.xymap[i][j] == ' ' || game->map.xymap[i][j] == '\t' ||
				game->map.xymap[i][j] == '\n') // handle '\n' since in 2d no nl
				k++;
			else if(game->map.xymap[i][j] == 'N' || game->map.xymap[i][j] == 'S' ||
				game->map.xymap[i][j] == 'E' || game->map.xymap[i][j] == 'W')
				l++;
			else 
				ft_exit_error("ERROR\nmap\n");
			j++;
		}
		i++;
	}
	// printf("%d\n",k);
	// printf("%d\n",l);
}
// 13 is last
void ft_check_map(t_game *game)
{
	// int i = 0;
	// int j = 0;
	// int k = 0;
	// while(game->map.xymap[i] != 0x00)
	// {
	// 	k = ft_strlen(game->map.xymap[i]);
	// 	printf("%d\n",k);
	// 	j = k + j;
	// 	//printf("%s\n",game->map.xymap[i]);
	// 	//write(1,&game->map.xymap[i][j],1);
	// 	//printf("%c",game->map.xymap[i][j]);
	// 	i++;
	// }
	// printf("%d\n",j);
	// printf("\n");
	// write(1, "\n", 1);
	check_char(game);
	check_wall(game);
}