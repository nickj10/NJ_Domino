/********************
*
* @Proposito: Fichero .c del modulo LOGICA. Dedicada a la implementacion
*	de toda la logica y funcionamiento del juego en si.
* @Autor: Nicole Marie Jimenez (n.jimenez.2016)
* @Fecha creacion: 14/9/17
* @Fecha ultima modificacion: 14/9/17
*
********************/

#include "logica.h"

/*******************
*
* @Finalidad: Crea la partida de domino
* @Parametros: No tiene parametros
* @Retorno: Retorna una partida inicializada
*
*******************/
void crearPartida (Partida *partida) {
	Ficha deck[MAXDOMINO];

	// Crear las fichas y ordenarlas aleatoriamente
	crearFichas (deck);

	// Crear la lista de las fichas
	partida->deck = GAME_crea ();
	
	// Inicializar los jugadores y repartir las fichas
	//initPlayers (partida.players, partida.deck);

	// Inicializar el board
	//partida->board = GAME_crea ();
	//GAME_inserir (&partida.board, GAME_consultar (partida.deck));
	//printf ("after?\n");
}

/*******************
*
* @Finalidad: Crear las fichas y ordenarlas aleatoriamente
* @Parametros:	deck = un array de tipo Ficha, tamano maximo de 28
* @Retorno: No retorna nada
*
*******************/
void crearFichas (Ficha deck[MAXDOMINO]) {
	int i = 0, j, k;
	while (i < MAXDOMINO) {
		for (j = 0; j <= 6; j++) {
			for (k = j; k <= 6; k++) {
				deck[i].num2 = k;
				deck[i].num1 = j;
				i++;
			}
		}
	}
	
	for (i = 0; i < MAXDOMINO; i++) {
		printf ("[%d|%d] ", deck[i].num1, deck[i].num2);
	}
}
