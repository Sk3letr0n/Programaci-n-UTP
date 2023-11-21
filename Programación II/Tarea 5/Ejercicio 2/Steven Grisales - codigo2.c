/*
Fecha de publicación: 16/09/2022
Hora: 5:13 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa presenta la suma de los elementos de la serie de Fibonacci entre 0 y 100.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = 0; //Esta variable guardara el # fibonacci para después imprimirlo 
	int m = 1; //Esta variable guardara el # en el que se este en ese momento en la serie fibonacci
	int o = 0; //Esta variable guardara el # anterior del que vayamos en la serie fibonacci
	int s = 0; //Esta variable guardara el dato de la suma de los números de la serie fibonacci entre 0 y 100
	
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
	
