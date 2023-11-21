/*
Fecha de publicaci�n: 24/08/2022
Hora: 10:00 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa lee dos n�meros y determina si ambos son pares o impares .
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int n = 0; //Esta variable guardara el dato insertado por teclado, en este caso el primer n�mero.
	int m = 0; //Esta variable guardara el dato insertado por teclado, en este caso el segundo n�mero.
	
	printf("Este programa determina si dos n%cmeros son pares o son impares\n", 163);
	
	printf("\nEntre el primer n%cmero: ", 163);
	
	scanf("%i", &n); //Lee el dato insertado a la variable.
	
	printf("Entre el segundo n%cmero: ", 163);
	
	scanf("%i", &m); //Lee el dato insertado a la variable.
	
	if (n % 2 == 0 && m % 2 == 0) //Inicio de la sentencia if junto con su argumentador.
	{
		printf("Ambos n%cmeros son pares\n\n", 163);
	}
	else //Inicio de la sentencia else en caso de if ser falso.
	{
		if (n % 2 != 0 && m % 2 != 0)
		{ 
			printf("Ambos n%cmeros son impares\n\n", 163); 
		}
		else
		{
			printf("\n");
		}
	}	
	//Finalizaci�n del condicional.
	
	system("pause");	
	return 0;	
}
