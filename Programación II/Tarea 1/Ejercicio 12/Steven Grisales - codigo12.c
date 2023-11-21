/*
Fecha de publicación: 12/08/2022
Hora: 6:32 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación

Este programa representa esta operación: 
 17      23
---  +  ---
 11      2
 ----------- = 0.656925
 943
 ---  + v144
 120
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main (){
	float r; //En esta variable guardaré el resultado de la operación
	
	r = ( ( (17.0/11) + (23.0/2) ) / ( (943.0/120) + (sqrt(144)) ) );

	printf("El resultado de la operaci%cn ( ( (17/11) + (23/2) ) / ( ( 943/120) + (sqrt(144)) ) ) es: %f\n\n", 162, r);
	
	system("pause");
	return 0;
}

