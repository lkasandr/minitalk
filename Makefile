NAME_CLIENT =		client
SRCS_CLIENT =		./client.c

NAME_SERVER =		server
SRCS_SERVER =		./server.c

HEADER =	./minitalk.h

OBJS_CLIENT =		$(SRCS_CLIENT:c=o)
OBJS_SERVER =		$(SRCS_SERVER:c=o)

%.o:		%.c $(HEADER)
			${CC} $(CFLAGS) -c $< -o ${<:.c=.o}

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
OPTFLAGS =  -O2
RM =		rm -f

all :		${NAME_CLIENT} ${NAME_SERVER}

$(NAME_CLIENT) :	$(OBJS_CLIENT) 
			$(CC) $(CFLAGS) $(OPTFLAGS) -o ${NAME_CLIENT} $(OBJS_CLIENT) -I$(HEADER)

$(NAME_SERVER) :	$(OBJS_SERVER) 
			$(CC) $(CFLAGS) $(OPTFLAGS) -o ${NAME_SERVER} $(OBJS_SERVER) -I$(HEADER)

clean :		
			$(RM) $(OBJS_CLIENT)
			$(RM) $(OBJS_SERVER)

fclean 	:	clean
			$(RM) ${NAME_CLIENT}
			$(RM) ${NAME_SERVER}

re :		fclean all

.PHONY :	all clean fclean re 