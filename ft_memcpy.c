/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:23:20 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/02 10:44:34 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_pointer;
	unsigned char	*src_pointer;

	dest_pointer = (unsigned char *)dest;
	src_pointer = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (n--)
		*dest_pointer++ = *src_pointer++;
	return (dest);
}
