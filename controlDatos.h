#ifndef _CONTROLDATOS_H_
#define _CONTROLDATOS_H_
#include "Persona.h"

int LeerUsuariosBin(Usuario* users);
int LeerAdministradoresBin(Administrador* admins);
int escribirUsuariosBin(Usuario* users, int len);
int escribirAdministradoresBin(Administrador* admins, int len);
int LeerDatostxt(char* nombrefic);
int EscribirDatostxt(char* nombrefic);
void clearifneeded(char* str);

#endif