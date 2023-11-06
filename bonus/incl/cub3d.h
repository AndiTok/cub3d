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

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
// # include "../../minilibx/minilibx-linux/mlx.h"
# include "../../minilibx/minilibx_opengl_20191021/mlx.h"
# include <string.h>
// #include <mlx.h>

//minimap
# define SCALE 16

//mlx dimension
# define WIN_WIDTH 1260
# define WIN_HEIGHT 720

//math //42 norm KO
// # define PI3 3*M_PI/2
// # define DEG M_PI / 180.00

//color
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xF7F731
# define PINK 0xFF00FF
# define BLACK 0x000000
# define GREY 0x828782
# define BROWN 0x964B00

// // keycode mac
# define W 13
# define A 0
# define S 1
# define D 2
# define E 14
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define L 37 // toggle map
# define M 46 // reserve form ouse

//keycode x11
// # define W 119
// # define A 97
// # define S 115
// # define D 100
// # define E 101
// # define ESC 65307
// # define LEFT 0xff51
// # define RIGHT 0xff53
// # define L 108
// # define M 109

/*
* px py: player position in xymap
* dir_x dir_y: player direction vector
* p_angle: player angle
* vx vy: end point of vertical cast ray
* hx hy: end point of horizontal cast ray
* dist_v dist_h: distance of vert/horiz ray
* dist_t: shorter ray between v/h ray (final)
* mx my: xymap index to compare with px py
* dof: depth of field (width/height of map)
* ra: ray angle
* rx ry: position of each ray (final)
* xo yo: ray offset
* line_h: wall height
* line_o: wall height offset
* fish: fisheye adjustment
*/
typedef struct s_raycast
{
	double	px;
	double	py;
	double	dir_x;
	double	dir_y;
	double	p_angle;
	double	dist_v;
	double	vx;
	double	vy;
	double	dist_h;
	double	hx;
	double	hy;
	double	dist_t;
	int		mx;
	int		my;
	int		dof;
	double	ra;
	double	rx;
	double	ry;
	double	xo;
	double	yo;
	double	line_h;
	double	line_o;
	double	fish;
}t_raycast;

typedef struct s_player
{
	double		x;
	double		y;
	int			color;
	char		p_dir;
}t_player;

/*bpp: bits per pixel*/
typedef struct s_img //
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/*final floor ceiling color hex stored here*/
typedef struct s_map
{
	char	**ffomap;
	char	**ffimap;
	char	**xymap;
	char	*map;
	int		floor;
	int		ceiling;
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	t_img	door[2];
	int		d;
	int		n_row;
	int		n_col;
}t_map;

/*final texture paths stored here */
typedef struct s_element
{
	char	*f;
	char	*c;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}t_element;

typedef struct s_file
{
	char	**xyfile;
	char	*file;
	int		lines;
	int		mid;
	int		f;
	int		c;
	int		no;
	int		so;
	int		we;
	int		ea;
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
	int			fps;
	int			mouse;
}t_game;

char	*ft_itoa(int n);
int		ft_atoi(char *str);
char	*ft_joinfree(char *str, char *tmpstr);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2);
void	ft_exit_error(char *str);

/*parsing*/
void	ft_check_input(int c, char **v);
void	ft_initialize_vars(t_game *game);
void	ft_load_file(t_game *game, char **v);
void	ft_split_store_file_element(t_game *game);
void	ft_check_store_rgb_element(t_game *game);
void	ft_check_store_xpm_element(t_game *game);
void	ft_store_map(t_game *game);
void	ft_check_map_char(t_game *game);
void	ft_dup_ffmap(t_game *game);
void	ft_check_stray_map(t_game *game);
void	ft_check_map_wall(t_game *game);
void	ft_check_map_hole(t_game *game);
void	ft_check_store_player(t_game *game);

/*mlx*/
void	ft_init_mlx(t_game *game);
void	draw_player(t_game *game);
void	draw_2dmap(t_game *game);
void	draw_line(t_game *game, int xe, int ye, int color);
void	ft_keypress(t_game *game);
void	rotation(int keycode, t_game game, t_raycast *ray);
void	ft_init_img(t_game *game);
void	img_pix_put(t_img *img, int x, int y, int color);
int		ft_render(t_game *game);
void	init_texture(t_game *game, t_map *map, t_element *elem);
int		ft_fps(t_game *game);
int		mouse_move(int x, int y, t_game *game);
void	toggle_cursor(t_game *game);
void	interact_door(t_game *game);
int		ft_end(t_game *game);

/*raycast + utils*/
void	ray_init(t_raycast *ray, t_player *player);
void	get_start_pa(t_raycast *ray, t_player *player);
void	dda(t_map *map, t_raycast *ray);
void	raycast(t_game *game, t_raycast *ray);
void	draw_wall(t_game *game, t_raycast *ray, int r, int color);
void	draw_xpm(t_game *game, t_raycast *ray, int r, int t);
double	ft_round(double val);
double	angle_reset(double angle);
void	fix_fisheye(t_raycast *ray);
void	limit_2dmap_index(t_map *map, t_raycast *ray);
int		set_dist_t_texture(t_map *map, t_raycast *ray);

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