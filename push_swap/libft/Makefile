# nome #
NAME = libft.a 

CC	= cc 
CFLAGS	= -Wall -Wextra -Werror
AR	= ar 
ARFLAGS	= -rcs
RM	= rm -rf

SRCS	= ft_atol.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_itoa.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strlcpy.c \
	ft_striteri.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strmapi.c \
	ft_substr.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_printf.c \
	ft_typedef.c \
	ft_putchar.c \
	ft_putint.c \
	ft_putstr.c \
	ft_putuns.c \
	ft_puthexa.c \
	ft_putptr.c \
	ft_count_nbr.c

SRCS_BONUS	= ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

# Arquivos de objeto gerados a partir dos arquivos de origem
OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)

 # makefile regras #
all: $(NAME)

clean:
	$(RM) $(OBJ) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

 # compilando os objetos (funçoes) #
$(NAME): $(OBJ)
	$(AR)  $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


bonus: $(OBJ) $(OBJ_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_BONUS)

.PHONY: all clean fclean re
