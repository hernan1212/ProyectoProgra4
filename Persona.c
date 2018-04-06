#include "Persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void MostrarUsuario(Usuario u)
{
	printf("Nick: %s,\nContrasena: %s, \nNombre: %s, \nApellido: %s, \nEdad: %i\n", &u.pers.nick, &u.pers.contra, &u.pers.nombre, &u.pers.apellido, u.pers.edad);
}
void MostrarAdmin(Administrador a)
{
	printf("Nick: %s,\nContrasena: %s, \nNombre: %s, \nApellido: %s, \nEdad: %i, \nCodigo de administrador: %s\n", &a.pers.nick, &a.pers.contra, &a.pers.nombre, &a.pers.apellido, a.pers.edad, &a.cod_administrador);
}