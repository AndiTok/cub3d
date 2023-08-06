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
		// if(tmp[1] != '\n') // parse in file with no blank row
		// {
		// 	file = ft_joinfree(file, tmp);
		// 	game->file.lines += 1;
		// }
		file = ft_joinfree(file, tmp);
		game->file.lines += 1;
	}
	close(fd);
	game->file.file = file;
	game->file.xyfile = ft_split(file, '\n');
		//printf("%d\n",game->file.lines);

	// int i = 0;
	// while (game->file.file[i] != 0x00)
	// {
	// 	printf("%c",game->file.file[i]);
	// 	i++;
	// }
	// int i = 0;
	// while (game->file.xyfile[i] != 0x00)
	// {
	// 	printf("%s\n",game->file.xyfile[i]);
	// 	i++;
	// }
}
