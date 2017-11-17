/********************
*
* @Proposito: Fichero .c del modulo LOGICA. Dedicada a la implementacion
*	de toda la logica y funcionamiento del juego en si.
* @Autor: Nicole Marie Jimenez (n.jimenez.2016)
* @Fecha creacion: 14/9/17
* @Fecha ultima modificacion: 28/9/17
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

/*******************
*
* @Finalidad: Inicializar los jugadores y repartir las fichas a cada 
*	jugador
* @Parametros:	players = un array dinamica de tipo Player que contiene la
*			informacion de cada jugador
*		file_jugadors = fichero de texto que contiene la informacion
*			de los jugadores
* @Retorno: No retorna nada
*
*******************/
int initPlayers (Player **players, FILE *file_jugadors) {
	int numJugadores, i;
	char aux[MAXNOMBRE];
	char *aux2 = (char *) malloc (sizeof(char));
	// Como ya esta abierto el fichero, no hace falta hacer un fopen
	if (file_jugadors == NULL) {
		printf ("No se encuentra el fichero de jugadores");
		return 0;
	}
	else {
		fscanf (file_jugadors,"%d", &numJugadores);
		*players = (Player *) malloc (sizeof(Player) * numJugadores);
		if (!(*players)) {
			printf ("No se ha podido guardar espacio para los jugadores.\n");
		} else {
			for (i = 0; i < numJugadores; i++) {
				// Pedir memoria para el nombre del jugador
				players[i]->name = (char *) malloc (sizeof(char) * MAXNOMBRE);
				if (!(players[i]->name)) {
					printf ("Error, no hay memoria para el nombre\n");
				} else {
					// Coger toda la linia y separarlo
					fscanf (file_jugadors, "%s", aux);
					aux2 = strtok (aux, "/");
					players[i]->name = aux2;
					aux2 = strtok (NULL, "\n");
					players[i]->turn = atoi(aux2);

					printf ("name %d: %s \n", i+1, players[i]->name);
					printf ("turn: %d\n", players[i]->turn);
				}	
			}
			
		}
		return numJugadores;
	}
}
