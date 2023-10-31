/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyap <wyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 07:43:06 by atok              #+#    #+#             */
/*   Updated: 2023/10/31 15:05:05 by wyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != 0x00)
	{
		if (s[i] == c && s[i + 1] == c)
			ft_exit_error("Error\nEmpty Row\n");
		while (s[i] == c && s[i] != 0x00)
			i++;
		if (s[i] != 0x00)
			count++;
		while (s[i] != c && s[i] != 0x00)
			i++;
	}
	return (count);
}

char	*word_dup(const char *s, char c)
{
	int		len;
	int		i;
	char	*word;

	i = 0;
	len = 0;
	while (s[len] != 0x00 && s[len] != c)
		len++;
	if (s[len] == 0x00)
		len++;
	word = (char *) malloc(sizeof(char) * (len));
	if (word == NULL)
		return (NULL);
	while (i < len - 1)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0x00;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	split = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (split == NULL)
		return (NULL);
	while (s[i] != 0x00)
	{
		while (s[i] == c && s[i] != 0x00)
			i++;
		if (s[i] != 0x00)
		{
			split[j] = word_dup(&s[i], c);
			j++;
		}
		while (s[i] != c && s[i] != 0x00)
			i++;
	}
	split[j] = 0x00;
	return (split);
}

/* int main(void)
{
	char **split;
	size_t	i = 0;
	size_t	j = 0;
	char str[] = "   hello world  123  test   ";
	char delim = ' ';

	split = ft_split(str, delim);
	
	printf("andi str has %i words\n", word_count(str, delim));
	// printf("%s\n", *ft_split(str, delim)); // print first array
	 while (split[i] != 0x00)
	 {
		printf("%s\n", split[i]);
		i++;
	 }
	 */
//   	while (split[i] != 0x00)
// 	{
// 		j = 0;
// 		while (split[i][j])
// 			write(1, &split[i][j++], 1);
// 		write(1, "\n", 1);
// 		i++;
// 	}
// 	return (0);
// }

/* **ft_.. = 2D array meaning
from this s [] ="Hi my name is"
to below
s [1] = "Hi"
s [2] = "my"
s [3] = "name"
s [4] = "is"
s [[1][2][3][4]] = "Hi" "my" "name" "is"
witin 1 array there is multiple array

can split how ever many time as long as there is delimiter
which is specified by user  

might need to while loop and print to see it */

/* word_count MUST be be in that sequence in order handle
if delimiter at the front and back OR only at the front OR only at the back
does not wokr in any other way.. if it can handle the front,
it will not be able to handle the back & vice versa..
BECAUSE
if there is no delimiter it will count++ on the 1st word
skipping the delimiter checking
if there is delimiter it will loop pass the delimiter then count++
in other workds, count++ must be before a non-delimiter
cmust ount++ FIRST on every first letter word
if count++ after a word, NULL tirminal will fuck it up*/