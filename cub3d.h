/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:09:02 by atok              #+#    #+#             */
/*   Updated: 2023/07/28 18:09:02 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>//
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "minilibx/minilibx-linux/mlx.h"
#include <string.h>//
//#include <mlx.h>

//minimap
#define TILESCALE 16

//math
#define PI 3.141592
#define PI_HALF PI/2
#define PI3 3*PI/2

//keycode mac
#define W 13
#define A 0
#define S 1
#define D 2
#define ESC 53
#define LEFT 123
#define RIGHT 124

//keycode x11
// #define W 119
// #define A 97
// #define S 115
// #define D 100
// #define ESC 65307
// #define LEFT 0xff51
// #define RIGHT 0xff53

typedef struct s_raycast
{
	double	px;
	double	py;
	int		map_x;
	int		map_y;
	double	dir_x; //direction vector, value may change on each keypress
	double	dir_y;	//direction vector, value may change on each keypress
	double	plane_x;
	double	plane_y;
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_x; //delta distance
	double	delta_y; //delta distance
	double	side_x; //side distance
	double	side_y; //side distance
	double	wall_dist; //distance from position to wall hit
	double	p_angle; //player angle

	//DDA: calculate step (amount of steps to hit a grid)
	int		step_x;
	int		step_y;
	int		side; //to check NS or EW wall hit

}t_raycast;

typedef struct s_player
{
	double		x;
	double		y;
	int 		color;
	char		p_dir;
}t_player;

typedef struct s_map
{
	//char	**ffmap;
	char	**ffomap;
	char	**ffimap;
	char	**xymap;
	char	*map;//
	int		floor; // final
	int		ceiling; // final
	int		n_row;
	int 	n_col;
}t_map;

typedef struct s_element
{
	char 	*F;
	char	*C;
	char	*NO; // final
	char	*SO; // final
	char	*WE; // final
	char	*EA; // final
}t_element;

typedef struct s_file
{
	char	**xyfile;
	char	*file;
	int		lines;
	int		mid;
	int		F;
	int		C;
	int		NO;
	int		SO;
	int		WE;
	int		EA;
}t_file;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	double		win_width;
	double		win_height;
	t_player	player;
	t_file		file;
	t_map		map;
	t_element 	element;
	t_raycast	ray;
}t_game;

char	*ft_itoa(int n);
int		ft_atoi(char *str);
char	*ft_joinfree(char *str, char *tmpstr);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2);
void	ft_exit_error(char *str);

void	ft_check_input(int c, char **v);
void	ft_initialize_vars(t_game *game);
void	ft_load_file(t_game *game, char **v);
void	ft_split_store_file_element(t_game *game);
void	ft_check_store_rgb_element(t_game *game);
void	ft_check_store_xpm_element(t_game *game);
void	ft_get_map(t_game *game);
void	ft_check_map_char(t_game *game);
void	ft_dup_ffmap(t_game *game);
void	ft_check_stray_map(t_game *game);
void	ft_check_map_wall(t_game *game);
void	ft_check_map_hole(t_game *game);
void	ft_check_store_player(t_game *game);
void	ft_init_mlx(t_game *game);
void	draw_dot(t_game *game);
void	ft_keypress(t_game *game);
void	rotation(int keycode, t_raycast ray);

//GNL + utils
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);

#endif

		// j = 0;
		// char *tmp = ft_strdup("");
		// while(i < game->file.lines)
		// {
		// 	//ft_strdup(game->file.xyfile[i]);
		// 	tmp = ft_joinfree(tmp,game->file.xyfile[i]);
		// 	//printf("%s\n",tmp[j]);
		// 	j++;
		// 	i++;
		// }
		// game->map.xymap = ft_split(tmp,'\n');;