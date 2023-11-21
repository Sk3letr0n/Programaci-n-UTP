/*
Fecha de publicación: 11/09/2022
Hora: 3:15 p.m.
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
int main(){
	printf("Este programa presenta todas las tablas de multiplicar del 1 al 10: \n\n");
	
	//x es un iterador, es el numero al que le vamos a sacar la tabla de multiplicar
	//y es un iterador con el cual va a ser el numero que va a multiplicar al numero que le estamos sacando la tabla de multiplicar
	
	for(int x = 1; x <= 10; x = x + 1){                        
		for(int y = 1; y <= 10; y = y + 1){                    
			printf ("%i x %i = %i \n", x, y, x * y);
		}                                                 
		printf("\n\n");                   
	}                                                      
	printf("\n");
	system("pause");
	return 0;                                            
}                                                          
