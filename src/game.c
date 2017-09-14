/********************
*
* @Proposito: Fichero .c del modulo GAME. Sirve para gestionar 
*	la estructura de datos lineales que se usa en este juego
* @Autor: Nicole Marie Jimenez (n.jimenez.2016)
* @Fecha creacion: 14/9/17
* @Fecha ultima modificacion: 14/9/17
*
********************/

#include "game.h"

/*******************
*
* @Finalidad: Crea una estructura de datos lineales de tipo ListaPDI
* @Parametros: No tiene parametros
* @Retorno: Retorna una lista PDI llamado g
*
*******************/
Game GAME_crea () {
	Game g;
	g.pri = (Nodo *) malloc(sizeof(Nodo));
	if (g.pri != NULL) {
		g.ant = g.pri;
		g.pri->sig = NULL;
	}
	return g;
}

/*******************
*
* @Finalidad: Inserir una nueva ficha a la lista
* @Parametros:	Game g = una lista PDI pasado por referencia
		Ficha e = la ficha que queremos inserir a la lista
* @Retorno: No retorna nada
*
*******************/
void GAME_inserir (Game *g, Ficha e) {
	Nodo *n = NULL;
	n = (Nodo *) malloc (sizeof(Nodo));
	if (n != NULL) {
		n->e = e;
		n->sig = g->ant->sig;
		g->ant->sig = n;
		g->ant = n;
	}
}

/*******************
*
* @Finalidad: Borrar una ficha de la lista
* @Parametros:	Game g = la lista del que queremos borrar una ficha
* @Retorno: No retorna nada
*
*******************/
void GAME_borrar (Game *g) {
	Nodo *n;
	if (g->ant->sig != NULL) {
		n = g->ant->sig;
		g->ant->sig = n->sig;
		free (n);
	}
}

/*******************
*
* @Finalidad: Consultar una ficha de la lista
* @Parametros:	Game g = la lista que queremos consultar
* @Retorno: Retorna la ficha consultada
*
*******************/
Ficha GAME_consultar (Game g) {
	Ficha e;
	if (g.ant->sig == NULL) {
		e.num1 = -1;
		e.num2 = -1;
	}
	else {
		e = g.ant->sig->e;
	}
	return e;
}

/*******************
*
* @Finalidad: Mirar si la lista esta vacia
* @Parametros:	Game g = la lista que queremos mirar 
* @Retorno: Retorna un entero = 1 si esta vacia
				0 si no esta vacia
*
*******************/
int GAME_estaVacia (Game g) {
	return g.pri->sig == NULL;
}

/*******************
*
* @Finalidad: Ir a la primera ficha de la lista
* @Parametros:	Game g = la lista pasada por referencia para modificar
* @Retorno: No retorna nada
*
*******************/
void GAME_irInicio (Game *g) {
	g->ant =g->pri;
}

/*******************
*
* @Finalidad: Avanzar y mirar la siguiente ficha
* @Parametros:	Game g = la lista en que queremos avanzar
* @Retorno: No retorna nada
*
*******************/
void GAME_avanzar (Game *g) {
	if (g->ant->sig != NULL) {
		g->ant = g->ant->sig;
	}
}

/*******************
*
* @Finalidad: Mirar si esta al final de la lista
* @Parametros:	Game g = la lista que queremos mirar si esta al final
* @Retorno: Retorna un entero = 1 si esta al final
				0 si no esta al final
*
*******************/
int GAME_final (Game g) {
	return g.ant->sig == NULL;
}

/*******************
*
* @Finalidad: Destruir la lista creada
* @Parametros:	Game g = la lista que queremos destruir
* @Retorno: No retorna nada
*
*******************/
void GAME_destruye (Game *g) {
	while (g->pri != NULL) {
		g->ant = g->pri;
		g->pri = g->pri->sig;
		free (g->ant);
	}
	g->ant = NULL;
}
