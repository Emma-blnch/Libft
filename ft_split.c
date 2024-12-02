/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:25:20 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/02 12:55:08 by eblancha         ###   ########.fr       */
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

static char	*fill_word(char const *new, int start, int end)
{
	size_t	i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (end - start) + 1);
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = new[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_tab(char **tab, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	ft_initiate_vars(size_t *i, int *j, int *s_word)
{
	*i = 0;
	*j = 0;
	*s_word = -1;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	int		s_word;
	char	**tab;
	int		word_len;

	ft_initiate_vars(&i, &j, &s_word);
	word_len = count_words(s, c);
	tab = malloc(sizeof(char *) * (word_len + 1));
	if (!tab)
		return (NULL);
	while (i < ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || s[i + 1] == '\0') && s_word >= 0)
		{
			tab[j] = fill_word(s, s_word, i);
			if (!tab[j])
			{
				free_tab(tab, j);
				return (NULL);
			}
			s_word = -1;
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
