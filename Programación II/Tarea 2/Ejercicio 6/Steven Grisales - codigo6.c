/*
Fecha de publicación: 24/08/2022
Hora: 9:42 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa lee un número e imprime si es mayor a 100.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	float n = 0.0; //Esta variable guardara el dato insertado por teclado, en este caso el número.
	
	printf("Este programa determina si un n%cmero es mayor a 100\n", 163);
	
	printf("\nEntre un n%cmero: ", 163);
	
	scanf("%f", &n); //Lee el dato insertado a la variable.
	
	if (n > 100) //Inicio de la sentencia if junto con su argumentador.
	{
		printf("El n%cmero es mayor de 100\n\n", 163);
	}
	else
	{
		printf("El n%cmero es menor de 100\n\n", 163);	
	}
	//Finalización del condicional.
	
	system("pause");	
	return 0;	
}
