/*
Fecha de publicaci�n: 23/08/2022
Hora: 8:37 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa lee un n�mero e imprime el d�a de la semana que corresponde ese n�mero.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int n = 0; //Esta variable guardara el dato insertado por teclado, en este caso el n�mero.
	
	printf("Este programa, lee un n%cmero entre [1 y 7] e imprime el d%ca que le corresponde en la semana. \nReferencia: 1=Lunes. 7=Domingo", 163, 161);
	
	printf("\nSalvedad: Para valores fuera de este rango (1, 7), no garantizamos el resultado del d%ca.\n", 161);
	
	printf("\nEntre un n%cmero: ", 163);
	
	scanf("%i", &n); //Lee el dato insertado a la variable.
	
	if (n == 1) //Inicio de la sentencia if junto con su argumentador.
	{
		printf("Lunes\n\n");
	}
	else //Inicio de la sentencia else en caso de if ser falso.
	{
		if (n == 2)
		{
			printf("Martes\n\n"); 
		}
		else
		{
			if (n == 3)
			{
				printf("Mi%crcoles \n\n", 130); 
			}
			else
			{
				if (n == 4)
				{
				printf("Jueves \n\n");	
				}
				else
				{
					if (n == 5)
					{
						printf("Viernes \n\n");
					}
					else
					{
						if (n == 6)
						{
							printf("S%cbado \n\n", 160);
						}
						else
						{
							if (n == 7)
							{
								printf("Domingo \n\n");
							}
							else
							{
								printf("Se sale del rango especificado\n\n");
							}	
						}
					}
				}
			}
		}
	}
	//Finalizaci�n del condicional.
	
	system("pause");	
	return 0;	
}
