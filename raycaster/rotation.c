/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 02:36:36 by wyap              #+#    #+#             */
/*   Updated: 2023/09/07 02:36:36 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotation(int keycode, t_raycast ray)
{
	if (keycode == LEFT)
	{
		ray.p_angle -= 0.1;
		if (ray.p_angle < 0)
			ray.p_angle += PI * 2; //reset to 2 PI
		ray.dir_x = cos(ray.p_angle) * 5; // multiply 5 to see significant value
		ray.dir_y = sin(ray.p_angle) * 5;
	}
	if (keycode == RIGHT)
	{
		ray.p_angle += 0.1;
		if (ray.p_angle > PI * 2)
			ray.p_angle -= PI * 2; //reset to 2 PI
		ray.dir_x = cos(ray.p_angle) * 5; // multiply 5 to see significant value
		ray.dir_y = sin(ray.p_angle) * 5;
	}
	// return (0);
}

