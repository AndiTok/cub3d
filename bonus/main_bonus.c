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

void	key_init(t_key *key)
{
	key->w = 0;
	key->a = 0;
	key->s = 0;
	key->d = 0;
}


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
	key_init(&game.key);
	ft_render(&game);
	ft_keypress(&game);
	mlx_loop(game.mlx);
}

// export DISPALY=[ipv4]:0.0 wihtout[]
// echo $DISPLAY to check
// xeyes to check
// gcc *.c -L minilibx/minilibx-linux -lmlx -lXext -lX11 -lm -lz && ./a.out maps/map.ber
// gcc -Wall -Werror -Wextra main.c raycaster/*.c utils/*.c parse_check/*c mlx/*.c gnl/*.c -L ../minilibx/minilibx-linux -lmlx -lXext -lX11 -lm -lz -fsanitize=address -g3  && ./a.out ../maps/w2020.cub

// gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit *.c  && ./a.out maps/minimalist.cub
// gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit *.c  -fsanitize=address -g3 && ./a.out maps/minimalist.cub

// gcc -Wall -Werror -Wextra main.c raycaster/*.c utils/*.c parse_check/*.c mlx/*.c gnl/*.c -L ../minilibx/minilibx-linux -lmlx -lXext -lX11 -lm -lz && ./a.out ../maps/w2020.cub
// gcc -Wall -Werror -Wextra main.c raycaster/*.c utils/*.c parse_check/*.c mlx/*.c gnl/*.c -L ../minilibx/minilibx-linux -lmlx -lXext -lX11 -lm -lz -fsanitize=address -g3 && ./a.out ../maps/w2020.cub

// run on mac:
// gcc -Wall -Werror -Wextra main_bonus.c raycaster/*.c utils/*.c parse_check/*.c mlx/*.c gnl/*.c -L ../minilibx/minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit && ./a.out ../maps/bonus.cub