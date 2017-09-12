all: Practica3

main.o: main.c domino_io.h
	gcc main.c -c

domino_io.o: domino_io.c domino_io.h
	gcc domino_io.c -c

Practica3: main.o domino_io.o
	gcc main.o domino_io.o -o p3
