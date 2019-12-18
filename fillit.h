/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:09:30 by ahandsom          #+#    #+#             */
/*   Updated: 2019/11/30 18:00:19 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
#include "./libft/libft.h"

typedef struct s_tetramino
{
    int size;
    int num;
    char **tetramino;
    struct s_tetramino *next;
}               t_etramino;

void    ft_error(int error);
static int  check(char **tetramino, int i, int j);
static void check_tetr(char **tetramino);
static void valid_tetr(char **tetramino);
void    check_full_tetr(t_etramino *head);



#endif