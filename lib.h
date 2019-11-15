#ifndef LIB_H
# define LIB_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
#define ESC "\033"

typedef unsigned long long int t_ulli;

const t_ulli g_sq[17][4] = {
	{-1, -1, -1, -1}, {-2, -1,-1, -1},
	{0xFFFFFFFFFFFCFFFC, -1, -1, -1},
	{0xFFFFFFF8FFF8FFF8, -1, -1, -1},
 	{0xFFF0FFF0FFF0FFF0,  -1, -1, -1},
 	{0xFFE0FFE0FFE0FFE0, 0xFFFFFFFFFFFFFFE0, -1, -1},
 	{0xFFC0FFC0FFC0FFC0, 0xFFFFFFFFFFC0FFC0, -1, -1},
 	{0xFF80FF80FF80FF80, 0xFFFFFF80FF80FF80, -1, -1},
 	{0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00, -1, -1},
 	{0xFE00FE00FE00FE00, 0xFE00FE00FE00FE00, 0xFFFFFFFFFFFFFE00, -1},
 	{0xFC00FC00FC00FC00, 0xFC00FC00FC00FC00, 0xFFFFFFFFFC00FC00, -1},
 	{0xF800F800F800F800, 0xF800F800F800F800, 0xFFFFF800F800F800, -1},
 	{0xF000F000F000F000, 0xF000F000F000F000, 0xF000F000F000F000, -1},
 	{0xE000E000E000E000, 0xE000E000E000E000, 0xE000E000E000E000, 0xFFFFFFFFFFFFE000},
 	{0xC000C000C000C000, 0xC000C000C000C000, 0xC000C000C000C000, 0xFFFFFFFFC000C000},
 	{0x8000800080008000, 0x8000800080008000, 0x8000800080008000, 0xFFFF800080008000},
 	{0, 0, 0, 0}
 };

const t_ulli	mas_tetr[19] = {
	0xf, 0x1000100010001, 0x30003, 0x10007, 0x40007, 0x70001, 0x70004,
	0x300010001, 0x100010003, 0x200020003, 0x300020002, 0x20007,
	0x200030002, 0x70002, 0x100030001, 0x60003, 0x100030002, 0x30006,
	0x200030001
};

void ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t		ft_strlen(const char *s)
{
	size_t a;

	a = 0;
	while (*(s + a))
		a++;
	return (a);
}


void ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if ((nb / 10) > 0)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}


int		ft_sqrt(int nbr)
{
	int	sqrt;

	sqrt = 1;
	while (sqrt * sqrt < nbr)
		sqrt++;
	return (sqrt);
}


void clrscr()
{
	ft_putchar('\e');
	ft_putchar('[');
	ft_putchar('2');
	ft_putchar('J');
}

void home()
{
	ft_putchar('\e');
	ft_putchar('[');
	ft_putchar('H');
}

void gotoxy(int x, int y)
{
	ft_putchar('\e');
	ft_putchar('[');
	ft_putnbr(y);
	ft_putchar(';');
	ft_putnbr(x);
	ft_putchar('H');
}



#endif