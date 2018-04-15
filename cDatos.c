#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int leerpalabrastxt(char* palabra)
{
char aux[20];
int i=0;
int control;
FILE* f;
srand(time(NULL));
control=rand() % 10;
f=fopen("../extras/lista.txt","r");
	if(f==NULL)
	{
		printf("El archivo no existe");
		return 1;
	}
while(fgets(aux, 20, f))
{
	if(i==control)
	{
		sscanf(aux, "%s", palabra);
	}
i++;
}
return 0;
}

//void clearifneeded(char* str)
//{

//}