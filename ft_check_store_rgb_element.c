/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 01:52:48 by atok              #+#    #+#             */
/*   Updated: 2023/08/01 01:52:48 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_rgb_value(int r, int g, int b)
{
	int	i;

	if (r < 0 || r > 255)
		ft_exit_error("RGB R,-,- not within 0 & 255 \n");
	if (g < 0 || g > 255)
		ft_exit_error("RGB -,G- not within 0 & 255 \n");
	if (b < 0 || b > 255)
		ft_exit_error("RGB -,-,B not within 0 & 255 \n");
	i = (r << 16) | (g << 8) | b; // formula
		//printf("%d\n", i);
	return (i);
}

int	convert_check_store_rgb(char *str)
{
	int	r;
	int	g;
	int	b;
	int	i;
			// note if i = 2, i++ will +2 
	i = 1; // start at 1
	r = 0;
	while (str[++i] != ',') //++i first to start at 2 where numbers are at 
		r = r * 10 + (str[i] - '0');
	g = 0;
	while (str[++i] != ',') // it will ++i to get over ',' first then check
		g = g * 10 + (str[i] - '0');
	i++;
	b = 0;
	while (str[i] >= '0' && str[i] <= '9') // cant use while != 0x00 & is btter to check for num
	{
		b = b * 10 + (str[i] - '0');
		i++;
	}
	i = check_rgb_value(r, g, b);
	return (i);
}

void	check_rgbformat(char *str)
{
	int		i;
	int		j;
	int		counter;

	counter = 0;
	j = ft_strlen(str) - 1;
	if (str[j] < '0' || str[j] > '9') // check for 0-9 at end
		ft_exit_error("wrong RGB format at END, must only be 0-9\n");
	i = 2;
	if (str[i] < '0' || str[i] > '9') // check for 0-9 at beginning
		ft_exit_error("wrong RGB format at START, must only be 0-9\n");
	i = 3;
	while (i < j) // check inbetween
	{
		if (str[i] == ',')
		{
			if (str[i + 1] == ',') // cannot be netx ot each other
				ft_exit_error("wrong format, ',' next to each other\n");
			counter++;
		}
		i++;
	}
	if (counter != 2) // can only have 2 ','
		ft_exit_error("wrong format, extra/missing ','\n");
}

void	ft_check_store_rgb_element(t_game *game)
{
	check_rgbformat(game->element.F);
	check_rgbformat(game->element.C);
	game->map.floor = convert_check_store_rgb(game->element.F);
	game->map.ceiling = convert_check_store_rgb(game->element.C);
}
