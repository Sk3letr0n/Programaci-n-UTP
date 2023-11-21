/*
Fecha de publicación: 25/08/2022
Hora: 5:46 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa lee 3 notas de un alumno a las cual les hace promedio para saber si aprueba o desaprueba.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	float n1 = 0; //Esta variable guardara el dato insertado por teclado, en este caso la primera nota.
	float n2 = 0; //Esta variable guardara el dato insertado por teclado, en este caso la segunda nota.
	float n3 = 0; //Esta variable guardara el dato insertado por teclado, en este caso la tercer nota.
	float prom = 0; //Esta variable guardara el dato insertado por teclado, en este caso el promedio de las notas.
	
	printf("Este programa lee tres notas, hace el promedio de estas y determina si el alumno aprueba si el promedio es 3.0 o mayor y desaprueba en caso contrario.\n", 130);
	
	printf("Salvedad: Al ser notas academicas, no se garantizan los resultados con n%cmeros negativos.\n", 163);
	
	printf("\nEntre la primera nota: ", 130);
	
	scanf("%f", &n1); //Lee el dato insertado a la variable.
	
	printf("Entre la segunda nota: ");
	
	scanf("%f", &n2); //Lee el dato insertado a la variable.
	
	printf("Entre la tercer nota: ");
	
	scanf("%f", &n3); //Lee el dato insertado a la variable.
	
	prom = (n1 + n2 + n3) / 3;	
		
	if (prom >= 3.0) //Inicio de la sentencia if junto con su argumentador.
	{
		printf("El promedio del alumno es: %0.1f por lo tanto aprueba.\n\n", prom);
	}
	else //Inicio de la sentencia else en caso de if ser falso.
	{
		printf("El promedio del alumno es: %0.1f por lo tanto reprueba.\n\n", prom); 
	}	
	//Finalización del condicional.
	
	system("pause");	
	return 0;	
}
