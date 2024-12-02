/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:21:56 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/02 15:58:11 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pointer;
	size_t	index;

	if (!s)
		return (NULL);
	index = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	pointer = malloc(sizeof(char) * (len + 1));
	if (!pointer)
		return (NULL);
	while (index < len && s[start + index])
	{
		pointer[index] = s[start + index];
		index++;
	}
	pointer[index] = '\0';
	return (pointer);
}
