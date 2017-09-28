/********************
*
* @Proposito: Fichero .h del modulo LOGICA. Dedicada para toda
*	la logica y el funcionamiento del juego en si.
* @Autor: Nicole Marie Jimenez (n.jimenez.2016)
* @Fecha creacion: 14/9/17
* @Fecha ultima modificacion: 28/9/17
*
********************/

#ifndef _LOGICA_H
#define _LOGICA_H

#define MAXDOMINO 28
#define MAXNOMBRE 20

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "game.h"

typedef struct {
	char *name;
	int turn;
	Game dominoes;
} Player;

typedef struct {
	Game deck;
	Game board;
	Player *players;
} Partida;

// Prototipos
void crearPartida (Partida *partida);
void crearFichas (Ficha deck[MAXDOMINO]);
int initPlayers (Player **players, FILE *file_jugadors);
void shuffleFichas (Ficha deck[MAXDOMINO], int max);

#endif
