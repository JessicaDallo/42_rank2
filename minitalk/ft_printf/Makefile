# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 17:25:22 by marvin            #+#    #+#              #
#    Updated: 2023/10/28 17:25:22 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
AR	= ar
ARFLAGS	= -rcs
RM	= rm
RMFLAGS = -f

OBJ	= ft_printf.o ft_typedef.o ft_putint.o ft_putchar.o ft_putstr.o ft_putuns.o ft_puthexa.o ft_putptr.o\
	ft_count_nbr.o ft_strlen.o ft_atoi.o ft_strdup.o ft_itoa.o ft_memset.o ft_bzero.o ft_calloc.o\

all : $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)
	
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(RMFLAGS) $(OBJ)
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all