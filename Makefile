NAME = cub3d
# BONUS = cub3d_bonus

SRC = ft_atoi.c ft_check_input.c ft_check_store_rgb_element.c ft_check_store_xpm_element.c\
	ft_exit_error.c ft_init_mlx.c ft_initialize_vars.c ft_itoa.c ft_joinfree.c\
	ft_keypress.c ft_load_file.c ft_split_store_file_info.c ft_split.c ft_strncmp.c ft_strnstr.c\
	get_next_line_utils.c get_next_line.c #ft_checkmap.c
OBJ = $(SRC:.c=.o)

MLX_PATH = minilibx/minilibx-linux/
MLX = -L $(MLX_PATH) -lmlx -lXext -lX11

GCC = gcc
RM = rm -rf
CFLAGS += -Wall -Werror -Wextra
FSAN = -fsanitize=address -g3

.PHONY = all clean fclean re debug

$(NAME): $(OBJ)
	$(GCC) $(CFLAGS) $(MLX) $(OBJ) -o $(NAME)

all: $(NAME)

# $(BONUS): $(BONUS_OBJ)
# $(GCC) $(CFLAGS) $(MLX) $(OBJ) -o $(NAME)

# bonus: $(BONUS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug:
	$(GCC) $(CFLAGS) $(FSAN) $(MLX) $(OBJ) -o $(NAME)

