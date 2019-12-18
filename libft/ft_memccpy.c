/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:23:37 by ahandsom          #+#    #+#             */
/*   Updated: 2019/09/19 22:12:27 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*strdst;
	char		*strsrc;

	i = 0;
	strdst = (char*)dst;
	strsrc = (char*)src;
	while (n > i)
	{
		strdst[i] = strsrc[i];
		if ((unsigned char)strsrc[i] == (unsigned char)c)
			return ((char*)dst + i + 1);
		i++;
	}
	return (NULL);
}
