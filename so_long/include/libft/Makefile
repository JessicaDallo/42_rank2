NAME = libft.a 

CC	= cc 
CFLAGS	= -Wall -Wextra -Werror
AR	= ar 
ARFLAGS	= -rcs
RM	= rm
RMFLAGS	= -f

OBJ	= ft_atoi.o ft_bzero.o ft_calloc.o ft_itoa.o ft_isalpha.o ft_isdigit.o \
	ft_isalnum.o ft_isascii.o ft_isprint.o ft_memcpy.o ft_memmove.o ft_memset.o *ft_memchr.o ft_memcmp.o \
	ft_putendl_fd.o ft_putnbr_fd.o ft_putchar_fd.o ft_putstr_fd.o *ft_split.o ft_strchr.o ft_strlen.o \
	ft_strncmp.o ft_strlcat.o ft_strnstr.o ft_strrchr.o ft_strlcpy.o ft_striteri.o ft_strdup.o ft_strjoin.o \
	ft_strtrim.o ft_strmapi.o ft_substr.o ft_toupper.o ft_tolower.o \
	ft_printf.o ft_typedef.o ft_putint.o ft_putchar.o ft_putstr.o ft_putuns.o ft_puthexa.o ft_putptr.o \
	ft_count_nbr.o\
	get_next_line.o get_next_line_utils.o

OBJ_BONUS = *ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o \
	ft_lstiter.o ft_lstmap.o

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(RMFLAGS) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

bonus: $(OBJ) $(OBJ_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_BONUS)
