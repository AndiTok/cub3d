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

#include "cub3d.h"

int main(int c, char **v)
{
	t_game game;

 	game.player.x = 100; // X-coordinate of the dot
	game.player.y = 50;  // Y-coordinate of the dot
    game.player.color = 0xFF00FF; // 0x-Hex 00-R 00-G 00-B
    // game.player.color = 65535; // 
    //game.player.color = (0 << 16) | (255 << 8) | 255; 
	
	ft_check_input(c, v);
	ft_initialize_vars(&game);
	ft_load_file(&game, v); // free tmp
	ft_split_store_file_element(&game);
	ft_check_store_rgb_element(&game);
	ft_check_store_xpm_element(&game);
	ft_get_map(&game); // maybe add a feature to cube the map at > dont hvae ' '
	ft_check_map_char(&game);
	ft_dup_ffmap(&game); // rmb to free after use
	ft_check_stray_map(&game); // may not need
	ft_check_map_wall(&game);
	// ft_check_map_hole(&game);
	ft_check_store_player(&game);
		printf("n_row: %d\nn_col: %d\n", game.map.n_row, game.map.n_col);
	ft_init_mlx(&game);
	ray_init(&game.ray, &game.player);
	ft_keypress(&game);
	mlx_loop(game.mlx);
}

// export DISPALY=[ipv4]:0.0 wihtout[]
// echo $DISPLAY to check
// gcc *.c -L minilibx/minilibx-linux -lmlx -lXext -lX11 -lm -lz && ./a.out maps/map.ber
// gcc *.c raycaster/*.c -L minilibx/minilibx-linux -lmlx -lXext -lX11 -lm -lz -fsanitize=address -g3  && ./a.out minimalist.cub 
// gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit *.c  && ./a.out minimalist.cub
// gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit *.c  -fsanitize=address -g3 && ./a.out minimalist.cub