/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:07:19 by atok              #+#    #+#             */
/*   Updated: 2023/10/09 20:07:19 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*render floor & ceiling background*/
void	render_void(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->win_height)
	{
		j = 0;
		while (j < game->win_width)
		{
			if (i < game->win_height / 2)
				img_pix_put(&game->img, j, i, game->map.ceiling);
			else
				img_pix_put(&game->img, j, i, game->map.floor);
			j++;
		}
		i++;
	}
}

/*clear previous frame and render new frame*/
int	ft_render(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.mlx_img);
	ft_init_img(game);
	render_void(game);
	raycast(game, &game->ray);
	if (game->toggle_m == 1)
	{
		draw_2dmap(game);
		draw_player(game);
		draw_line(game, game->player.x + cos(game->ray.p_angle - 30 * DEG) * 25,
			game->player.y + sin(game->ray.p_angle - 30 * DEG) * 25, 0xFFFF00);
		draw_line(game, game->player.x + cos(game->ray.p_angle + 30 * DEG) * 25,
			game->player.y + sin(game->ray.p_angle + 30 * DEG) * 25, 0xFFFF00);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.mlx_img, 0, 0);
	return (0);
}
