/*
Fecha de publicaci�n: 12/08/2022
Hora: 2:19 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n

Este programa realiza una conversi�n de grados Celsius a grados Fahrenheit
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	float c; //Esta variable guardara el dato insertado por teclado, en este caso los grados celsius.
	
	printf("Por favor digite los centigrados a convertir a Fahrenheit: ");
	
	scanf("%f",&c); //Lee el dato insertado a la variable.
	
	printf("\n%0.0f%cC son %0.1f grados Fahrenheit\n\n", c, 248, (((9.0*c) /5.0) +32));

	system("pause");	
	return 0;
}
