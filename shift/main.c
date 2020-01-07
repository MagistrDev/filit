/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:44:30 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/07 02:55:31 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef unsigned long long t_uint64;

t_uint64	ft_mask(int x)
{
	t_uint64	r;
	int			i;

	i = (x >= 0) ? x : -(x);
	r = 0;
	while (i--)
		r |= (t_uint64)1 << (i + ((x > 0) ? (64 - x) : 0));
	return (r);
}

void		ft_shift(t_uint64 *arr, int arr_size, int shift)
{
	t_uint64	mask;
	int			sh;
	int			i;

	i = arr_size;
	sh = shift;
	while (sh > 64)
		sh -= 64;
	mask = ft_mask(sh);
	while (--i >= 0)
	{
		if (sh == 64)
			arr[i] = (i > 0) ? arr[i - 1] : 0;
		else
		{
			arr[i] <<= sh;
			if (i)
				arr[i] |= (arr[i - 1] & mask) >> (64 - sh);
		}
	}
	if (shift > 63)
		ft_shift(arr, arr_size, shift - sh);
}

int			main(int agrc, char **agrv)
{
	t_uint64 bla[4] = {0xff00000000000000, 1, 0, 1};
	t_uint64 hop;
	int sh;

	hop = 1;
	printf("%016llx %016llx %016llx %016llx\n", bla[0], bla[1], bla[2], bla[3]);
	scanf("%i", &sh);
	ft_shift(bla, 4, sh);
	printf("%016llx %016llx %016llx %016llx\n", bla[0], bla[1], bla[2], bla[3]);
	return (0);
}
