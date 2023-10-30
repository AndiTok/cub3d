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

#include "../cub3d.h"

void	raycast(t_game *game, t_raycast *ray)
{
	int	r;
	int	t;

	r = 0;
	ray->ra = ray->p_angle - (30.0 * DEG);
	ray->ra = angle_reset(ray->ra);
	ray->px = game->player.x;
	ray->py = game->player.y;
	while (r < 1260)
	{
		dda(&game->map, ray);
		t = set_dist_t_texture(ray);
		fix_fisheye(ray);
		draw_xpm(game, ray, r, t);
		ray->ra += (DEG / 21);
		ray->ra = angle_reset(ray->ra);
		r++;
	}
}
