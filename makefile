EXEC	=	nigga

SRCD	=	src

SRCS	=	$(SRCD)/domino_io.c	\
		$(SRCD)/main.c

CC	=	gcc -Wall -Wextra -Werror -Iinc

OBJS	=	$(SRCS:.c=.o)

all:		$(OBJS) #calls the objs dependency, converts all .c into .o
		$(CC) $(OBJS) -o $(EXEC) #gcc ... *.o -o exec_name

clean:
		rm -f $(OBJS) #rm *.o

fclean:		clean #calls the clean rule, rm's all .o files
		rm -f $(EXEC_NAME) #rm's the executable

re:		fclean all #rm's everything and recompiles

.PHONY:		all clean fclean re #PHONY is always needed for security reasons
