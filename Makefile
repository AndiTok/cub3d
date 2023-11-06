# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 14:48:51 by wyap              #+#    #+#              #
#    Updated: 2023/10/31 14:48:51 by wyap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
BONUS = cub3d_bonus

SRC_DIR = mandatory/
SRC = parse_check/ft_check_input.c parse_check/ft_check_map_char.c\
		parse_check/ft_check_map_hole.c parse_check/ft_check_map_wall.c\
		parse_check/ft_check_store_player.c\
		parse_check/ft_check_store_rgb_element.c parse_check/ft_load_file.c\
		parse_check/ft_check_store_xpm_element.c parse_check/ft_check_stray_map.c\
		parse_check/ft_dup_ffmap.c parse_check/ft_get_map.c\
		parse_check/ft_initialize_vars.c parse_check/ft_split_store_file_element.c\
		raycaster/raycast.c raycaster/ray_init.c raycaster/raycast_utils.c\
		raycaster/dda.c raycaster/draw_wall.c mlx/rotation.c\
		gnl/get_next_line.c gnl/get_next_line_utils.c mlx/ft_init_mlx.c\
		mlx/ft_init_img.c mlx/ft_draw.c mlx/init_texture.c mlx/ft_render.c\
		mlx/ft_keypress.c utils/ft_atoi.c utils/ft_exit_error.c utils/ft_itoa.c\
		utils/ft_joinfree.c utils/ft_split.c utils/ft_strncmp.c utils/ft_strnstr.c main.c

BONUS_DIR = bonus/
BONUS_SRC = parse_check/ft_check_input.c parse_check/ft_check_map_char.c\
		parse_check/ft_check_map_hole.c parse_check/ft_check_map_wall.c\
		parse_check/ft_check_store_player.c\
		parse_check/ft_check_store_rgb_element.c parse_check/ft_load_file.c\
		parse_check/ft_check_store_xpm_element.c parse_check/ft_check_stray_map.c\
		parse_check/ft_dup_ffmap.c parse_check/ft_get_map.c\
		parse_check/ft_initialize_vars.c parse_check/ft_split_store_file_element.c\
		raycaster/raycast.c raycaster/ray_init.c raycaster/raycast_utils.c\
		raycaster/dda.c raycaster/draw_wall.c mlx/rotation.c mlx/other_events.c\
		gnl/get_next_line.c gnl/get_next_line_utils.c mlx/ft_init_mlx.c\
		mlx/ft_init_img.c mlx/ft_draw.c mlx/init_texture.c mlx/ft_render.c\
		mlx/ft_keypress_bonus.c mlx/ft_fps.c utils/ft_atoi.c utils/ft_exit_error.c utils/ft_itoa.c\
		utils/ft_joinfree.c utils/ft_split.c utils/ft_strncmp.c utils/ft_strnstr.c main_bonus.c

OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))
BONUS_OBJ =  $(addprefix $(BONUS_DIR), $(BONUS_SRC:.c=.o))

GCC = gcc
INCL = -I ./incl
CFLAGS += -Wall -Werror -Wextra $(INCL)
FSAN = -fsanitize=address -g3
RM = rm -rf

MLX_FLAG_MAC = -L minilibx/minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit
MLX_FLAG_WIN = -L minilibx/minilibx-linux -lmlx -lXext -lX11 -lm -lz

.PHONY = all clean fclean re

$(NAME): $(OBJ)
	@echo " "
	@echo compiling make...
	$(GCC) $(CFLAGS) $(OBJ) $(MLX_FLAG_MAC) -o $(NAME)
	@echo " "

m: $(NAME)

$(BONUS): $(BONUS_OBJ)
	@echo " "
	@echo compiling bonus...
	$(GCC) $(CFLAGS) $(BONUS_OBJ) $(MLX_FLAG_MAC) -o $(BONUS)
	@echo " "

bonus: $(BONUS)

all: $(NAME) $(BONUS)
	@echo "*"   compiled all  "*"

clean:
	@echo " "
	@echo cleaning...
	$(RM) $(OBJ)
	@echo " "
	$(RM) $(BONUS_OBJ)
	@echo " "
	@echo "*" cleaned objects "*"

fclean: clean
	@echo " "
	@echo cleaning executable and dSYM...
	$(RM) $(NAME) $(BONUS) $(NAME)_debug $(BONUS)_debug
	@ $(RM) *.dSYM
	@echo " "
	@echo "*" cleaned target  "*"
	@echo " "


re: fclean all
	@echo "*" recompiled all "*"

debug: $(OBJ)
	@echo compiling with debug flags...
	$(GCC) $(CFLAGS) $(MLX_FLAG_MAC) $(FSAN) $(OBJ) -o $(NAME)_debug
	@echo " "
	$(GCC) $(CFLAGS) $(MLX_FLAG_MAC) $(FSAN) $(BONUS_OBJ) -o $(BONUS)_debug
	@echo " "
	@echo "*" compiled debug  "*"