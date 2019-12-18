/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:10:46 by ahandsom          #+#    #+#             */
/*   Updated: 2019/09/22 19:00:42 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *substr)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str[0] == '\0' && substr[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (substr[j] != '\0' && str[i + j] == substr[j])
			j++;
		if (substr[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
