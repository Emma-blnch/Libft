/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:59:11 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/02 15:57:43 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	index;

	if (!dest || !src)
		return (0);
	index = 0;
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (size <= len_dest)
		return (len_src + size);
	while (src[index] && (len_dest + index) < (size - 1))
	{
		dest[len_dest + index] = src[index];
		index++;
	}
	dest[len_dest + index] = '\0';
	return (len_src + len_dest);
}
