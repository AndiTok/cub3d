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
# include <string.h>//
//#include <mlx.h>

//minimap
# define SCALE 16

//mlx dimension
# define WIN_WIDTH 1260
# define WIN_HEIGHT 720

//math
# define PI3 3*M_PI/2
# define DEG M_PI/180.00

//color
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x00FFFF
# define YELLOW 0xF7F731


// // keycode mac
// # define W 13
// # define A 0
// # define S 1
// # define D 2
// # define ESC 53
// # define LEFT 123
// # define RIGHT 124
// # define L 37 // toggle map
// # define M 46 // reserve form ouse

//keycode x11
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define LEFT 0xff51
# define RIGHT 0xff53
# define L 108
# define M 109

typedef struct s_raycast
{
	double	px; //player position in xymap
	double	py;
	double	dir_x; //player dir vector
	double	dir_y; //player dir vector
	double	p_angle; //player angle

	double	dist_v;
	double	vx;
	double	vy;
	double	dist_h;
	double	hx;
	double	hy;
	double	dist_t; //finalized line distance

	int		mx; //map index to compare with player position
	int		my;
	int		dof; //depth of field (width/height of map)
	double	ra; //ray angle
	double	rx; //ray position
	double	ry;
	double	xo; //x offset
	double	yo; //y offset

	double	line_h; //wall line height
	double	line_o; //wall line offset
	double	fish; //fisheye fix

} t_raycast;

typedef struct s_player
{
	double		x;
	double		y;
	int			color;
	char		p_dir;
}t_player;

typedef struct s_img //
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	//char	**ffmap;
	char	**ffomap;
	char	**ffimap;
	char	**xymap;
	char	*map;//
	int		floor; // final
	int		ceiling; // final
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
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
	t_element	element;
	t_raycast	ray;
	t_img		img;
	int			toggle_m;
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
void	draw_player(t_game *game);
void	draw_2dmap(t_game *game);
void	draw_line(t_game *game, int xe, int ye, int color);
void	ft_keypress(t_game *game);
void	rotation(int keycode, t_game game,t_raycast *ray);
// new
void	ft_init_img(t_game *game); //
void	img_pix_put(t_img *img, int x, int y, int color); //
int		ft_render(t_game *game); //
void	init_texture(t_game *game, t_map *map, t_element *elem);


//raycast
void	ray_init(t_raycast *ray, t_player *player);
void	get_start_pa(t_raycast *ray, t_player *player);
void	raycast(t_game *game, t_raycast *ray);
void	draw_wall(t_game *game, t_raycast *ray, int r, int color);
void	draw_texture(t_game *game, t_raycast *ray, int r);
void	draw_xpm(t_game *game, t_raycast *ray, int r, int t);

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