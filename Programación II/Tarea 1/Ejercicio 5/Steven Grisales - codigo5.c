/*
Fecha de publicación: 12/08/2022
Hora: 4:27 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación

Este programa pide horas y minutos e imprime el total en minutos
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	int h; //Esta variable guardara el dato insertado por teclado, en este caso las horas.
	int m; //Esta variable guardara el dato insertado por teclado, en este caso los minutos.

	printf("Por favor digite la cantidad de horas: ");
	
	scanf("%i",&h); //Lee el dato insertado a la variable.
	
	printf("Por favor digite la cantidad de minutos: ");
	
	scanf("%i",&m); //Lee el dato insertado a la variable.
	
	printf("\n%i horas y %i minutos equivalen a %i minutos.\n\n", h, m, ((h*60)+m));
	
	system("pause");
	return 0;
}
