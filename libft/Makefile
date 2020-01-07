# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 14:37:07 by ahandsom          #+#    #+#              #
#    Updated: 2019/09/26 13:53:43 by ahandsom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra -I $(HFILES)

ADDAR = ar -rc

SRCS =	ft_strncpy.c 	\
		ft_strlen.c		\
		ft_strdup.c		\
		ft_strcpy.c		\
		ft_putstr.c		\
		ft_putchar.c 	\
		ft_putchar_fd.c	\
		ft_memset.c		\
		ft_memcpy.c 	\
		ft_isupper.c	\
		ft_isspace.c	\
		ft_islower.c	\
		ft_isdigit.c	\
		ft_isascii.c	\
		ft_isalpha.c	\
		ft_atoi.c		\
		ft_memccpy.c	\
		ft_memcmp.c		\
		ft_bzero.c		\
		ft_strjoin.c	\
		ft_memalloc.c	\
		ft_strnew.c		\
		ft_striteri.c	\
		ft_striter.c	\
		ft_memmove.c	\
		ft_strcat.c		\
		ft_strncat.c	\
		ft_memdel.c		\
		ft_memchr.c		\
		ft_strlcat.c	\
		ft_isalnum.c	\
		ft_isprint.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strstr.c		\
		ft_strnstr.c	\
		ft_strcmp.c		\
		ft_strncmp.c	\
		ft_putstr_fd.c	\
		ft_putendl.c	\
		ft_putnbr.c		\
		ft_putnbr_fd.c	\
		ft_strdel.c		\
		ft_strclr.c		\
		ft_strmap.c		\
		ft_strmapi.c	\
		ft_itoa.c		\
		ft_strsub.c		\
		ft_strtrim.c	\
		ft_itoa.c		\
		ft_strsplit.c	\
		ft_strnequ.c	\
		ft_strequ.c		\
		ft_putendl_fd.c	\
		ft_wordlen.c

HFILES = ./

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(SRCS) $(NAME)
$(NAME): $(OBJS)
		$(ADDAR) $@ $^

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
