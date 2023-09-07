/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 03:28:30 by atok              #+#    #+#             */
/*   Updated: 2023/08/06 03:28:30 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_player_pos(char **map, int x, int y)
{
	if (map[y - 1][x] != '0' && map[y - 1][x] != '1')
		ft_exit_error("Error\nplayer out of bound\n");
	if (map[y + 1][x] != '0' && map[y + 1][x] != '1')
		ft_exit_error("Error\nplayer out of bound\n");
	if (map[y][x - 1] != '0' && map[y][x - 1] != '1')
		ft_exit_error("Error\nplayer out of bound\n");
	if (map[y][x + 1] != '0' && map[y][x + 1] != '1')
		ft_exit_error("Error\nplayer out of bound\n");
}

void	get_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.xymap[i] != 0x00)
	{
		j = 0;
		while (game->map.xymap[i][j] != 0x00)
		{
			if (game->map.xymap[i][j] == 'N' || game->map.xymap[i][j] == 'S' ||
				game->map.xymap[i][j] == 'E' || game->map.xymap[i][j] == 'W')
			{
				game->player.x = (double)j * TILESCALE;
				game->player.y = (double)i * TILESCALE;
			}
			j++;
		}
		i++;
	}
}

// void get_player_angle(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (game->map.xymap[i] != 0x00)
// 	{
// 		j = 0;
// 		while (game->map.xymap[i][j] != 0x00)
// 		{
// 			if (game->map.xymap[i][j] == 'N')
// 				game->ray.p_angle = PI_HALF;
// 			if (game->map.xymap[i][j] == 'S')
// 				game->ray.p_angle = PI3;
// 			if (game->map.xymap[i][j] == 'E')
// 				game->ray.p_angle = 0;
// 			if (game->map.xymap[i][j] == 'W')
// 				game->ray.p_angle = PI;
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	ft_check_store_player(t_game *game)
{
		// int i = 0;
		// while (game->map.xymap[i] != 0x00)
		// {
		// 	printf("%s\n",game->map.xymap[i]);
		// 	i++;
		// }
	get_player_pos(game);
	// printf("x - %f y - %f\n", game->player.x , game->player.y);

	check_player_pos(game->map.xymap,game->player.x/TILESCALE
		,game->player.y/TILESCALE);
	// /\ may not need to check 
	// REASON-can modify ff wall check to check,not required,saves alot time & problem
	// get_player_angle(game);
}
