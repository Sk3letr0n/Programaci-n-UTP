/*
Fecha de publicaci�n: 16/09/2022
Hora: 5:23 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

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
