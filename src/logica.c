/********************
*
* @Proposito: Fichero .c del modulo LOGICA. Dedicada a la implementacion
*	de toda la logica y funcionamiento del juego en si.
* @Autor: Nicole Marie Jimenez (n.jimenez.2016)
* @Fecha creacion: 14/9/17
* @Fecha ultima modificacion: 15/9/17
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
	int i;

	// Crear las fichas y ordenarlas aleatoriamente
	crearFichas (deck);

	// Crear la lista de las fichas
	partida->deck = GAME_crea ();
	for (i= 0; i < MAXDOMINO; i++) {
		GAME_inserir (&partida->deck, deck[i]);
	}	
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
	for (j = 0; j <= 6; j++) {
		for (k = j; k <= 6; k++) {
			deck[i].num2 = k;
			deck[i].num1 = j;
			i++;
		}
	}
	
	// Ordenarlas aleatoriamente
	shuffleFichas (deck, MAXDOMINO);

}

/*******************
*
* @Finalidad: Ordenar las fichas aleatoriamente
* @Parametros:	deck = un array de tipo Ficha, tamano maximo de 28
* @Retorno: No retorna nada
*
*******************/
void shuffleFichas (Ficha deck[MAXDOMINO], int max) {
	int i, j;
	Ficha temp;
	
	srand (time(NULL));
	if (max > 1) {
		for (i = 0; i < max - 1; i++) {
			// Elegir aleatoriamente un numero de casilla
			j = (i + rand()) % MAXDOMINO;
		
			// Hacer un intercambio con esa casilla
			temp = deck[j];
			deck[j] = deck[i];
			deck[i] = temp;
		}
	}

}
