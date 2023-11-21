/*
Fecha de publicaci�n: 23/08/2022
Hora: 8:26 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa determina si un n�mero es impar o par.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int n = 0; //Esta variable guardara el dato insertado por teclado, en este caso el n�mero.
	
	printf("Este programa, lee un n%cmero e imprime si es par o impar.\n", 163);
	
	printf("\nEntre un n%cmero: ", 163);
	
	scanf("%i", &n); //Lee el dato insertado a la variable.
	
	if (n % 2 == 0) //Inicio de la sentencia if junto con su argumentador.
	{
		printf("El n%cmero es par\n\n", 163); //Condici�n verdadera.
	}
	else //Inicio de la sentencia else en caso de if ser falso.
	{
		printf("El n%cmero es impar\n\n", 163); //Condici�n falsa.
	}
	//Finalizaci�n del condicional.
	
	system("pause");	
	return 0;	
}
