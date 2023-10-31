/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 07:48:13 by atok              #+#    #+#             */
/*   Updated: 2023/07/30 07:48:13 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

/*local ft_putstr*/
void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != 0x00)
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_exit_error(char *str)
{
	ft_putstr(str);
	exit(1);
}
