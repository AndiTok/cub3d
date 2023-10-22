/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:43:32 by wyap              #+#    #+#             */
/*   Updated: 2023/10/22 18:09:06 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_texture(t_game *game, t_map *map, t_element *elem)
{
	int	i;
	int	j;

	map->north.mlx_img = mlx_xpm_file_to_image(game->mlx, elem->NO, &i, &j);
	if (!map->north.mlx_img)
		ft_exit_error("north texture not loaded");
	map->north.addr = mlx_get_data_addr(map->north.mlx_img,
			&map->north.bpp, &map->north.line_len, &map->north.endian);

	map->south.mlx_img = mlx_xpm_file_to_image(game->mlx, elem->SO, &i, &j);
	if (!map->south.mlx_img)
		ft_exit_error("south texture not loaded");
	map->south.addr = mlx_get_data_addr(map->south.mlx_img,
			&map->south.bpp, &map->south.line_len, &map->south.endian);

	map->east.mlx_img = mlx_xpm_file_to_image(game->mlx, elem->EA, &i, &j);
	if (!map->east.mlx_img)
		ft_exit_error("east texture not loaded");
	map->east.addr = mlx_get_data_addr(map->east.mlx_img,
			&map->east.bpp, &map->east.line_len, &map->east.endian);

	map->west.mlx_img = mlx_xpm_file_to_image(game->mlx, elem->WE, &i, &j);
	if (!map->west.mlx_img)
		ft_exit_error("west texture not loaded");
	map->west.addr = mlx_get_data_addr(map->west.mlx_img,
			&map->west.bpp, &map->west.line_len, &map->west.endian);

	// printf("textures loaded");
	return (0);
}
