/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:38:40 by atok              #+#    #+#             */
/*   Updated: 2023/10/09 16:38:40 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	ft_init_img(t_game *game)
{
	game->img.mlx_img = mlx_new_image(game->mlx,
			game->win_width, game->win_height);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img,
			&game->img.bpp, &game->img.line_len, &game->img.endian);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if ((y <= 720 && y >= 0) && (x <= 1280 && x >= 0))
	{
		dst = img->addr + (y * (img->line_len) + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
