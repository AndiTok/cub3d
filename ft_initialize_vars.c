/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_vars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:03:41 by atok              #+#    #+#             */
/*   Updated: 2023/07/31 22:03:41 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initialize_vars(t_game *game)
{
	game->win_width = 0;
	game->win_height = 0;
	game->file.lines = 0;
	game->file.mid = 0;
	game->file.F = 0;
	game->file.C = 0;
	game->file.NO = 0;
	game->file.SO = 0;
	game->file.WE = 0;
	game->file.EA = 0;
}
