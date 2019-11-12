#include "lib.h"
#include <windows.h>

void ft_print_tetr(t_ulli tetr,t_ulli sq, char *ch1, char *ch2)
{
	int i;
	t_ulli x;

	x = 1;
	i = 0;
	while (i < 64)
	{
		if ((i % 8 == 0) && !(sq & x))
			ft_putchar('\n');
		if (sq & x)
			ft_putstr("\e[C!");
		else
			ft_putstr(((tetr & x) ? ch1 : ch2));
		x <<= 1;
		i++;
	}
}

int ft_puttetr(t_ulli *tetbuf, t_ulli *tetr, t_ulli teto, int sq)
{
	t_ulli buf;

	buf = *tetbuf;
	while (!((*tetr | *tetbuf) == (*tetr + *tetbuf)))
	{
		*tetr <<= 1;
		while (*tetr & g_sq[sq])
			*tetr <<= 1;
	}
	if ((*tetr | *tetbuf) == (*tetr + *tetbuf) && ((*tetbuf + *tetr) != *tetbuf))
	{
		*tetbuf |= *tetr;
		return (1);
	}
	return (0);
}

int		main(void)
{
	int x = 16;
	int i;
	int sq = 1;
	int del = 00;
	char str[2] = {0,0};

	t_ulli	tetr[16];
	t_ulli	tetr2[16] = {mas_tetr[0], mas_tetr[0], mas_tetr[0], mas_tetr[0], mas_tetr[0], mas_tetr[0], mas_tetr[0], mas_tetr[0],mas_tetr[0],mas_tetr[0],mas_tetr[0],mas_tetr[0],mas_tetr[0],mas_tetr[0],mas_tetr[0],mas_tetr[0]};
	t_ulli	buf;
	sq = ft_sqrt(x * 4) - 1;
hop:
	sq++;
	buf = g_sq[x];
	i = 0;
	while (i < x)
	{
		tetr[i] = tetr2[i];
		i++;
	}
	home();
	clrscr();
	ft_print_tetr(g_sq[sq], 0, " ", ".");
	ft_putchar('\n');
	buf = 0;
	Sleep(del);

	i = 0;
	while (i < x)
	{
		if (ft_puttetr(&buf, &tetr[i], tetr2[i], sq))
		{
			gotoxy(0,0);
			str[0] = 'A' + i;
			ft_print_tetr(tetr[i], 0, str, "\e[C");
			Sleep(del);
		}
		else
		{	
			i--;
			goto hop;
		}
		i++;
	}
	return (0);
}