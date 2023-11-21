/*
Fecha de publicación: 23/08/2022
Hora: 8:37 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa lee un número e imprime el día de la semana que corresponde ese número.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int n = 0; //Esta variable guardara el dato insertado por teclado, en este caso el número.
	
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
	//Finalización del condicional.
	
	system("pause");	
	return 0;	
}
