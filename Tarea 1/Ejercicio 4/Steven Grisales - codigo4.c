/*
Fecha de publicación: 12/08/2022
Hora: 4:13 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación

Este programa hace la conversión de Km/h a mph teniendo en cuenta que
1Km = 0.621371 millas
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	float k; //Esta variable guardara el dato insertado por teclado, en este caso los kilometros.

	printf("Por favor digite cuantos Km/h quiere convertir a mph: ");
	
	scanf("%f",&k); //Lee el dato insertado a la variable.
	
	printf("\n%0.1fKm/h equivalen a %0.2f mph.\n\n", k, k*0.621371);
	
	system("pause");
	return 0;
}
