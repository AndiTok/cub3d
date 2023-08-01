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

void check_Other_element(t_game *game)
{
	int i;

	i = 0;
	while(i < game->file.mid)
	{
		if (ft_strnstr(game->file.xyfile[i],"NO ./",5) && 
				game->file.xyfile[i][5] != ' ')
			game->file.NO++;
		else if (ft_strnstr(game->file.xyfile[i],"SO ./",5) && 
				game->file.xyfile[i][5] != ' ')
			game->file.SO++;
		else if (ft_strnstr(game->file.xyfile[i],"WE ./",5) && 
				game->file.xyfile[i][5] != ' ')
			game->file.WE++;
		else if (ft_strnstr(game->file.xyfile[i],"EA ./",5) && 
				game->file.xyfile[i][5] != ' ')
			game->file.EA++;
		i++;
	}
	if(game->file.NO == 0 || game->file.SO == 0 || 
		game->file.WE == 0 || game->file.EA == 0)
		ft_exit_error("Other element format ERROR or duplicate\n");
	//to make sure there is NO ./,SO ./,WE ./,EA ./
 	//& "next" to it is not space
}

void check_FC_element(t_game *game)
{
	int i;

	i = 0;
	while(i < game->file.mid)
	{

		if (!ft_strncmp(game->file.xyfile[i],"F ") && 
			game->file.xyfile[i][2] != ' ')
			game->file.F++;
		else if (!ft_strncmp(game->file.xyfile[i],"C ") && 
			game->file.xyfile[i][2] != ' ')
			game->file.C++;
		i++;
	}
	if(game->file.F == 0 || game->file.C == 0)
		ft_exit_error("FC element format ERROR or duplicate\n");
	// to make sure there is C ,F ,
	// & "next" to it is not space
}

void store_element(t_game *game)
{
	int i;
	// int counter;

	i = 0;
	// counter = 0;
	while(i < game->file.mid)
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

void	find_mid_store_map(t_game *game)
{
	int i;
	int k;
	
	i = 0;
	while(game->file.xyfile[i] != 0x00)
	{
		if(game->file.xyfile[i][0] == ' ' || game->file.xyfile[i][0] == '1')
		{
			//map beignning is either alwasy == to ' ' or 1
			game->file.mid = i; // mid section saperator aka 1st line of map
			break;
		}
		i++;
	}
	if(i != 6) // make sure there ar only 6 elements at the top
		ft_exit_error("extra or missing color/texture map element line\n");
		// printf("%s\n",game->file.xyfile[i]); // check where "i" is pointing
		//printf("%d\n",i); // check number 
		// k = 0; // check file
		// while (game->file.xyfile[k] != 0x00)
		// {
		// 	printf("%s\n",game->file.xyfile[k]);
		// 	k++;
		// }
	char **tmp = (char**)malloc(sizeof (char *) * game->file.lines - i + 1);
	k = 0;
	while(game->file.xyfile[i] != 0x00)
	{
		tmp[k] = ft_strdup(game->file.xyfile[i]);
		k++;
		i++;
	}
	tmp[k] = 0x00;
	game->map.xymap = tmp;
		// i = 0; // check map
		// while(game->map.xymap[i] != 0x00)
		// {
		// 	printf("%s\n",game->map.xymap[i]);
		// 	i++;
		// }
}

/*
store map
check element: floor and ceiling color info format
check element: (north south west east) texture
parse element to struct t_element
*/
void	ft_split_store_file_info(t_game *game)
{
	find_mid_store_map(game);
	// check_6_element(game);
	check_FC_element(game);
	check_Other_element(game);
	//check_duplicate_element(game); // handeled in check
	store_element(game);
	//store_map(game);
}
