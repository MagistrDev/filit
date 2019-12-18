/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:06:52 by ahandsom          #+#    #+#             */
/*   Updated: 2019/11/30 18:00:16 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_error(int error)
{
    if (err == 0)
		ft_putstr("\n");
	else if (err == -1)
		ft_putstr("\n");
	else if (err == 1)
		ft_putstr("\n");
	else if (err == 2)
		ft_putstr("\n");
	exit(1);
}

static int  check(char **tetramino, int i, int j)
{
    int start;

    start = 0;
    if ((j + 1) < 4)
        if (tetramino[i][j + 1] == '#')
            start++;
    if ((i + 1) < 4)
        if (tetramino[i + 1][j] == '#')
            start++;
    if ((i - 1) >= 0)
        if (tetramino[i - 1][j] == '#')
            start++;
    if ((j - 1) >= 0)
        if(tetramino[i][j - 1] == '#')
            start++;
    return (start);
}

static void check_tetr(char **tetramino)
{
    int i;
    int j;
    int side;

    i = 0;
    side = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if(tetramino[i][j] == '#')
                side = side + check(tetramino, i, j);
            j++;
        }
        i++;
    }
    if (side != 8 && side != 6)
        ft_error(1);
}

static void valid_tetr(char **tetramino)
{
    int i;
    int j;
    int start;

    i = 0;
    start = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if(tetramino[i][j] == '#')
                start++;
            if (tetramino[i][j] != '.' && tetramino[i][j] != '#')
                ft_error(1);
            j++;
        }
        i++;
    }
    if (start != 4)
        ft_error(1);
}

void    check_full_tetr(t_etramino *head)
{
    while (head)
    {
        valid_tetr(head->tetramino);
        check_tetr(head->tetramino);
        head = head->next;
    }
}
/*
int     countchars(char *buff)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while(i < 19)
    {
        if (buff[i] && buff[i] != '\n' && buff[i] != '.' && buff[i] != '#')
            return(0);
        if (buff[i] == '\n' && ((i + 1) % 5 != 0))
            return(0);
        if (buff[i] == '#')
            count++;
        i++;
    }
    if(!buff[i] || buff[i] != '\n')
        return(0);
    return (count);
}
int     valid_tetrominoes(char *buf)
{
    
}
*/