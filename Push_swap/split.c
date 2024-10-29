/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:07:10 by scarlos-          #+#    #+#             */
/*   Updated: 2024/10/11 20:39:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char c)
{
	int		count;
	int		flag;

	count = 0;
	while (*str)
	{
		flag = 0;
		while (*str == c && *str)
			++str;
		while (*str != c && *str)
		{
			if (!flag)
			{
				++count;
				flag = 1;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char c)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == c)
		++cursor;
	while ((str[cursor + len] != c) && str[cursor + len])
		++len;
	next_str = malloc((int)len * sizeof(char) + 1);
	if (next_str == NULL)
		return (NULL);
	while ((str[cursor] != c) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char c)
{
	int		nbr_words;
	char	**strings;
	int		i;

	i = 0;
	nbr_words = count_words(str, c);
	if (!nbr_words)
		exit(1);
	strings = malloc(sizeof(char *) * (size_t)(nbr_words + 2));
	if (strings == NULL)
		return (NULL);
	while (nbr_words-- >= 0)
	{
		if (i == 0)
		{
			strings[i] = malloc(sizeof(char));
			if (strings[i] == NULL)
				return (NULL);
			strings[i++][0] = '\0';
			continue ;
		}
		strings[i++] = get_next_word(str, c);
	}
	strings[i] = NULL;
	return (strings);
}
