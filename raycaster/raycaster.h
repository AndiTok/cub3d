#include "../cub3d.h"

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

	//DDA: calculate step (amount of steps to hit a grid)
	int		step_x;
	int		step_y;
	int		side; //to check NS or EW wall hit

} t_raycast;
