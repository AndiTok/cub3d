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

void render_void(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->win_height)
	{
		j = 0;
		while (j < game->win_width)
		{
			if(i < game->win_height / 2)
				img_pix_put(&game->img, j, i,game->map.ceiling);
			else
				img_pix_put(&game->img, j, i,game->map.floor);
			j++;
		}
		i++;
	}
}

int	ft_render(t_game *game)
{
	mlx_destroy_image(game->mlx,game->img.mlx_img);
	ft_init_img(game);

	// mlx_clear_window(game->mlx, game->win);
	// mlx_put_image_to_window(game->mlx,game->win,game->img.mlx_img,0,0); //
	render_void(game);
	raycast(game,&game->ray);
	if (game->toggle_m == 1)
	{
		draw_2dmap(game);
		draw_player(game);
		draw_line(game, game->player.x + game->ray.dir_x,  game->player.y + game->ray.dir_y, 0xFF00FF);
		// draw_line(game, game->ray.rx, game->ray.ry, 0x00FFFF);
	}
	// printf("P: dir_x: %f, dir_y %f\n", game->ray.dir_x, game->ray.dir_y);
		// draw_line(game, 0 , 0 , 0xFFFFFF); //test
	// draw_rect(game); // test  ft above
	mlx_put_image_to_window(game->mlx,game->win,game->img.mlx_img,0,0); //
	// mlx_do_sync(game->mlx);
	// printf("test");
	return (0);
}