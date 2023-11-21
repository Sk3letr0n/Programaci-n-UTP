/*
Fecha de publicación: 2/09/2022
Hora: 5:01 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa utilizando ciclos anidados genera las siguientes parejas de enteros: (con un máximo de cuatro(4) ordenes “IMPRIMIR” (printf) en todo el
programa incluyendo las funciones.)
0 1
1 1
2 2
3 2
4 3
5 3
6 4
7 4
8 5
9 5		
*/
#include <stdio.h>
#include <stdlib.h>

void fl(int, int, int);

int main(){
	int n = 0; //Esta variable la usare para saber cuando se incrementan los numeros de la columna derecha.
	
	printf("Este programa muestra pareja de enteros ordenados mediante recursividad.\n\n");
	fl(0, 1, n);
	
	printf("\n\n");
	system("pause");
	return 0;
}
void fl(int x, int y, int n){ //La variable x muestra los #s de la columna izquierda mientras que y los de la derecha
	if(x <= 9){
		if(n < 2){
			printf("%i %i\n", x, y);
			fl(x+1, y, n+1);
		}
		else{
			fl(x, y+1, n = 0);
		}
	}
	else{
	}
	return;
}
