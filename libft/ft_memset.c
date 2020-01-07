/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:16:16 by ahandsom          #+#    #+#             */
/*   Updated: 2019/09/19 15:35:55 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*m;

	m = (char*)b;
	while (len > 0)
	{
		m[len - 1] = c;
		len--;
	}
	return (b);
}