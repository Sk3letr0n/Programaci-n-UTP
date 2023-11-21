/*
Fecha de publicación: 12/08/2022
Hora: 2:19 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación

Este programa realiza una conversión de grados Celsius a grados Fahrenheit
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
