/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 07:42:56 by atok              #+#    #+#             */
/*   Updated: 2023/07/30 07:43:34 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_joinfree(char *str, char *tmpstr)
{
	char	*join;

	join = ft_strjoin(str, tmpstr);
	free(str);
	return (join);
}
