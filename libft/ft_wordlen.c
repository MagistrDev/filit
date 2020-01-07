/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:52:04 by ahandsom          #+#    #+#             */
/*   Updated: 2019/09/26 13:52:29 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wordlen(char const *str, char c, int i)
{
	int length;

	length = 0;
	while (str[i + length] != c && str[i + length])
		length++;
	return (length);
}
