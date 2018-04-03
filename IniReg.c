#include "IniReg.h"
#include <stdio.h>
#include <stdlib.h>

void IniciarSesion()
{
	Persona pers;
	printf("Has decidido iniciar sesion\n");
	printf("Inserte el nick:");
	scanf("%s",&pers.nick);
}
void Registrar()
{
	int opcionRegistro;
	Persona pers;
	printf("Has decidido registrarte\n");
	printf("Elige una opcion:\n 1.-Si deseas registrarte como un usuario. \n 2.- Si deseas registrarte como un administrador. \n");
	scanf("%i",&opcionRegistro);
	if(opcionRegistro==1)
	{
		Usuario usu;
		printf("Has elegido registrarte como un usuario.\n");
		printf("Inserte el nick del usuario:");
		scanf("%s",&pers.nick);
		printf("Inserte la contraseña del usuario:");
		scanf("%s",&pers.contra);
		printf("Inserte el nombre del usuario:");
		scanf("%s",&pers.nombre);
		printf("Inserte el apellido del usuario:");
		scanf("%s",&pers.apellido);
		printf("Inserte la edad del usuario:");
		scanf("%i",&pers.edad);
		usu.pers=pers;
	}
	else if(opcionRegistro)
	{
		Administrador admin;
		printf("Has elegido registrarte como un administrador.\n");
	}
}