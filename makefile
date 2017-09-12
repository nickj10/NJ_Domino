all: Practica3

main.o: src/main.c include/domino_io.h
	gcc main.c -c

domino_io.o: src/domino_io.c include/domino_io.h
	gcc domino_io.c -c

Practica3: main.o domino_io.o
	gcc main.o domino_io.o -o p3
