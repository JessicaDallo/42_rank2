FTPRINTF = ./ft_printf/ft_printf.a

CC = cc
CCFLAGS = cc -Wall -Werror -Wextra

SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)


all: $(SERVER) $(CLIENT)

$(SERVER) $(CLIENT): $(OBJS_SERVER) $(OBJS_CLIENT) $(FTPRINTF)
		${CCFLAGS} ${OBJS_SERVER} ./ft_printf/ft_printf.a -o ${SERVER}
		${CCFLAGS} ${OBJS_CLIENT} ./ft_printf/ft_printf.a -o ${CLIENT}

$(FTPRINTF):
		${MAKE} -C ./ft_printf

clean:	
		$(MAKE) clean -C ./ft_printf
		rm -rf ${OBJS_SERVER} ${OBJS_CLIENT}

fclean:	clean
		$(MAKE) fclean -C ./ft_printf
		rm -rf $(SERVER) $(CLIENT)

re:	fclean all