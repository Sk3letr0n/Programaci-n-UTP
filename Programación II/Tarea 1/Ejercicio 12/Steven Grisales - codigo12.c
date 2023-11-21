/*
Fecha de publicaci�n: 12/08/2022
Hora: 6:32 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n

Este programa representa esta operaci�n: 
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
	float r; //En esta variable guardar� el resultado de la operaci�n
	
	r = ( ( (17.0/11) + (23.0/2) ) / ( (943.0/120) + (sqrt(144)) ) );

	printf("El resultado de la operaci%cn ( ( (17/11) + (23/2) ) / ( ( 943/120) + (sqrt(144)) ) ) es: %f\n\n", 162, r);
	
	system("pause");
	return 0;
}

