/*
Fecha de publicación: 17/09/2022
Hora: 3:20 p.m.
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

int main(){
	int x = 0; //Esta variable mostrará los numeros de la columna de la izquierda
	int y = 1; //Esta variable mostrará  los numeros de la columna de la derecha
	int i = 1; //Es un iterador que utilizamos para saber cuando incrementamos en la columna derecha
	
	printf ("Este programa muestra por pantalla unas parejas de enteros ya especificadas. \n\n");
	
	//i Es un iterador que utilizamos para saber cuando incrementamos en la columna derecha
	do{       
		printf ("%i %i \n", x , y);  
		x = x + 1;
		                                                                       
		if(i%2 == 0){               
			y = y + 1;                   
		} else {
		}
		i = i + 1; 	 
	} while(x <= 9);
	
	printf("\n\n");
	system("pause");
	return 0;
}
