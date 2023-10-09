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

int	ft_render(t_game *game)
{
	mlx_destroy_image(game->mlx,game->img.mlx_img);
	ft_init_img(game);

	// mlx_clear_window(game->mlx, game->win);
	// mlx_put_image_to_window(game->mlx,game->win,game->img.mlx_img,0,0); //
	draw_2dmap(game);
	draw_player(game);
	draw_line(game, game->player.x + game->ray.dir_x,  game->player.y + game->ray.dir_y, 0xFF00FF);
	// printf("P: dir_x: %f, dir_y %f\n", game->ray.dir_x, game->ray.dir_y);
	raycast(game,&game->ray);
		// draw_line(game, 0 , 0 , 0xFFFFFF); //test
	// draw_rect(game); // test  ft above
	mlx_put_image_to_window(game->mlx,game->win,game->img.mlx_img,0,0); //
	// mlx_do_sync(game->mlx);
	// printf("test");
	return (0);
}