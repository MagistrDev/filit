/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:19:57 by ahandsom          #+#    #+#             */
/*   Updated: 2019/09/24 22:49:24 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	char	*strnew;

	if (!s)
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]) && s[i] != '\0')
		i++;
	len = ft_strlen(s);
	while (ft_isspace(s[len - 1]) && s[len - 1] != '\0')
		len--;
	if (len <= i)
		len = i;
	strnew = (char*)malloc(len - i + 1);
	if (strnew == NULL)
		return (NULL);
	strnew[len - i] = '\0';
	ft_strncpy(strnew, &s[i], len - i);
	return (strnew);
}
