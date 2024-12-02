/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:30:35 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/02 15:03:34 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*allocate_string(size_t size)
{
	char	*result;

	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	s1_len = 0;
	s2_len = 0;
	if (!s1 || !s2)
		return (allocate_string(0));
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (s1[s1_len])
	{
		result[s1_len] = s1[s1_len];
		s1_len++;
	}
	while (s2[s2_len])
	{
		result[s1_len + s2_len] = s2[s2_len];
		s2_len++;
	}
	result[s1_len + s2_len] = '\0';
	return (result);
}
