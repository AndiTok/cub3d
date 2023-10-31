/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:33:16 by atok              #+#    #+#             */
/*   Updated: 2023/10/31 15:05:05 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while ((char)str[len] != 0x00)
		len++;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*allocate;
	size_t			i;
	unsigned char	*tmp;

	if (size == 0 || count == 0)
		return (ft_strdup(""));
	if (count >= SIZE_MAX / size)
		return (NULL);
	allocate = malloc(count * size);
	if (allocate == NULL)
		return (NULL);
	i = 0;
	tmp = (unsigned char *)allocate;
	while (i < count * size)
	{
		tmp[i] = 0x00;
		i++;
	}
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != c && str[i] != 0x00)
	{
		i++;
	}
	if (str[i] == c)
		return (&str[i]);
	else
		return (NULL);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	int		len;

	len = 0;
	while (src[len])
		len++;
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (dup == (NULL))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = 0x00;
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ss;
	int		dl;
	int		sl;

	if (s1 == 0x00 || s2 == 0x00)
		return (0);
	ss = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ss == NULL)
		return (NULL);
	dl = 0;
	while (s1[dl] != 0x00)
	{
		ss[dl] = s1[dl];
		dl++;
	}
	sl = 0;
	while (s2[sl] != 0x00)
	{
		ss[dl] = s2[sl];
		sl++;
		dl++;
	}
	ss[dl] = 0x00;
	return (ss);
}
