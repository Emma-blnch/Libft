/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:47:48 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/02 15:59:05 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	j;

	if (!*little)
		return ((char *)big);
	index = 0;
	while (big[index] && index < len)
	{
		j = 0;
		while (big[index + j] == little[j] && little[j] && index + j < len)
			j++;
		if (!little[j])
			return ((char *)(big + index));
		index++;
	}
	return (NULL);
}
