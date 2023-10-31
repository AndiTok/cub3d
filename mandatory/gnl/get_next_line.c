/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:26:07 by atok              #+#    #+#             */
/*   Updated: 2023/10/31 15:05:05 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

char	*read_file(int fd, char *str)
{
	char	*tmpstr;
	char	*bin;
	int		i;

	if (str == 0x00)
		str = ft_strdup("");
	i = 1;
	tmpstr = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
	while (i > 0)
	{
		i = read(fd, tmpstr, BUFFER_SIZE);
		if (i == -1)
		{
			free(tmpstr);
			return (NULL);
		}
		tmpstr[i] = 0x00;
		bin = str;
		str = ft_strjoin(str, tmpstr);
		free(bin);
		if (ft_strchr(tmpstr, '\n'))
			break ;
	}
	free(tmpstr);
	return (str);
}

char	*get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (str[i] == 0x00)
		return (NULL);
	while (str[i] != 0x00 && str[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i] != 0x00 && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] != 0x00 && str[i] == '\n')
		line[i++] = '\n';
	line[i] = 0x00;
	return (line);
}

char	*remaining(char *str)
{
	int		i;
	int		j;
	char	*remaining;

	i = 0;
	while (str[i] != 0x00 && str[i] != '\n')
		i++;
	if (str[i] == 0x00)
	{
		free (str);
		return (NULL);
	}
	remaining = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (str[i] != 0x00)
		remaining[j++] = str[i++];
	free(str);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = read_file(fd, str);
	if (str == NULL)
		return (NULL);
	line = get_line(str);
	str = remaining(str);
	return (line);
}

// remaining = ft_strdup(str + i + 1);
/* read returns -1 ,0 or > 0
-1 = error
0 = read nothing
>0 = read amount */

/* BUFFER_SIZE = read size...
the bigger the faster
if not it will keep loopinf till it hits \n */

/* 1st to read the file/copy from .txt to our founction/calloc
loop read buffer size amount & joining old and new str till '\n'
tmpstr is free outside the loop becase the buffer constantly 
reallocate that ammount in to tmpstr

imagine from collum to row
2nd output the frist 
3rd stored the res of the line in static char
repeat */

/* can use .c and .h file as the fd */