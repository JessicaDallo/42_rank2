# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 16:55:01 by marvin            #+#    #+#              #
#    Updated: 2024/03/13 16:55:01 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# names #
NAME	= push_swap

# Caminhos para as bibliotecas libft
LIBFT = ./libft/libft.a

# objects / functions #
#$(DIR)algorithm/ordering.c \#
CC	= cc
CFLAGS	= -g -o0 -Wall -Wextra -Werror
RM	= rm -rf
DIR	= sources/

SRCS	= $(DIR)main/push_swap.c \
	$(DIR)main/stack_init.c \
	$(DIR)main/errors_push.c \
	$(DIR)main/stack_utils.c \
	$(DIR)commands/push.c \
	$(DIR)commands/rotates.c \
	$(DIR)commands/swap_moves.c \
	$(DIR)commands/sorted.c \
	$(DIR)commands/rev_rotate.c \
	$(DIR)algorithm/a_to_b.c \
	$(DIR)algorithm/b_to_a.c \
	$(DIR)algorithm/ordering.c \
	$(DIR)algorithm/ordering_utils.c

OBJ 	= $(SRCS:.c=.o)
	
## MAKEFILE RULES ##
all: $(NAME)

## MAKING MAIN PROGRAM ##
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)


# Compilação do libft antes de compilar o push_swap
$(LIBFT):
	$(MAKE) -C ./libft

clean:
	$(RM) $(OBJ)

fclean: clean 
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
