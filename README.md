# NJ_Domino

Un juego de domino diseñado para ser un proyecto en la universidad. Inacabado.
Como un "side project", lo terminaré aquí. El objetivo de este proyecto es jugar con las estructuras de datos lineales y la
gestión de memoria. Es un juego de 2 a 4 jugadores.

========================================================================================================

Funcionalidades

- Para ejecutar el juego, hay que pasar 2 paramteros: ranking.bin y jugadors.txt
- El menu principal tiene 3 opciones, 1 para empezar nueva partida, 2 para mostrar el ranking de los jugadores y 3 para salir del juego
- En total hay 28 fichas. Una ficha [5|1] puede considerar como  [1|5]
  No hay fichas repetidas
- jugadors.txt
        Formato del fichero: .txt
        Contenido:
              <numero de jugadores>
              <nombre del jugador>/<orden en partida>
- ranking.bin
        Formato del fichero: .bin
        Contenido:
              <numero de jugadores>
              <Jugador 1>
              <Jugador 2>
                .
                .
              <Jugador n>
        
        Informacion de cada jugador: - nombre, partidas ganadas, perdidas
 
- Al comenzar, cada jugador tiene 5 fichas
- Poner fichas, robar fichas, pasar el turno

Si un jugador se queda sin fichas, el jugador ha ganado!!
