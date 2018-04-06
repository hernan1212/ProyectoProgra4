#include "IniReg.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
	int opcion;
	int resultado;
	printf("Introduce la opcion que desea hacer: \n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
	if (scanf("%i", &opcion) != 1||(opcion<1||opcion>3)) {
   					printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
  					while (getchar() != '\n');
  				}

	do
	{
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
						printf("El usuario o la contraseña no son correctos, intentalo otra vez :).");
					}
					printf("Introduce la opcion que desea hacer: \n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
					if (scanf("%i", &opcion) != 1||(opcion<1||opcion>3)) 
					{
   					printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
  					while (getchar() != '\n');
  					}
				}
				break;
			case 2:
			resultado=Registrar();
			if(resultado==1)
			{
				opcion=3;
			}
			else
			{
				printf("Introduce la opcion que desea hacer: \n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
				if (scanf("%i", &opcion) != 1||(opcion<1||opcion>3)) {
   					printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
  					while (getchar() != '\n');
  				}
			}
			break;
			case 3:
				printf("La aplicacion se cerrara!\n" );
				break;
			default:
				while (scanf("%i", &opcion) != 1||(opcion<1||opcion>3)) {
   					printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
  					while (getchar() != '\n');
					 
 				}
				break;

		}

	}while(opcion!=3);
}