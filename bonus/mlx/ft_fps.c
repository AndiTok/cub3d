/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:00:40 by atok              #+#    #+#             */
/*   Updated: 2023/11/01 03:00:40 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

/*door animation: switch door texture when condition met*/
int	ft_fps(t_game *game)
{
	game->fps++;
	if (game->fps == 4242)
	{
		game->map.d++;
		game->map.d = game->map.d % 2;
		ft_render(game);
		game->fps = 0;
	}
	return (0);
}
