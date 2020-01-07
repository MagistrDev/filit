/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:28:26 by ahandsom          #+#    #+#             */
/*   Updated: 2019/09/20 19:49:37 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (d > s)
		while (len--)
			*(d + len) = *(s + len);
	else if (d != s)
		while (len--)
			*d++ = *s++;
	return (dst);
}
