#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cDatos.h"

int main ()
{
char* palabra;
char* resultado;
char letra;
char aux;
int restantes;
int vidas=3;
bool control=false;
int tam;

leerpalabrastxt(palabra);
tam=strlen(palabra);
restantes=tam;
resultado=malloc(strlen(palabra)-1);

printf ("Estas jugando al ahorcado, tu palabra tiene wololo letras\n");
for(int i =0; palabra[i]!='\0';i++)
{
resultado[i]='X';
}

while(vidas!=0 && restantes!=0)	
{

	control=false;
	if(letra!='\n')
	{
	for(int i =0; palabra[i]!='\0';i++)
	{
	printf("%c",resultado[i]);

	}

	printf("\n");
	printf ("Introduce una letra\n");
	}

	letra=getchar();
	if(letra=='\n')
	{
		control=true;
	}	
	
	for(int i =0; i<tam ;i++)
	{
		if(palabra[i]==letra)
		{
			resultado[i]=letra;
			palabra[i]=' ';
			control=true;
			restantes--;
		}
	}
	if(control==false)
		{
			vidas--;
			printf("la letra %c no esta, pierdes una vida, te quedan una vida menos \n", &letra, &vidas);
			
		}

}

if(vidas==0)
{
printf ("Has perdido\n");	
return 0;
}
if(restantes==0)
{
printf ("Has ganado\n");
return 1;
}
return 0;
}



