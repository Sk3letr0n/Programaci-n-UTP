/*
Fecha de publicaci�n: 31/08/2022
Hora: 9:07 p.m.
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
void tablas(int, int);

int main(){
	printf("Este programa presenta todas las tablas de multiplicar del 1 al 10: \n\n");
	tablas(1, 1);
	
	printf("\n\n");
	
	system("pause");
	return 0;
}

void tablas(int x, int y){
	if(x <= 10){
		if(y <= 10){
			printf("%i x %i = %i \n", x, y, x * y);
			tablas(x, y+1);	
		}
		else{
			printf("\n\n\n");
			tablas(x+1, y = 0);
		}	
	}
	return;
}
