/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:08:08 by ecelsa            #+#    #+#             */
/*   Updated: 2019/11/27 21:19:49 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "lib.h"

t_ulli ft_mask(int x)
{
    t_ulli    r;
    int i;

    i = (x >= 0) ? x : -(x);
    r = 0;
    while (i--)
        r |= (t_ulli)1 << (i + ((x > 0) ? (64 - x) : 0));
    return(r);
}

void ft_shift(t_ulli *arr, int arr_size, int shift)
{
	t_ulli mem[2];
	t_ulli mask;
	int i;
	
	i = 0;
	mask = ft_mask(shift);
	mem[0] = 0;
	while(i < arr_size)
	{
		mem[1] = (arr[i] & mask) >> (64 - shift);
		arr[i] <<= shift;
		arr[i] |= mem[0];
		mem[0] = mem[1];
		i++;
	}
}

void ft_print_tetr(t_ulli *tetr, int n, int sq, char *ch1, char *ch2)
{
	int		i;
	int		x;
	int		line;

	home();
	i = 0;
	x = 0;

	while(x < 4)
	{
		i = 0;
		ft_putstr("\x1b[");
		ft_putnbr(n+30);
		ft_putstr("m");
		while (i < 64)
		{
			line = (i / 16 + 1)+ (4 * x);
			if (line > sq)
				break ;
			if (i % 16 == 0)
				gotoxy(0, line);
		//if (i % 16 < sq)
	/*	char hop = *ch;
			if (*ch1 == 0)
				*ch1 == 'A' + n;*/
			ft_putstr(((tetr[x] & ((t_ulli)1 << i)) ? ch1 : ch2));
			i++;
			if (i % 16 == sq)
				i += 16 - sq;
		}
		x++;
	}
	ft_putstr("\x1b[0m");
}
/*
void ft_finprint()
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while(y < sq)
	{
		x = 0;
		while(x < sq)
		{
			f = 0;	
			while(i < x)
			{
				i++;
			}
			x++;
		}
		ft_putstr("\n");
		y++;
	}
}
*/
void ft_puttable(int sq)
{
	int x;
	int y;

	y = 0;
	home();
	clrscr();
	while (y++ < sq)
	{
		x = 0;
		while (x++ < sq)
			write(1, ".", 1);
		write (1, "\n", 1);
	}
}
int ft_tetcmp(t_ulli *table, t_ulli *tetr, int sq)
{
	int 	r;
	int 	i;
	t_ulli	t[2][4];
	
	r = 0;
	i = 0;
	while(i < 4)
	{
		t[0][i] = table[i];
		t[1][i] = tetr[i];
		if (table[i] & tetr[i]) 
			r |= 1;
		if (tetr[i] & g_sq[sq][i])
			r |= 2;
		if (tetr[i] & g_ml[sq][i])
			r |= 4;
		i++;
	}
	return (r);
}

int main(int argc, char **argv)
{
	clock_t begin = clock();
	//t_ulli	**m;
	t_ulli	i[26][4];
	t_ulli	m[26][4];
	t_ulli	table[4] = {0, 0, 0, 0};
	int		sh;
	int		n;
	int 	x = 12;
	int		sq;

	(void)argc;
	(void)argv;
	n = 0;
	//m = (t_ulli**)malloc(sizeof(t_ulli*) * x);
	while (n < x)
	{
	//	m[n] = (t_ulli*)malloc(sizeof(t_ulli) * 4);
		i[n][0] = 0;
		i[n][1] = 0;
		i[n][2] = 0;
		i[n][3] = 0;
		n++;
	}
	i[0][0] = mas_tetr[3];
	i[1][0] = mas_tetr[6];
	i[2][0] = mas_tetr[3];
	i[3][0] = mas_tetr[6];
	i[4][0] = mas_tetr[3];
	i[5][0] = mas_tetr[6];
	i[6][0] = mas_tetr[3];
	i[7][0] = mas_tetr[6];
	i[8][0] = mas_tetr[3];
	i[9][0] = mas_tetr[6];
	i[10][0] = mas_tetr[3];
	i[11][0] = mas_tetr[6];
	i[12][0] = mas_tetr[3];
	i[13][0] = mas_tetr[6];
	i[14][0] = mas_tetr[3];
	i[15][0] = mas_tetr[6];
	i[16][0] = mas_tetr[6];
	i[17][0] = mas_tetr[3];
	i[18][0] = mas_tetr[2];
	i[19][0] = mas_tetr[2];
	
	sq = ft_sqrt(x * 4);
	home();
	clrscr();
	ft_puttable(sq);
	n = 0;
	while(n < x)
	{
		m[n][0] = i[n][0];
		m[n][1] = i[n][1];
		m[n][2] = i[n][2];
		m[n][3] = i[n][3];
		sh = ft_tetcmp(table, m[n],sq);
		while (sh = ft_tetcmp(table, m[n],sq))
			{
				if (sh & 4)
					{
						m[n][0] = i[n][0];
						m[n][1] = i[n][1];
						m[n][2] = i[n][2];
						m[n][3] = i[n][3];
						n--;
						ft_print_tetr(m[n], n, sq, ".", "\e[C");
						table[0] ^= m[n][0];
						table[1] ^= m[n][1];
						table[2] ^= m[n][2];
						table[3] ^= m[n][3];
						if (n == 0)
						{
							sq++;
							home();
							clrscr();
							ft_puttable(sq);
						}
						else
							ft_shift(m[n], 4, 1);						
					}
				//else if(sh == 2)
				//	ft_shift(m[n], 4, (17 - sq));
				else if (sh < 4)
					ft_shift(m[n], 4, 1);
			}
		table[0] |= m[n][0];
		table[1] |= m[n][1];
		table[2] |= m[n][2];
		table[3] |= m[n][3];
		ft_print_tetr(m[n], n, sq, "#", "\e[C");
		n++;
	}

	clock_t end = clock();
	home();
	gotoxy(0,14);
	printf("%f секунд.\n %i", (double)(end - begin) / CLOCKS_PER_SEC,ft_tetcmp(table, m[0],sq));

	return 0;
}