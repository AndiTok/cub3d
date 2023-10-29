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

#include "cub3d.h"

/*j = 2: to start after texture name*/
char	*check_xpm_format(char *str)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 4; // should be 4 fix due to str_dup in ft_split
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
	game->element.NO = check_xpm_format(game->element.NO);
	game->element.SO = check_xpm_format(game->element.SO);
	game->element.WE = check_xpm_format(game->element.WE);
	game->element.EA = check_xpm_format(game->element.EA);
	// 	printf("%s\n",game->element.NO);
	// 	printf("%s\n",game->element.SO);
	// 	printf("%s\n",game->element.EA);
	// 	printf("%s\n",game->element.WE);
}
