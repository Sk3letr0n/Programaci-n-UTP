/*
Fecha de publicación: 16/09/2022
Hora: 5:23 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa presenta todas las tablas de multiplicar del 1 al 10
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int x = 1; //Es el numero al que le vamos a sacar la tabla de multiplicar
	int y = 1; //Va a ser el numero que va a multiplicar al numero que le estamos sacando la tabla de multiplicar
	printf("Este programa presenta todas las tablas de multiplicar del 1 al 10: \n\n");
	
	while(x <= 10){
		while(y <= 10){
			printf ("%i x %i = %i \n", x, y, x * y); 
			y = y + 1;
		}
		printf("\n\n");
		x = x + 1;
		y = 1;
	}

	system("pause");
	return 0;                                            
}                                                          
