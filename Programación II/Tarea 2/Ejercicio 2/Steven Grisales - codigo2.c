/*
Fecha de publicación: 23/08/2022
Hora: 8:26 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa determina si un número es impar o par.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int n = 0; //Esta variable guardara el dato insertado por teclado, en este caso el número.
	
	printf("Este programa, lee un n%cmero e imprime si es par o impar.\n", 163);
	
	printf("\nEntre un n%cmero: ", 163);
	
	scanf("%i", &n); //Lee el dato insertado a la variable.
	
	if (n % 2 == 0) //Inicio de la sentencia if junto con su argumentador.
	{
		printf("El n%cmero es par\n\n", 163); //Condición verdadera.
	}
	else //Inicio de la sentencia else en caso de if ser falso.
	{
		printf("El n%cmero es impar\n\n", 163); //Condición falsa.
	}
	//Finalización del condicional.
	
	system("pause");	
	return 0;	
}
