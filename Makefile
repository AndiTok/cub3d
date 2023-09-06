NAME = cub3d

SRC_DIR = ./src/
SRC = 
OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))

GCC = gcc
INCL = -I ./incl
CFLAGS += -Wall -Werror -Wextra
FSAN = -fsanitize=address -g3
RM = rm -rf

MLX_FLAG_MAC = -lmlx -framework OpenGL -framework AppKit
MLX_FLAG_WIN = -L minilibx/minilibx-linux -mlx -lXext -lX11 -lm -lz

.PHONY = all clean fclean re

$(NAME): $(OBJ)
	@echo compiling make...
	$(GCC) $(CFLAGS) $(MLX_FLAG_MAC) $(OBJ) -o $(NAME)
	
all: $(NAME)
	@echo compiling all...

clean:
	@echo cleaning...
	$(RM) $(OBJ)

fclean: clean
	@echo cleaning executable and dSYM...
	$(RM) $(NAME)
	@ $(RM) *.dSYM

re: fclean all
	@echo recompiling...

debug: $(OBJ)
	@echo compiling with debug flags...
	$(GCC) $(CFLAGS) $(MLX_FLAG_MAC) $(FSAN) $(OBJ) -o $(NAME)
