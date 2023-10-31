/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_store_xpm_element.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 06:15:57 by atok              #+#    #+#             */
/*   Updated: 2023/08/01 06:15:57 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

/*
* i = strlen - 4: to start before ".xpm"
* j = 2: to start after texture name
*/
char	*check_xpm_format(char *str)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 4;
	if (!ft_strnstr ((str + i), ".xpm", 4))
		ft_exit_error("ERROR: Invalid texture format\n");
	i = 0;
	j = 2;
	while (str[j] == ' ')
		j++;
	while (str[j] != 0x00)
	{
		str[i] = str[j];
		i++;
		j++;
	}
	str[i] = 0x00;
	return (str);
}

void	ft_check_store_xpm_element(t_game *game)
{
	game->element.no = check_xpm_format(game->element.no);
	game->element.so = check_xpm_format(game->element.so);
	game->element.we = check_xpm_format(game->element.we);
	game->element.ea = check_xpm_format(game->element.ea);
}
	// 	printf("%s\n",game->element.no);
	// 	printf("%s\n",game->element.so);
	// 	printf("%s\n",game->element.ea);
	// 	printf("%s\n",game->element.we);
