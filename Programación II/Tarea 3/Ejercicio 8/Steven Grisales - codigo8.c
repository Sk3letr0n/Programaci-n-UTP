/*
Fecha de publicaci�n: 2/09/2022
Hora: 5:01 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa utilizando ciclos anidados genera las siguientes parejas de enteros: (con un m�ximo de cuatro(4) ordenes �IMPRIMIR� (printf) en todo el
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
