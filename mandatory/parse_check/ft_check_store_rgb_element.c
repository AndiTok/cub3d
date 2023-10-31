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

#include "../incl/cub3d.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
* convert RGB intensity to color hex value
* (r << 16) | (g << 8) | b;
*/
int	check_rgb_value(int r, int g, int b)
{
	int	i;

	if (r < 0 || r > 255)
		ft_exit_error("Error\nRGB R,-,- not within 0 & 255 \n");
	if (g < 0 || g > 255)
		ft_exit_error("Error\nRGB -,G- not within 0 & 255 \n");
	if (b < 0 || b > 255)
		ft_exit_error("Error\nRGB -,-,B not within 0 & 255 \n");
	i = (r << 16) | (g << 8) | b;
	return (i);
}

/*
* R: ++i first to start at 2 where numbers are at
* G: ++i to get over ',' first then check
*/
int	convert_check_store_rgb(char *str)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	while (ft_isdigit(str[i + 1]) == 0)
		i++;
	r = 0;
	while (str[++i] != ',')
		r = r * 10 + (str[i] - '0');
	g = 0;
	while (str[++i] != ',')
		g = g * 10 + (str[i] - '0');
	i++;
	b = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		b = b * 10 + (str[i] - '0');
		i++;
	}
	i = check_rgb_value(r, g, b);
	return (i);
}

/*check rgb specification string, skip "F " and "C "*/
void	check_rgbformat(char *str)
{
	int	i;
	int	j;
	int	comma;

	comma = 0;
	j = ft_strlen(str) - 1;
	if (ft_isdigit(str[j]) == 0)
		ft_exit_error("Error\nwrong RGB format at END, must only be 0-9\n");
	i = 0;
	while (ft_isdigit(str[i]) == 0)
		i++;
	if (ft_isdigit(str[i]) == 0)
		ft_exit_error("Error\nwrong RGB format at START, must only be 0-9\n");
	i = 3;
	while (i++ < j)
	{
		if (str[i] == ',')
		{
			if (str[i + 1] == ',')
				ft_exit_error("Error\n ',' next to each other\n");
			comma++;
		}
	}
	if (comma != 2)
		ft_exit_error("Errorn\n wrong format, extra/missing ','\n");
}

void	ft_check_store_rgb_element(t_game *game)
{
	check_rgbformat(game->element.f);
	check_rgbformat(game->element.c);
	game->map.floor = convert_check_store_rgb(game->element.f);
	game->map.ceiling = convert_check_store_rgb(game->element.c);
}
