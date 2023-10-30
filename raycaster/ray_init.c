/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:41:36 by wyap              #+#    #+#             */
/*   Updated: 2023/10/30 14:41:36 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_init(t_raycast *ray, t_player *player)
{
	ray->p_angle = 0;
	get_start_pa(ray, player);
	ray->mx = 0;
	ray->my = 0;
	ray->rx = 0;
	ray->ry = 0;
	ray->xo = 0;
	ray->yo = 0;
	ray->dist_h = 1000000;
	ray->dist_v = 1000000;
	ray->dist_t = 0;
	ray->line_h = 0;
	ray->line_o = 0;
	ray->fish = 0;
}
