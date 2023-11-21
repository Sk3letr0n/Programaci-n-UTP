/*
Fecha de publicación: 12/08/2022
Hora: 2:35 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación

Este programa calcula el volumen de una esfera mediante la formula 4/3*pi*r^3
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main (){
	float v; //Esta variable guardara el dato insertado por teclado, en este caso el radio de la esfera.
	
	printf("Por favor digite el radio de la esfera: ");
	
	scanf("%f",&v); //Lee el dato insertado a la variable.
	
	printf("\nEl volumen de una esfera de radio %0.2f es de %f\n\n", v, (((4.0*3.1415926) /3.0) * pow(v,3) ));
	
	/*/El "pow" es potencia que fue insertado con la librería math.h
	El 0.2 después del % es para definir la cantidad de decimales del float/*/
	
	system("pause");
	return 0;
}
