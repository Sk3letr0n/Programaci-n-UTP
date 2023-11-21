/*
Fecha de publicaci�n: 23/08/2022
Hora: 7:50 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa determina que n�mero es primo entre el 1 y el 5.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int n = 0; //Esta variable guardara el dato insertado por teclado, en este caso el n�mero entre 1 a 5.
	
	printf("Este programa, lee un n%cmero entre uno(1) y cinco(5), e imprime si es primo o no.", 163);
	
	printf("\nSalvedad: Para valores fuera de este rango (1, 5), no garantizamos la determinacion de si es primo o no.");
	
	printf("\n \nEntre un n%cmero: ", 163);
	
	scanf("%i", &n); //Lee el dato insertado a la variable.
	
	if (n == 2 || n == 3 || n == 5) //Inicio de la sentencia if junto con su argumentador.
	{
		printf("\nEl n%cmero es primo \n\n", 163); //Condici�n verdadera.
	}
	else //Inicio de la sentencia else en caso de If ser falso.
	{
		printf("\nEl n%cmero no es primo \n\n", 163); //Condici�n falsa.
	}
	//Finalizaci�n del condicional.
	
	system("pause");	
	return 0;	
}
