/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:25:20 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/02 14:46:56 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	fill_tab(char *new, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
}

static void	free_tab(char **tab, size_t allocated)
{
	size_t	i;

	i = 0;
	while (i < allocated)
	{
		free(tab[i]);
		i++;
	}
}

static int	set_mem(char **tab, char const *s, char c)
{
	size_t	count;
	size_t	index;
	size_t	current;

	index = 0;
	current = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index])
		{
			count = 0;
			while (s[index + count] && s[index + count] != c)
				count++;
			tab[current] = malloc(sizeof(char) * (count + 1));
			if (!tab[current])
			{
				free_tab(tab, current);
				return (0);
			}
			fill_tab(tab[current], s + index, c);
			current++;
			index += count;
		}
	}
	tab[current] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**tab;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	if (!set_mem(tab, s, c))
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}
