#include "IniReg.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int * opcion;

	opcion=malloc(sizeof(int));

	printf("Introduce la opcion que desea hacer: \n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
	scanf("%i",opcion);

	do
	{
		switch(*opcion)
		{
			case 1:
				IniciarSesion();
				break;
			case 2:
				Registrar();
				break;
			case 3:
				printf("La aplicacion se cerrara!\n" );
				break;
			default:
				while (scanf("%i", opcion) != 1) {
   					printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
  					while (getchar() != '\n');
					 
 				}
				break;

		}

	}while(*opcion!=3);
}