/*
Fecha de publicación: 10/09/2022
Hora: 9:45 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa presenta la serie de Fibonacci hasta llegar y sin sobrepasar 10000.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = 0; //Esta variable guardara el # fibonacci para después imprimirlo 
	int m = 1; //Esta variable guardara el # en el que se este en ese momento en la serie fibonacci
	int o = 0; //Esta variable guardara el # anterior del que vayamos en la serie fibonacci
    
    printf("Este programa presenta la serie de Fibonacci como la serie que comienza con los digitos 1 y 0 y va \nsumando progresivamente los dos ultimos elementos de la serie, asi: 0 1 1 2 3 5 8 13 21 34.......\n");
    printf("\nPara este programa, se presentara la serie de Fibonacci hasta llegar sin sobrepasar el numero 10,000\n\n");
    
    for(; n <= 10000; ){ 
    	printf ("%i, ", n); 
 		n = m + o; 
		m = o; 
		o = n; 
	}
	printf("\n\n");
	system("pause");
	return 0;
}
