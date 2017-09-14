/********************
*
* @Proposito: Fichero .h del modulo DOMINO_IO. Sirve para gestionar
	la recepcion de los datos y ademas, para imprimir a la 
	pantalla
* @Autor: Nicole Marie Jimenez (n.jimenez.2016)
* @Fecha creacion: 9/9/17
* @Fecha ultima modificacion: 14/9/17
*
********************/

#ifndef _DOMINO_IO_H
#define _DOMINO_IO_H

// Librerias del sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes
#define MAXNOM 20

// Tipos propios
typedef struct {
	char *name;
	int turn;
} Player;

// Prototipos de funciones
void getOpcion (char *);

#endif
