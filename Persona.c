#include "Persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void MostrarUsuario(Usuario u)
{
	if(u.bloq)
	{
		printf("Nick: %s, \nContrasena: %s, \nNombre: %s, \nApellido: %s, \nEdad: %i,\nEste usuario esta bloqueado\n", &u.pers.nick, &u.pers.contra, &u.pers.nombre, &u.pers.apellido, u.pers.edad);
	}
	else
	{
		printf("Nick: %s,\nContrasena: %s, \nNombre: %s, \nApellido: %s, \nEdad: %i,\nEste usuario no esta bloqueado\n", &u.pers.nick, &u.pers.contra, &u.pers.nombre, &u.pers.apellido, u.pers.edad);
	}

}
void MostrarAdmin(Administrador a)
{
	printf("Nick: %s,\nContrasena: %s, \nNombre: %s, \nApellido: %s, \nEdad: %i, \nCodigo de administrador: %s\n", &a.pers.nick, &a.pers.contra, &a.pers.nombre, &a.pers.apellido, a.pers.edad, &a.cod_administrador);
}