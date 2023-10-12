/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:43:32 by wyap              #+#    #+#             */
/*   Updated: 2023/10/12 16:07:07 by wyap             ###   ########.fr       */
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
	map->south.mlx_img = mlx_xpm_file_to_image(game->mlx, elem->SO, &i, &j);
	if (!map->south.mlx_img)
		ft_exit_error("south texture not loaded");
	map->east.mlx_img = mlx_xpm_file_to_image(game->mlx, elem->EA, &i, &j);
	if (!map->east.mlx_img)
		ft_exit_error("east texture not loaded");
	map->west.mlx_img = mlx_xpm_file_to_image(game->mlx, elem->WE, &i, &j);
	if (!map->west.mlx_img)
		ft_exit_error("west texture not loaded");
	// printf("textures loaded");
	return (0);
}
