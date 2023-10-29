/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 04:11:54 by atok              #+#    #+#             */
/*   Updated: 2023/08/01 04:11:54 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s2);
	while (s1[i] != 0x00 && s2[i] != 0x00 && i < len - 1)
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] != s2[i])
			break ;
	}
	return (s1[i] - s2[i]);
}

/* int main()
{
	char s1[] = "F 220,100,0";
	char s2[] = "F ";
	//printf("%d\n",ft_strncmp(s1,s2));
		if (!ft_strncmp(s1,s2))
			printf("works\n");
		else
			printf("oh");
}

//gcc ft_strncmp.c get_next_line_utils.c && ./a.out */