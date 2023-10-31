/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 07:42:56 by atok              #+#    #+#             */
/*   Updated: 2023/10/31 15:05:05 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

char	*ft_joinfree(char *str, char *tmpstr)
{
	char	*join;

	join = ft_strjoin(str, tmpstr);
	free(str);
	return (join);
}
