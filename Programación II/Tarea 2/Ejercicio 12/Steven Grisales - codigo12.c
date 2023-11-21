/*
Fecha de publicaci�n: 25/08/2022
Hora: 6:29 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa calcula el salario semanal de un obrero dependiendo las horas trabajadas.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int h = 0; //Esta variable guardara el dato insertado por teclado, en este caso las horas.
	int p1 = 0; //Esta variable guardara el dato el c�lculo del pago 1.
	int p2 = 0; //Esta variable guardara el dato el c�lculo del pago 2.
	
	printf("Este programa calcula el salario semanal de un obrero leyendo el %c de horas trabajadas de la siguiente forma:\na. Si trabaja 40 horas o menos se le paga $16 por hora. \nb. Si trabaja mas de 40 horas se le paga $16 por cada una de las primeras 40 horas y $20 por cada hora extra.", 35);
	
	printf("\nSalvedad: No garantizamos el resultado para 'horas negativas'.\n");
	
	printf("\nEntre el n%cmero de horas: ", 163);
	
	scanf("%i", &h); //Lee el dato insertado a la variable.
	
	p1 = h * 16;
	p2 = ((h - 40) * 20) + 640;	
		
	if (h <= 40) //Inicio de la sentencia if junto con su argumentador.
	{
		printf("Su pago sera de: $%i.\n\n", p1);
	}
	else //Inicio de la sentencia else en caso de if ser falso.
	{
		printf("Su pago sera de: $%i.\n\n", p2); 
	}	
	//Finalizaci�n del condicional.
	
	system("pause");	
	return 0;	
}
