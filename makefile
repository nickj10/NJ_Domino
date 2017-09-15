EXEC	=	nigga	#nombre del ejecutable

SRCD	=	src	#donde se encuentran los ficheros .c

SRCS	=	$(SRCD)/domino_io.c	\
		$(SRCD)/logica.c	\
		$(SRCD)/game.c		\
		$(SRCD)/main.c

CC	=	gcc -Wall -Wextra -Werror -Iinc 2> errorlog.txt
		#-Werror nos da error si hay alguna variable no inicializada
		# 2> errorlog.txt escribe los errores en un fichero aunque
		# no esten visibles en el terminal 

OBJS	=	$(SRCS:.c=.o)	#crea los .o a partir de los .c

all:		$(OBJS)
		$(CC) $(OBJS) -o $(EXEC)
clean:
		rm -f $(OBJS)	#suprime los ficheros .o

fclean:		clean
		rm -f $(EXEC)	# suprime el ejecutable

re:		fclean all	# suprime los .o/.exe y lo compila de nuevo

.PHONY:		all clean fclean re
