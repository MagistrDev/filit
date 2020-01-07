/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:00:06 by ahandsom          #+#    #+#             */
/*   Updated: 2019/09/21 16:48:11 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = ft_strlen(s1);
	while (len-- && (s1[i] = *s2++))
		i++;
	s1[i] = '\0';
	return (s1);
}
