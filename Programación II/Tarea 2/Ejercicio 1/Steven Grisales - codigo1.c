/*
Fecha de publicación: 23/08/2022
Hora: 7:50 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa determina que número es primo entre el 1 y el 5.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int n = 0; //Esta variable guardara el dato insertado por teclado, en este caso el número entre 1 a 5.
	
	printf("Este programa, lee un n%cmero entre uno(1) y cinco(5), e imprime si es primo o no.", 163);
	
	printf("\nSalvedad: Para valores fuera de este rango (1, 5), no garantizamos la determinacion de si es primo o no.");
	
	printf("\n \nEntre un n%cmero: ", 163);
	
	scanf("%i", &n); //Lee el dato insertado a la variable.
	
	if (n == 2 || n == 3 || n == 5) //Inicio de la sentencia if junto con su argumentador.
	{
		printf("\nEl n%cmero es primo \n\n", 163); //Condición verdadera.
	}
	else //Inicio de la sentencia else en caso de If ser falso.
	{
		printf("\nEl n%cmero no es primo \n\n", 163); //Condición falsa.
	}
	//Finalización del condicional.
	
	system("pause");	
	return 0;	
}
