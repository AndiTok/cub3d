/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 07:38:11 by atok              #+#    #+#             */
/*   Updated: 2023/07/30 07:38:11 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

/*check texture specification on .cub*/
void	check_texture_element(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->file.mid)
	{
		if (ft_strnstr(game->file.xyfile[i], "NO ", 3))
			game->file.no++;
		else if (ft_strnstr(game->file.xyfile[i], "SO ", 3))
			game->file.so++;
		else if (ft_strnstr(game->file.xyfile[i], "WE ", 3))
			game->file.we++;
		else if (ft_strnstr(game->file.xyfile[i], "EA ", 3))
			game->file.ea++;
		i++;
	}
	if (game->file.no != 1 || game->file.so != 1
		|| game->file.we != 1 || game->file.ea != 1)
		ft_exit_error("Error: Texture element not found or duplicate\n");
}

/*check floor & ceiling spec on .cub*/
void	check_fc_element(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->file.mid)
	{
		if (!ft_strncmp(game->file.xyfile[i], "F "))
			game->file.f++;
		else if (!ft_strncmp(game->file.xyfile[i], "C "))
			game->file.c++;
		i++;
	}
	if (game->file.f != 1 || game->file.c != 1)
		ft_exit_error("Error: FC element not found or duplicate\n");
}

/*store specification to t_game data*/
void	store_element(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->file.mid)
	{
		if (game->file.xyfile[i][0] == 'F')
			game->element.f = ft_strdup(game->file.xyfile[i]);
		else if (game->file.xyfile[i][0] == 'C')
			game->element.c = ft_strdup(game->file.xyfile[i]);
		else if (game->file.xyfile[i][0] == 'N')
			game->element.no = ft_strdup(game->file.xyfile[i]);
		else if (game->file.xyfile[i][0] == 'S')
			game->element.so = ft_strdup(game->file.xyfile[i]);
		else if (game->file.xyfile[i][0] == 'W')
			game->element.we = ft_strdup(game->file.xyfile[i]);
		else if (game->file.xyfile[i][0] == 'E')
			game->element.ea = ft_strdup(game->file.xyfile[i]);
		i++;
	}
}

/*locate empty line after specification in .cub*/
void	find_mid(t_game *game)
{
	int	i;

	i = 0;
	while (game->file.xyfile[i] != 0x00)
	{
		if (game->file.xyfile[i][0] != 'F' && game->file.xyfile[i][0] != 'C' &&
			game->file.xyfile[i][0] != 'N' && game->file.xyfile[i][0] != 'S' &&
			game->file.xyfile[i][0] != 'W' && game->file.xyfile[i][0] != 'E' &&
			game->file.xyfile[i][0] != '\0')
		{
			game->file.mid = i;
			break ;
		}
		i++;
	}
}

void	ft_split_store_file_element(t_game *game)
{
	find_mid(game);
	check_fc_element(game);
	check_texture_element(game);
	store_element(game);
}
