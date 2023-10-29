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

//Oct 28: not sure if still required
void	check_player_pos(char **map, int x, int y)
{
	if (map[y - 1][x] != '0' && map[y - 1][x] != '1')
		ft_exit_error("Error: player out of bound\n");
	if (map[y + 1][x] != '0' && map[y + 1][x] != '1')
		ft_exit_error("Error: player out of bound\n");
	if (map[y][x - 1] != '0' && map[y][x - 1] != '1')
		ft_exit_error("Error: player out of bound\n");
	if (map[y][x + 1] != '0' && map[y][x + 1] != '1')
		ft_exit_error("Error: player out of bound\n");
}


/*player x and y - 8 to center the dot*/
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
				game->player.x = (double)j * SCALE - 8;
				game->player.y = (double)i * SCALE - 8;
			}
			j++;
		}
		i++;
	}
}

void	get_start_pa(t_raycast *ray, t_player *player)
{
	if (player->p_dir == 'N')
		ray->p_angle = PI3;
	if (player->p_dir == 'S')
		ray->p_angle = M_PI_2;
	if (player->p_dir == 'E')
		ray->p_angle = 0;
	if (player->p_dir == 'W')
		ray->p_angle = M_PI;
}

void	ft_check_store_player(t_game *game)
{
	get_player_pos(game);
	check_player_pos(game->map.xymap, game->player.x / SCALE,
		game->player.y / SCALE);
	// /\ may not need to check 
	// REASON-can modify ff wall check to check,not required,saves alot time & problem
	// get_player_angle(game);
}
