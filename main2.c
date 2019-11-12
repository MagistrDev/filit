#include "lib.h"
#include <windows.h>
#include <time.h>

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

int main(int argc, char **argv)
{
	clock_t begin = clock();
	t_ulli	*m;
	int		n;
	int 	x = 4;
	int		sq = 1;


	m = (t_ulli*)malloc(sizeof(t_ulli) * x);
	m[0] = mas_tetr[0];
	m[1] = mas_tetr[2];
	m[2] = mas_tetr[5];
	m[3] = mas_tetr[9];


	home();
	clrscr();
	ft_print_tetr(g_sq[sq], 0, " ", ".");
	
	ft_shift(m, 4, 32);
	
	clock_t end = clock();
	printf("\n%f секунд.\n", (double)(end - begin) / CLOCKS_PER_SEC);
	return 0;
}