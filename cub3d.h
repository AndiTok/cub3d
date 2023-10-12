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
#define SCALE 16

//math
#define PI3 3*M_PI/2
#define DEG M_PI/180.00

// keycode mac
#define W 13
#define A 0
#define S 1
#define D 2
#define ESC 53
#define LEFT 123
#define RIGHT 124

// //keycode x11
// #define W 119
// #define A 97
// #define S 115
// #define D 100
// #define ESC 65307
// #define LEFT 0xff51
// #define RIGHT 0xff53

// typedef struct s_raycast
// {
// 	// double	px;
// 	// double	py;
// 	// int		map_x;
// 	// int		map_y;
// 	double	dir_x; //direction vector, value may change on each keypress
// 	double	dir_y;	//direction vector, value may change on each keypress
// 	// double	plane_x;
// 	// double	plane_y;
// 	// double	cam_x;
// 	// double	ray_dir_x;
// 	// double	ray_dir_y;
// 	// double	delta_x; //delta distance
// 	// double	delta_y; //delta distance
// 	// double	side_x; //side distance
// 	// double	side_y; //side distance
// 	double	wall_dist; //distance from position to wall hit
// 	double	p_angle; //player angle

// 	//DDA: calculate step (amount of steps to hit a grid)
// 	// int		step_x;
// 	// int		step_y;
// 	// int		side; //to check NS or EW wall hit

// }t_raycast;

typedef struct s_raycast
{
	//carried from t_raycast
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

typedef struct s_img //
{
    void	*mlx_img;
    char	*addr;
    int		bpp; /* bits per pixel */
    int		line_len;
    int		endian;
}	t_img;

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
	t_img 		img;
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

//raycast
void	ray_init(t_raycast *ray, t_player *player);
void	get_start_pa(t_raycast *ray, t_player *player);
void	raycast(t_game *game, t_raycast *ray);
void	draw_wall(t_game *game, t_raycast *ray, int r, int color);

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
		// game->map.xymap = ft_split(tmp,'\n');

	// plotted line not that smooth using Bresenham's line algorithm 
	// decision param = 2 * (y2 - y1) - (x2 - x1)
	// p or error/err = 2 * dy - dx
	// it is however capable to draw multi lines effciently
	// int xs = game->player.x;
	// int xe = game->player.x + game->ray.dir_x;
	// int ys = game->player.y;
	// int ye = game->player.y + game->ray.dir_y;

	// int dx = abs(xe - xs);
	// int dy = abs(ye - ys);

	// int next_x = (xs < xe) ? 1 : -1;
	// int next_y = (ys < ye) ? 1 : -1;

	// int err = dx - dy;
	// int e2;

	// while (xs != xe || ys != ye) 
	// {
	// 	mlx_pixel_put(game->mlx, game->win, xs, ys, game->player.color);

	// 	e2 = 2 * err;
	// 	if (e2 > -dy) 
	// 	{
	// 		err -= dy;
	// 		xs += next_x;
	// 	}
	// 	if (e2 < dx) 
	// 	{
	// 		err += dx;
	// 		ys += next_y;
	// 	}
	// }
	//-----------------------------------------------------
	// plotted line is starighter indirectly from y=mx+c linier eq to plain old triangle
	// less efficient/effective when drawing >1 line when computationg power is limites
	// becase it uses float instead of int
	//	it is also shorter in code length
	// int xs = game->player.x;
	// int xe = game->player.x + game->ray.dir_x;
	// int ys = game->player.y;
	// int ye = game->player.y + game->ray.dir_y;
	// 	// Compute the differences between the start and end points
	// int dx = xe - xs;
	// int dy = ye - ys;

	// // Determine whether the line is steeper in the x or y direction
	// int steps;
	// if (abs(dx) > abs(dy)) 
	// 	steps = abs(dx);
	// else 
	// 	steps = abs(dy);

	// // Calculate the increments for x and y
	// float x_increment = (float)dx / steps;
	// float y_increment = (float)dy / steps;

	// int i = 0;
	// float j = xs, y = ys;
	// while (i <= steps) 
	// {
	// 	mlx_pixel_put(game->mlx, game->win, (int)j, (int)y, game->player.color);
	// 	j += x_increment;
	// 	y += y_increment;
	// 	i++;
	// }

/* void	draw_line(t_game *game, int xe, int ye, int color)
{
	
	float xs;
	float ys;
	 
	xs = game->player.x;
	ys = game->player.y;

	xe += game->player.x; //+ game->ray.dir_x;
	ye += game->player.y; //+ game->ray.dir_y;

	// Compute the differences between the start and end points
	int dx;
	int dy;

	dx = xe - xs;
	dy = ye - ys;

	// Determine whether the line is steeper in the x or y direction
	// which is longer x or y?
	int steps;

	if (ft_abs(dx) > ft_abs(dy)) 
		steps = ft_abs(dx);
	else 
		steps = ft_abs(dy);

	// Calculate the increments for x and y
	float x_increment;
	float y_increment; 
	x_increment = (float)dx / steps;
	y_increment = (float)dy / steps;

	int i;
	i = 0;
	while (i <= steps) 
	{
		mlx_pixel_put(game->mlx, game->win, (int)xs, (int)ys, color);
		xs += x_increment;
		ys += y_increment;
		i++;
	}
} */