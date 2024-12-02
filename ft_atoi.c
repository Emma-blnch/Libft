/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:30:13 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/02 10:40:07 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *string)
{
	int		multiplier;
	int		result;
	size_t	index;

	index = 0;
	multiplier = 1;
	result = 0;
	while (string[index] == ' ' || (string[index] >= 9 && string[index] <= 13))
	{
		index++;
	}
	if ((string[index] == '-' || string[index] == '+'))
	{
		if ((string[index + 1] == '-' || string[index + 1] == '+'))
			return (0);
		if (string[index] == '-')
			multiplier *= -1;
		index++;
	}
	while (string[index] >= '0' && string[index] <= '9')
	{
		result = result * 10 + (string[index] - '0');
		index++;
	}
	return (result * multiplier);
}
