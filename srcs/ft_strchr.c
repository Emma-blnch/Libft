/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:40:06 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/02 14:53:18 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	void	*result;

	len = ft_strlen(s) + 1;
	result = ft_memchr(s, c, len);
	return ((char *)result);
}
