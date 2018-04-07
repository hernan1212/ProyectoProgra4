#ifndef _CONTROLDATOS_H_
#define _CONTROLDATOS_H_
#include "Persona.h"
#include "Juego.h"
#include "Partida.h"
int LeerUsuariosBin(Usuario* users);
int LeerAdministradoresBin(Administrador* admins);
int LeerJuegosBin(Juego* juegos);
int LeerPartidasBin(pAhorcado* pa);
int escribirUsuariosBin(Usuario* users, int len);
int escribirAdministradoresBin(Administrador* admins, int len);
int escribirJuegosBin(Juego* juegos, int len);
int escribirPartidasBin(pAhorcado* pa, int len);
int LeerDatostxt(char* nombrefic);
int EscribirDatostxt(char* nombrefic);
void clearifneeded(char* str);

#endif