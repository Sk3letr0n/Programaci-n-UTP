/*
Fecha de publicación: 14/08/2022
Hora: 3:55 a.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación

Este programa permite hallar el resultado de una función
segun el valor que se le asigne a la x y muestra el valor a asignado a x
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main (){
	float x; //Esta variable guardara el dato insertado por teclado 
	double r; //En esta variable guardaré el resultado de la operación
	
	printf("Por favor digite el valor que le quiere asignar a x: ");
	
	scanf("%float", &x);
	
	r = (((((((x/6 + 45/x) / (x - (-8/2)) / 12) / sqrt (x)) / 5.0) + pow(x,4)) / sqrt (x)));
	
	printf("\nEl resultado de la ecuaci%cn para un valor de %0.1f es: %f\n\n", 162, x, r);
	//Vgr. Salvedad: No cubrimos resultados con x siendo negativo.
	
	system("pause");
	return 0;
}
