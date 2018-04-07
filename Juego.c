#include "Juego.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void PrintJuego(Juego j)
{
	printf("Nombre: %s, Genero: %s, Nick del creador: %s, Precio: %i euros\n", &j.nombre, &j.genero, &j.Creador.nick, j.Precio);
}