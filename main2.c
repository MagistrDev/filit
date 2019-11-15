# include <time.h>
#include "lib.h"

//#include <time.h>

t_ulli ft_mask(int x)
{
    t_ulli    r;
    int i;

    i = (x >= 0) ? x : -(x);
    r = 0;
    while (i--)
        r |= 1 << i + ((x > 0) ? (64 - x) : 0);
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

void ft_print_tetr(t_ulli *tetr, int sq, char *ch1, char *ch2)
{
	int		i;
	int		x;
	int		line;
	t_ulli	*fig;

	home();
	i = 0;
	x = 0;

	while(x < 4)
	{
		i = 0;
		while (i < 64)
		{
			line = (i / 16 + 1)+ (4 * x);
			if (line > sq)
				break ;
			if (i % 16 == 0)
				gotoxy(0, line);
		//if (i % 16 < sq)
			ft_putstr(((tetr[x] & ((t_ulli)1 << i)) ? ch1 : ch2));
			i++;
			if (i % 16 == sq)
				i += 16 - sq;
		}
		x++;
	}
}

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

int main(int argc, char **argv)
{
	clock_t begin = clock();
	t_ulli	**m;
	t_ulli	xx;
	int		n;
	int		bla = 0;
	int 	x = 26;
	int		sq = 1;

	n = 0;
	m = (t_ulli**)malloc(sizeof(t_ulli*) * x);
	while (n < x)
	{
		m[n] = (t_ulli*)malloc(sizeof(t_ulli) * 4);
		m[n][0] = mas_tetr[1];
		m[n][1] = 0;
		m[n][2] = 0;
		m[n][3] = 0;
		n++;
	}
	/*
	m[0] = mas_tetr[0];
	m[1] = mas_tetr[2];
	m[2] = mas_tetr[5];
	m[3] = mas_tetr[9];
	*/
	sq = ft_sqrt(x * 4);

	home();
	clrscr();
	ft_puttable(sq);
	for (int cc = 0; cc < 128; cc++)
	{
		ft_print_tetr(m[0], sq, "#", "\e[C");
		ft_shift(m[0], 4, 1);
		for (t_ulli sleep = 0; sleep < 70000000; sleep++) ;
		ft_print_tetr(m[0], sq, ".", "\e[C");
	}	
	clock_t end = clock();
	home();
	gotoxy(0,14);

	printf("%f секунд.\n", (double)(end - begin) / CLOCKS_PER_SEC);
	printf("%llx\n", m[0][0]);
	return 0;
}