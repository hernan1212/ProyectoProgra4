#include "IniReg.h"
#include <stdio.h>

int main()
{
	int opcion,resultado;
	do
	{
		printf("Introduce una opcion que desea hacer y recuerda que si no tienes una cuenta debes registrarte: \n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
		while(LeerValorInt(&opcion)==-1)
		{
			printf("Error! No es un numero o no es un numero adecuado!\n Introduce una opcion y recuerda que si no tienes una cuenta debes registrarte:\n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
		}
		switch(opcion)
		{
			case 1:
				resultado=IniciarSesion();
				if(resultado==1)
				{
					opcion=3;
				}
				else
				{
					if(resultado==-1)
					{
						printf("El usuario o la contrasena no son correctos, intentalo otra vez.\n");
					}
				}
				break;
			case 2:
				resultado=Registrar();
				if(resultado==1)
				{
					opcion=3;
				}
				break;
			case 3:
				printf("La aplicacion se cerrara!\n" );
				break;
			default:
				printf("Error! No es un numero o no es un numero adecuado!\n");
				break;
		}
	}while(opcion!=3);
}