/*
Fecha de publicaci�n: 12/08/2022
Hora: 2:58p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n

Este programa permite calcular el per�metro de un rect�ngulo tomando su lado y ancho
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	float l; //Esta variable guardara el dato insertado por teclado, en este caso el largo del rect�ngulo.
	float a; //Esta variable guardara el dato insertado por teclado, en este caso el ancho del rect�ngulo.
	
	printf("Por favor digite el largo del rectangulo: ");
	
	scanf("%f",&l); //Lee el dato insertado a la variable.
	
	printf("Por favor digite el ancho del rectangulo: ");
	
	scanf("%f",&a); //Lee el dato insertado a la variable.
	
	printf("\nEl perimetro de un rectangulo con largo %0.1f y ancho %0.1f es de %0.1f.\n\n", l, a,(l + l + a + a));
	
	system("pause");
	return 0;
}
