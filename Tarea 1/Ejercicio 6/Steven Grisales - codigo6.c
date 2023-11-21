/*
Fecha de publicaci�n: 12/08/2022
Hora: 4:45 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n

Este programa recibe minutos e imprime el total de horas y minutos.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main (){
	float m; //Esta variable guardara el dato insertado por teclado, en este caso los minutos.
	
	printf("Por favor digite la cantidad de minutos: ");
	
	scanf("%f",&m); //Lee el dato insertado a la variable.
	
	double x = m/60;//Esta variable guardara el dato decimal de m/60 para as� separar su parte entera y decimal.
	double m2, h; //Estas dos variables almacenan las partes separadas
	m2 = modf(x, &h); //Mandamos el apuntador de h
	//modf devuelve la parte decimal (m2), y pone la parte entera (h) en la variable cuya direcci�n mandamos
	
	printf("\n%0.0f minutos equivalen a %0.0f horas y %0.0f minutos.\n\n", m, h, m2*60);
	
	system("pause");
	return 0;
}
