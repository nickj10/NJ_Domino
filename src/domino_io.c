/********************
*
* @Proposito: Fichero .c del modulo DOMINO_IO. Sirve para gestionar
	la recepcion de los datos y ademas, para imprimir a la 
	pantalla
* @Autor: Nicole Marie Jimenez (n.jimenez.2016)
* @Fecha creacion: 9/9/17
* @Fecha ultima modificacion: 11/9/17
*
********************/

#include "domino_io.h"

void getOpcion (char *opcion) {
	do {
		printf ("Bienvenido al NJ Domino!\n");
		printf ("\t1. Nueva partida\n");
		printf ("\t2. Mostrar ranking\n");
		printf ("\t3. Salir\n");
		scanf ("%s", opcion);
		if (strcmp (opcion, "1") != 0 && strcmp (opcion, "2") != 0 && strcmp (opcion, "3") != 0) {
			printf ("Error, opcion incorrecta. [1..3]\n");
		}
	} while (strcmp (opcion, "1") != 0 && strcmp (opcion, "2") != 0 && strcmp (opcion, "3") != 0);
}
