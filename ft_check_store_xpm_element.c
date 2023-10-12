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

char	*check_texture_path_extention(char *str)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 4; // should be 4 fix due to str_dup in ft_split
	if (!ft_strnstr ((str + i), ".xpm", 4))
		ft_exit_error("ERROR check texture .xpm extention\n");
	i = 0;
	j = 5;
	while (str[j] != 0x00)
	{
		if (str[j] == ' ')
			ft_exit_error("ERROR file path has sapce\n");
		str[i] = str[j];
		i++;
		j++;
	}
	str[i] = 0x00;
	return (str);
}

void	ft_check_store_xpm_element(t_game *game)
{
	game->element.NO = check_texture_path_extention(game->element.NO);
	game->element.SO = check_texture_path_extention(game->element.SO);
	game->element.WE = check_texture_path_extention(game->element.WE);
	game->element.EA = check_texture_path_extention(game->element.EA);
	// 	printf("%s\n",game->element.NO);
	// 	printf("%s\n",game->element.SO);
	// 	printf("%s\n",game->element.EA);
	// 	printf("%s\n",game->element.WE);
}
