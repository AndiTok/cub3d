/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 07:43:11 by atok              #+#    #+#             */
/*   Updated: 2023/08/01 04:06:50 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*str;
	const char	*find;
	size_t		i;
	size_t		j;

	str = haystack;
	find = needle;
	if (*find == 0x00)
		return ((char *) str);
	if (len == 0)
		return (NULL);
	i = 0;
	j = 0;
	while ((str[i] != 0x00) && (len > i + j))
	{
		j = 0;
		while (str[i + j] == find[j] && len > i + j)
		{
			if (find[j + 1] == 0x00)
				return ((char *) str + i);
					j++;
		}
		i++;
	}
	return (NULL);
}

//returns a pointer to the needle/to_find string

/* int main()
{
	char str[] = "omfgmhead";
	char find[] = "f";
	int len = 5; // how far in str u want to search 
	char *ans;
	//printf("%s\n",ft_strnstr(str,find,len));
	if(ft_strnstr(str,find,len))
		printf("yeah\n");
		// //if (!ans) //same meaning
		// if (ans == NULL)
		// 	printf(">null<\n");
		// else
		// 	printf("%s\n",ans);
} */