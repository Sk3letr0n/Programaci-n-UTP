/*
Fecha de publicaci�n: 16/09/2022
Hora: 5:13 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa presenta la suma de los elementos de la serie de Fibonacci entre 0 y 100.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = 0; //Esta variable guardara el # fibonacci para despu�s imprimirlo 
	int m = 1; //Esta variable guardara el # en el que se este en ese momento en la serie fibonacci
	int o = 0; //Esta variable guardara el # anterior del que vayamos en la serie fibonacci
	int s = 0; //Esta variable guardara el dato de la suma de los n�meros de la serie fibonacci entre 0 y 100
	
	printf("Este programa presenta la suma de los elementos de la serie de Fibonacci entre 0 y 100.");

	printf("\nLos numeros a sumar son:\n\n");
    
    while(n <= 100){ 
    	printf ("%i, ", n); 
		s = s + n; 
		n = m + o;
		m = o; 
		o = n;
	}
	printf("\nY la suma es: %i", s);
	
	printf("\n\n");
	system("pause");
	return 0;
}
	
