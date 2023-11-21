/*
Fecha de publicaci�n: 12/08/2022
Hora: 2:35 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n

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
	
	/*/El "pow" es potencia que fue insertado con la librer�a math.h
	El 0.2 despu�s del % es para definir la cantidad de decimales del float/*/
	
	system("pause");
	return 0;
}
