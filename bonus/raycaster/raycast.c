/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:53:14 by wyap              #+#    #+#             */
/*   Updated: 2023/10/30 15:53:14 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	fix_fisheye(t_raycast *ray)
{
	ray->fish = ray->p_angle - ray->ra;
	ray->fish = angle_reset(ray->fish);
	ray->dist_t *= cos(ray->fish);
}

void	raycast(t_game *game, t_raycast *ray)
{
	int	r;
	int	t;

	r = 0;
	ray->ra = ray->p_angle - (30.0 * (M_PI / 180.00));
	ray->ra = angle_reset(ray->ra);
	ray->px = game->player.x;
	ray->py = game->player.y;
	while (r < 1260)
	{
		dda(&game->map, ray);
		t = set_dist_t_texture(&game->map, ray);
		fix_fisheye(ray);
		draw_xpm(game, ray, r, t);
		ray->ra += ((M_PI / 180.00) / 21);
		ray->ra = angle_reset(ray->ra);
		r++;
	}
}
