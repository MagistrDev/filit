/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:13:55 by ahandsom          #+#    #+#             */
/*   Updated: 2019/09/19 19:45:27 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					negative;
	int					i;

	i = 0;
	negative = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		negative = -1;
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	if (i > 19 || result >= 9223372036854775808ULL)
		return (negative == 1 ? -1 : 0);
	return (result * negative);
}
