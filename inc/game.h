/********************
*
* @Proposito: Fichero .h del modulo GAME. Sirve para gestionar
*	la estructura de datos lineales que se usa en este
*	juego
* @Autor: Nicole Marie Jimenez (n.jimenez.2016)
* @Fecha creacion: 14/9/17
* @Fecha ultima modificacion: 14/9/17
*
********************/

#ifndef _GAME_H
#define _GAME_H

#include <stdlib.h>

typedef struct {
	int num1;
	int num2;
} Ficha;

typedef struct _Nodo {
	Ficha e;
	struct _Nodo *sig;
} Nodo;

typedef struct {
	Nodo *pri;
	Nodo *ant;
} Game;

Game GAME_crea ();
void GAME_inserir (Game *g, Ficha e);
void GAME_borrar (Game *g);
Ficha GAME_consultar (Game g);
int GAME_estaVacia (Game g);
void GAME_irInicio (Game *g);
void GAME_avanzar (Game *g);
int GAME_final (Game g);
void GAME_destruye (Game *g);

#endif
