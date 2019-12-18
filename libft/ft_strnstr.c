/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:07:04 by ahandsom          #+#    #+#             */
/*   Updated: 2019/09/23 19:06:11 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((str == 0 && substr == 0) || substr[0] == '\0')
		return ((char *)str);
	while (i < n && str[i] != '\0')
	{
		j = 0;
		while (i + j < n && str[i + j] == substr[j] && substr[j] != '\0')
			j++;
		if (substr[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
