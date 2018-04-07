#ifndef _MENUP_H_
#define _MENUP_H_
#include "Persona.h"
#include "Juego.h"
#include <stdbool.h>
int MenuU(Usuario u);
int MenuA(Administrador a);
void ListaJuegos(Juego* j, int control1);
void Jugar(Juego* j, int control1);
void PerfilU(Usuario u);
void PerfilA(Administrador a);
void Estadisticas();
int SubirJuego(Juego* j, Persona p, int control1);
void GestionAplicacion(Juego* j, int control1);
#endif