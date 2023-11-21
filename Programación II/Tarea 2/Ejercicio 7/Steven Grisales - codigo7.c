/*
Fecha de publicación: 24/08/2022
Hora: 10:00 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa lee dos números y determina si ambos son pares o impares .
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int n = 0; //Esta variable guardara el dato insertado por teclado, en este caso el primer número.
	int m = 0; //Esta variable guardara el dato insertado por teclado, en este caso el segundo número.
	
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
	//Finalización del condicional.
	
	system("pause");	
	return 0;	
}
