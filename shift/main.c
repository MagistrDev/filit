/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:08:08 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/07 04:51:16 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "../lib.h"

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
	while ((sh > 64) || (sh < -64))
		sh -= (sh >= 0) ? 64 : -64;
	mask = ft_mask(sh);
	while (i != 0)
	{
		if (sh == 64)
			arr[i - 1 ] = (i - 1 > 0) ? arr[i - 2] : 0;
		else
		{
			
			arr[i - 1] <<= sh;
			if (i - 1)
				arr[i - 1] |= (arr[i - 2] & mask) >> (64 - sh);
		}
		i -= (i > 0) ? 1 : -1;
	}
	if (shift > 63)
		ft_shift(arr, arr_size, shift - sh);
}

int			main(int argc, char **argv)
{
	t_uint64 bla[4] = {0xff, 0, 0, 0};
	bla[0] >>= 63;
	printf("!%016llx\n", bla[0]);
	return (0);
}
