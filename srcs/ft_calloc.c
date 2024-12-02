/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:02:08 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/02 15:56:16 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t num_elements, size_t size)
{
	char	*pointer;

	if (num_elements == 0 || size == 0)
	{
		pointer = malloc(0);
		return (pointer);
	}
	if (((num_elements * size) / size) != num_elements)
		return (NULL);
	pointer = malloc(num_elements * size);
	if (!pointer)
		return (NULL);
	memset(pointer, 0, num_elements * size);
	return (pointer);
}
