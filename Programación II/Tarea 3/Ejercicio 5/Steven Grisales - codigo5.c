/*
Fecha de publicación: 31/08/2022
Hora: 9:07 p.m.
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
