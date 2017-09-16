/********************
*
* @Proposito: Funcion principal del juego
* @Autor: Nicole Marie Jimenez (n.jimenez.2016)
* @Fecha creacion: 9/9/17
* @Fecha ultima modificacion: 16/9/17
*
********************/

#include "domino_io.h"
#include "logica.h"

int main (int argc, char *argv[]) {
	int i = 0;
	char *f_ranks = (char *) malloc (sizeof(char) * MAXNOM);
	char *f_jugadors = (char *) malloc (sizeof(char) * MAXNOM);
	FILE *file_ranking;
	FILE *file_jugadors;
	char *opcion = (char *) malloc (sizeof(char) * MAXNOM);
	Partida partida;
	int hayRanks = 0;
	//int numJugadores;
	
	// Coger los nombres de los ficheros en los parametros
	while (i < argc) {
		if (strcmp(argv[i], "ranking.bin") == 0) {
			hayRanks++;
			strcpy(f_ranks, argv[i]);
		}
		if (strcmp(argv[i], "jugadors.txt") == 0) {
			strcpy(f_jugadors, argv[i]);
		}
		i++;
	}
	
	if (!hayRanks) {
		strcpy (f_ranks, "ranking.bin");	// Se asigna el nombre del fichero
	}
		
	printf ("%s \n", f_ranks);
	
	// Comprobar si los ficheros existen
	file_jugadors = fopen (f_jugadors, "r");
	if (file_jugadors == NULL) {
		printf ("No existe el fichero de los jugadores.\n");
	}
	else {
		file_ranking = fopen (f_ranks, "ab+");
		if (file_ranking == NULL) {
			printf ("No existe el fichero del ranking.\n");
			printf ("Se creara un nuevo fichero ranking.bin\n");
		}
		else {
			// Empezar el juego
			do {
				getOpcion(opcion);
				switch (opcion[0]) {
					case '1':
						initPlayers (&partida.players, file_jugadors);	
						crearPartida (&partida);
						GAME_irInicio (&partida.deck);
						
						/****DEBUG FICHAS*****
						while (!GAME_final (partida.deck)) {
							aux = GAME_consultar (partida.deck);
							printf ("[%d|%d] ", aux.num1, aux.num2);
							GAME_avanzar (&partida.deck);
						}
						*********************/
						
						/****DEBUG PLAYERS****
						for (int index = 0; index < numJugadores; index++) {
							printf ("%s - %d \n", partida.players[index].name, partida.players[index].turn);
						}
						*********************/
						break;
					case '2':
						break;
					case '3':
						printf ("Gracias por jugar!\n");
				}
			} while (strcmp (opcion, "3") != 0);		
		}
	}
	
}
