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

#include "cub3d.h"

// void check_duplicate_element(t_game *game)
// {
// 	int counter;

// 	counter = 0;
// 	if(game->file.F == 1)
// 		counter++;
// 	if(game->file.C == 1)
// 		counter++;
// 	if(game->file.NO == 1)
// 		counter++;
// 	if(game->file.SO == 1)
// 		counter++;
// 	if(game->file.WE == 1)
// 		counter++;
// 	if(game->file.EA == 1)
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
// 			game->file.F++;
// 		else if (ft_strnstr(game->file.xyfile[i],"C ",2) &&
// 				game->file.xyfile[i][2] != ' ')
// 			game->file.C++;
// 		else if (ft_strnstr(game->file.xyfile[i],"NO ./",5))
// 			game->file.NO++;
// 		else if (ft_strnstr(game->file.xyfile[i],"SO ./",5))
// 			game->file.SO++;
// 		else if (ft_strnstr(game->file.xyfile[i],"WE ./",5))
// 			game->file.WE++;
// 		else if (ft_strnstr(game->file.xyfile[i],"EA ./",5))
// 			game->file.EA++;
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
			game->file.NO++;
		else if (ft_strnstr(game->file.xyfile[i], "SO ", 3))
			game->file.SO++;
		else if (ft_strnstr(game->file.xyfile[i], "WE ", 3))
			game->file.WE++;
		else if (ft_strnstr(game->file.xyfile[i], "EA ", 3))
			game->file.EA++;
		i++;
	}
	if (game->file.NO != 1 || game->file.SO != 1
		|| game->file.WE != 1 || game->file.EA != 1)
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
			game->file.F++;
		else if (!ft_strncmp(game->file.xyfile[i], "C "))
			game->file.C++;
		i++;
	}
	if (game->file.F != 1 || game->file.C != 1)
		ft_exit_error("Error\nFC element not found or duplicate\n");
}

/*store specification to t_game data*/
void	store_element(t_game *game)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < game->file.mid)
	{
		if (game->file.xyfile[i][0] == 'F')
			game->element.F = ft_strdup(game->file.xyfile[i]);
		else if (game->file.xyfile[i][0] == 'C')
			game->element.C = ft_strdup(game->file.xyfile[i]);
		else if (game->file.xyfile[i][0] == 'N')
			game->element.NO = ft_strdup(game->file.xyfile[i]);
		else if (game->file.xyfile[i][0] == 'S')
			game->element.SO = ft_strdup(game->file.xyfile[i]);
		else if (game->file.xyfile[i][0] == 'W')
			game->element.WE = ft_strdup(game->file.xyfile[i]);
		else if (game->file.xyfile[i][0] == 'E')
			game->element.EA = ft_strdup(game->file.xyfile[i]);
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
	// printf("%s\n",game->element.F);
}
