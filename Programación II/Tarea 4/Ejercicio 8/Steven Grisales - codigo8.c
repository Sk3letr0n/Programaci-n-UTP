/*
Fecha de publicaci�n: 11/09/2022
Hora: 4:35 p.m.
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

int main(){
	int x = 0; //Esta variable mostrar� los numeros de la columna de la izquierda
	int y = 1; //Esta variable mostrar�  los numeros de la columna de la derecha
	
	printf ("Este programa muestra por pantalla unas parejas de enteros ya especificadas. \n\n");
	
	//i Es un iterador que utilizamos para saber cuando incrementamos en la columna derecha
	for(int i = 1; x <= 9; i = i + 1){       
		printf ("%i %i \n", x , y);     
		x = x + 1;                                                                     
		if(i%2 == 0){               
			y = y + 1;                  
		} else {
		}	
	}
	printf("\n\n");
	system("pause");
	return 0;
}
