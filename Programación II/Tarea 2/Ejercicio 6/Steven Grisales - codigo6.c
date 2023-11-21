/*
Fecha de publicaci�n: 24/08/2022
Hora: 9:42 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa lee un n�mero e imprime si es mayor a 100.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	float n = 0.0; //Esta variable guardara el dato insertado por teclado, en este caso el n�mero.
	
	printf("Este programa determina si un n%cmero es mayor a 100\n", 163);
	
	printf("\nEntre un n%cmero: ", 163);
	
	scanf("%f", &n); //Lee el dato insertado a la variable.
	
	if (n > 100) //Inicio de la sentencia if junto con su argumentador.
	{
		printf("El n%cmero es mayor de 100\n\n", 163);
	}
	else
	{
		printf("El n%cmero es menor de 100\n\n", 163);	
	}
	//Finalizaci�n del condicional.
	
	system("pause");	
	return 0;	
}
