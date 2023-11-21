/*
Fecha de publicación: 12/08/2022
Hora: 5:40 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación

Este programa encuentra el valor del tercer ángulo de un triángulo mediante
los otros dos angulos sabiendo que los 3° forman 180°
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	float a1; //Esta variable guardara el dato insertado por teclado, en este caso el primer ángulo.
	float a2; //Esta variable guardara el dato insertado por teclado, en este caso el segundo ángulo.
	
	printf("Por favor digite el valor del primer angulo: ");
	
	scanf("%f",&a1); //Lee el dato insertado a la variable.
	
	printf("Por favor digite el valor del segundo angulo: ");
	
	scanf("%f",&a2); //Lee el dato insertado a la variable.
	
	printf("\nEl valor del tercer angulo de un triangulo con angulos de %0.1f y %0.1f es de %0.1f.\n\n", a1, a2, 180-a1-a2);
	
	system("pause");
	return 0;
}
