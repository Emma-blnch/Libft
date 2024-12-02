/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:17:23 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/02 15:57:19 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int character, size_t n)
{
	unsigned char	*pointer;

	pointer = (unsigned char *)s;
	while (n--)
		*pointer++ = (unsigned char)character;
	return (s);
}
