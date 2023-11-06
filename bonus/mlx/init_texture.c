/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:43:32 by wyap              #+#    #+#             */
/*   Updated: 2023/11/06 17:33:59 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	init_door(t_game *game, t_map *map)
{
	int	i;
	int	j;

	map->door[0].mlx_img = mlx_xpm_file_to_image(game->mlx,
			"./texture/doora.xpm", &i, &j);
	if (!map->door[0].mlx_img)
		ft_exit_error("doora texture not loaded\n");
	map->door[0].addr = mlx_get_data_addr(map->door[0].mlx_img,
			&map->door[0].bpp, &map->door[0].line_len, &map->door[0].endian);
	map->door[1].mlx_img = mlx_xpm_file_to_image(game->mlx,
			"./texture/doorb.xpm", &i, &j);
	if (!map->door[1].mlx_img)
		ft_exit_error("doorb texture not loaded\n");
	map->door[1].addr = mlx_get_data_addr(map->door[1].mlx_img,
			&map->door[1].bpp, &map->door[1].line_len, &map->door[1].endian);
	return ;
}

void	init_texture(t_game *game, t_map *map, t_element *elem)
{
	int	i;
	int	j;

	map->north.mlx_img = mlx_xpm_file_to_image(game->mlx, elem->no, &i, &j);
	if (!map->north.mlx_img)
		ft_exit_error("north texture not loaded\n");
	map->north.addr = mlx_get_data_addr(map->north.mlx_img,
			&map->north.bpp, &map->north.line_len, &map->north.endian);
	map->south.mlx_img = mlx_xpm_file_to_image(game->mlx, elem->so, &i, &j);
	if (!map->south.mlx_img)
		ft_exit_error("south texture not loaded\n");
	map->south.addr = mlx_get_data_addr(map->south.mlx_img,
			&map->south.bpp, &map->south.line_len, &map->south.endian);
	map->east.mlx_img = mlx_xpm_file_to_image(game->mlx, elem->ea, &i, &j);
	if (!map->east.mlx_img)
		ft_exit_error("east texture not loaded\n");
	map->east.addr = mlx_get_data_addr(map->east.mlx_img,
			&map->east.bpp, &map->east.line_len, &map->east.endian);
	map->west.mlx_img = mlx_xpm_file_to_image(game->mlx, elem->we, &i, &j);
	if (!map->west.mlx_img)
		ft_exit_error("west texture not loaded\n");
	map->west.addr = mlx_get_data_addr(map->west.mlx_img,
			&map->west.bpp, &map->west.line_len, &map->west.endian);
	init_door(game, map);
	return ;
}
