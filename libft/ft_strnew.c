/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:00:40 by ahandsom          #+#    #+#             */
/*   Updated: 2019/10/24 17:34:27 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*mem;

	mem = (char *)malloc(sizeof(char) * (size + 1));
	if (!mem)
		return (NULL);
	ft_bzero(mem, size + 1);
	return (mem);
}
