/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 07:35:48 by atok              #+#    #+#             */
/*   Updated: 2023/07/30 07:35:48 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*read .cub file, store content in one string,
and splitted versionin 2D char array*/
void	ft_load_file(t_game *game, char **v)
{
	static int	fd;
	char		*file;
	char		*tmp;

	fd = open(v[1], O_RDONLY);
	if (fd == -1)
		ft_exit_error("Error\nFile empty");
	file = ft_strdup("");
	while (fd != -1)
	{
		tmp = get_next_line(fd);
		if (tmp == 0x00)
			break ;
		file = ft_joinfree(file, tmp);
		free(tmp);
		game->file.lines += 1;
	}
	close(fd);
	game->file.file = file;
	game->file.xyfile = ft_split(file, '\n');
}
