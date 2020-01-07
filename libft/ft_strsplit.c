/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:15:39 by ahandsom          #+#    #+#             */
/*   Updated: 2019/09/26 13:52:56 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			words++;
		while (str[i] != c && str[i])
			i++;
	}
	return (words);
}

static int	ft_next_word(char const *str, char c, int i)
{
	if (i == 0 && str[i] != c && str[i])
		return (i);
	while (str[i] != c && str[i])
		i++;
	while (str[i] == c && str[i])
		i++;
	return (i);
}

static void	*ft_free_words(char **array, int i)
{
	int f;

	f = 0;
	while (f < i)
		free(array[f++]);
	free(array);
	return (NULL);
}

static void	iter_init(int *i, int *index)
{
	*i = 0;
	*index = 0;
}

char		**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		words;
	int		index;
	int		i;
	int		j;

	words = ft_count_words(str, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	iter_init(&i, &index);
	while (i < words && str)
	{
		index = ft_next_word(str, c, index);
		j = 0;
		if (!(tab[i] = (char*)malloc(sizeof(char) * \
			(ft_wordlen(str, c, index) + 1))))
			return (ft_free_words(tab, i));
		while (str[index] != c && str[index])
			tab[i][j++] = str[index++];
		tab[i++][j] = '\0';
	}
	if (!(tab[i] = (char*)malloc(sizeof(char))))
		return (NULL);
	tab[i] = 0;
	return (tab);
}
