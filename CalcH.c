#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include<unistd.h>
#include<time.h>

int main ()
{
int vidas=1;
int opcion;
int num1;
int num2;
int resultado;
int respuesta;
int control=1;

srand(time(NULL));
num1=rand() % 30;

while(vidas!=0)	
{

opcion=rand() % 4;

switch(opcion)
		{
			case 1:
				num2=rand() % 30*control;
				num2++;
				printf("Cuanto es %d + %d? \n",num1 ,num2 );
				num1=num1+num2;
				break;
			case 2:
				num2=rand() % num1;
				printf("Cuanto es %d - %d? \n",num1 ,num2 );
				num1=num1-num2;
				break;
			case 3:
				num2=rand() % 30*control;
				num2++;
				printf("Cuanto es %d * %d? \n",num1 ,num2 );
				num1=num1*num2;
				break;

			default:
				do{
					num2=rand() %num1;
				  }while((num1%num2)!=0);
				printf("Cuanto es %d / %d? \n",num1 ,num2 );
				num1=num1/num2;

				break;
		}

control++;

	
scanf("%i",&respuesta);

if(respuesta!=num1)
{
	printf("que mal, has fallado, suerte la proxima vez\n");
	sleep(3);
	vidas=0;
}
else
{
	printf("bien, llevas %d correctas\n" , control-1);
}

}


return control-1;
}