EXEC	=	nigga

SRCD	=	src

SRCS	=	$(SRCD)/domino_io.c	\
		$(SRCD)/main.c

CC	=	gcc -Wall -Wextra -Werror -Iinc

OBJS	=	$(SRCS:.c=.o)

all:		$(OBJS)
		$(CC) $(OBJS) -o $(EXEC)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(EXEC)

re:		fclean all

.PHONY:		all clean fclean re
