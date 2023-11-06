/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:08:50 by atok              #+#    #+#             */
/*   Updated: 2023/07/28 18:08:50 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/cub3d.h"

int	main(int c, char **v)
{
	t_game	game;

	game.player.color = PINK;
	ft_check_input(c, v);
	ft_initialize_vars(&game);
	ft_load_file(&game, v);
	ft_split_store_file_element(&game);
	ft_check_store_rgb_element(&game);
	ft_check_store_xpm_element(&game);
	ft_store_map(&game);
	ft_check_map_char(&game);
	ft_dup_ffmap(&game);
	ft_check_store_player(&game);
	ft_check_stray_map(&game);
	ft_check_map_wall(&game);
	ft_check_map_hole(&game);
	ft_init_mlx(&game);
	init_texture(&game, &game.map, &game.element);
	ft_init_img(&game);
	ray_init(&game.ray, &game.player);
	ft_render(&game);
	ft_keypress(&game);
	mouse_move(631, 0, &game);
	mlx_mouse_hide();
	mlx_loop(game.mlx);
}
