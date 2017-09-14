EXEC	=	nigga

SRCD	=	src

SRCS	=	$(SRCD)/domino_io.c	\
		$(SRCD)/logica.c	\
		$(SRCD)/game.c		\
		$(SRCD)/main.c

CC	=	gcc -Wall -Wextra -Werror -Iinc -fno-stack-protector

OBJS	=	$(SRCS:.c=.o)

all:		$(OBJS)
		$(CC) $(OBJS) -o $(EXEC)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(EXEC)

re:		fclean all

.PHONY:		all clean fclean re
