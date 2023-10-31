/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 07:32:43 by atok              #+#    #+#             */
/*   Updated: 2023/07/30 07:32:43 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	ft_check_input(int c, char **v)
{
	int	i;

	if (c != 2)
		ft_exit_error("Error: Wrong number of input/param\n");
	i = ft_strlen(v[1]) - 4;
	if (!ft_strnstr ((v[1] + i), ".cub", 4))
		ft_exit_error("Error: Wrong map file format, must be a .cub file\n");
}
