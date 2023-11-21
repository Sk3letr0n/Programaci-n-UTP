/*
Fecha de publicaci�n: 11/09/2022
Hora: 5:20 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa utilizando ciclos anidados genera las siguientes ternas de enteros: (con un m�ximo de cuatro(4) ordenes �IMPRIMIR� (printf) en todo el
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

int main(){
	int x = 1; //Esta variable mostrar� los numeros de la columna de la izquierda
	int y = 1; //Esta variable mostrar� los numeros de la columna de la mitad
	int z = 1; //Esta variable mostrar� los numeros de la columna derecha
	
	printf ("Este programa muestra por pantalla unas parejas de enteros ya especificadas.\n\n");
	
	//i Es un iterador para saber cuando incrimentamos el valor en la columna de la mitad y de la derecha
	for(int i = 1; x <= 9; i = i + 1){
		printf ("%i %i %i \n", x, y, z);
		x = x + 1;
		z = z + 1; 
		if(i%3 == 0){
			y = y + 1; 
			z = 1; 
		}
    }
	printf("\n\n");
	system("pause");
	return 0;
}
