#include "Partida.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void MostrarPartidaAhorcado(pAhorcado p)
{
	printf("Nick de la persona: %s, Partidas jugadas: %s, Partidas ganadas: %s\n", &p.Jugador.nick, p.PartidasJugadas, p.PartidasGanadas);
}
void MostrarPartidaCalculadora(pCalc p)
{
	printf("Nick de la persona: %s, Partidas jugadas: %s, Puntuacion maxima: %s\n", &p.Jugador.nick, p.PartidasJugadas, p.PuntMax);
}