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

// void check_duplicate_element(t_game *game)
// {
// 	int counter;

// 	counter = 0;
// 	if(game->file.f == 1)
// 		counter++;
// 	if(game->file.c == 1)
// 		counter++;
// 	if(game->file.no == 1)
// 		counter++;
// 	if(game->file.so == 1)
// 		counter++;
// 	if(game->file.we == 1)
// 		counter++;
// 	if(game->file.ea == 1)
// 		counter++;
// 	if(counter != 6) //
// 		ft_exit_error("duplicate element\n");
// }

// void check_6_element(t_game *game)
// {
// 	int i;

// 	i = 0;
// 	while(i < game->file.mid)
// 	{
// 		if (ft_strnstr(game->file.xyfile[i],"F ",2) && 
// 				game->file.xyfile[i][2] != ' ')
// 			game->file.f++;
// 		else if (ft_strnstr(game->file.xyfile[i],"C ",2) &&
// 				game->file.xyfile[i][2] != ' ')
// 			game->file.c++;
// 		else if (ft_strnstr(game->file.xyfile[i],"NO ./",5))
// 			game->file.no++;
// 		else if (ft_strnstr(game->file.xyfile[i],"SO ./",5))
// 			game->file.so++;
// 		else if (ft_strnstr(game->file.xyfile[i],"WE ./",5))
// 			game->file.we++;
// 		else if (ft_strnstr(game->file.xyfile[i],"EA ./",5))
// 			game->file.ea++;
// 		else
// 			ft_exit_error("wrong element format, typo or spacing\n");
// 		i++;
// 	}
// 	//to make sure there is C ,F ,NO ./,SO ./,WE ./,EA ./
// 	//& "next" to it is not space
// }

/*check texture specification on .cub*/
void	check_other_element(t_game *game)
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
		ft_exit_error("Error\nOther element not found or duplicate\n");
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
		ft_exit_error("Error\nFC element not found or duplicate\n");
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

// void store_map(t_game *game)
// {
// 	char **tmp; 
// 	int i;
// 	int j;

// 	j = game->file.mid;
// 	i = 0;
// 	tmp = (char**)malloc(sizeof (char *) * (game->file.lines - j + 1)); // +1 for null
// 	// while(j < game->file.lines)
// 	while(game->file.xyfile[j] != 0x00)
// 	{
// 		tmp[i] = ft_strdup(game->file.xyfile[j]);
// 		i++;
// 		j++;
// 	}
// 	tmp[i] = 0x00; // so can loop trough with null
// 	game->map.xymap = tmp;
// 	// i = 0;
// 	// while(game->map.xymap[i] != 0x00)
// 	// {
// 	// 	printf("%s\n",game->map.xymap[i]);
// 	// 	i++;
// 	// }
// }

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
	// check_6_element(game);
	check_fc_element(game);
	check_other_element(game);
	//check_duplicate_element(game); // handeled in check
	store_element(game);
	//store_map(game);
	// printf("%s\n",game->element.f);
}
