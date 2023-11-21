/*
Fecha de publicación: 2/09/2022
Hora: 5:20 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa utilizando ciclos anidados genera las siguientes ternas de enteros: (con un máximo de cuatro(4) ordenes “IMPRIMIR” (printf) en todo el
programa incluyendo las funciones.)
1 1 1
2 1 2
3 1 3
4 2 1
5 2 2
6 2 3
7 3 1
8 3 2
9 3 3	
*/
#include <stdio.h>
#include <stdlib.h>

void fl(int, int, int, int);

int main(){
	int n = 1; //Esta variable la usare para saber cuando se incrementan los numeros de la columna derecha.
	
	printf("Este programa muestra ternas de enteros ordenados mediante recursividad.\n\n");
	fl(1, 1, 1, n);
	
	printf("\n\n");
	system("pause");
	return 0;
}
void fl(int x, int y, int z, int n){ //La variable x muestra los #s de la columna izquierda mientras que y los del medio y z los de la derecha
	if(x <= 9){
		if(n <= 3){
			printf("%i %i %i\n", x, y, z);
			fl(x+1, y, z+1, n+1);
		}
		else{
			fl(x, y+1, z = 1, n = 1);
		}
	}
	else{
	}
	return;
}
