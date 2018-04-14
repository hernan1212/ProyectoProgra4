#include "IniReg.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
	int * opcion;
	int resultado;
	printf("Introduce la opcion que desea hacer y recuerda que si no tienes una cuenta debes registrarte: \n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
	LeerValorInt(opcion);

	do
	{
		switch(*opcion)
		{
			case 1:
				resultado=IniciarSesion();
				if(resultado==1)
				{
					*opcion=3;
				}
				else
				{
					if(resultado==-1)
					{
						printf("El usuario o la contrasena no son correctos, intentalo otra vez.\n");
					}
					printf("Introduce la opcion que desea hacer y recuerda que si no tienes una cuenta debes registrarte: \n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
					LeerValorInt(opcion);
				}
				break;
			case 2:
			resultado=Registrar();
			if(resultado==1)
			{
				*opcion=3;
			}
			else
			{
				printf("Introduce la opcion que desea hacer y recuerda que si no tienes una cuenta debes registrarte: \n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
				LeerValorInt(opcion);
			}
			break;
			case 3:
				printf("La aplicacion se cerrara!\n" );
				break;
			default:
			printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion y recuerda que si no tienes una cuenta debes registrarte:\n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
				LeerValorInt(opcion);
		}
	}while(*opcion!=3);
}