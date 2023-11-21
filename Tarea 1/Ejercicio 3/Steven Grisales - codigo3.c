/*
Fecha de publicación: 12/08/2022
Hora: 2:58p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación

Este programa permite calcular el perímetro de un rectángulo tomando su lado y ancho
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	float l; //Esta variable guardara el dato insertado por teclado, en este caso el largo del rectángulo.
	float a; //Esta variable guardara el dato insertado por teclado, en este caso el ancho del rectángulo.
	
	printf("Por favor digite el largo del rectangulo: ");
	
	scanf("%f",&l); //Lee el dato insertado a la variable.
	
	printf("Por favor digite el ancho del rectangulo: ");
	
	scanf("%f",&a); //Lee el dato insertado a la variable.
	
	printf("\nEl perimetro de un rectangulo con largo %0.1f y ancho %0.1f es de %0.1f.\n\n", l, a,(l + l + a + a));
	
	system("pause");
	return 0;
}
