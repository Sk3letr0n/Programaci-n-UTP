/*
Fecha de publicación: 27/08/2022
Hora: 3:21 a.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa lee un número entero positivo de tres cifras y determina si es capicúo.
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	int n = 0; //Esta variable guardara el dato insertado por teclado, en este caso el número.

	printf("Este programa determina si un numero entero positivo de tres cifras es capicuo."), 163, 163;
	
	printf("\nSalvedad: Para n%cmeros negativos no garantizamos resultados", 163);
	
	printf("\n\nEntre el n%cmero positivo de tres cifras: ", 163);
	
	scanf("%i", &n); //Lee el dato insertado a la variable.
	
	int re = (n % 10); //Esta variable guardara el residuo de n % 10.
	int co = (n / 100); //Esta variable guardara el cociente de n / 100.
	
	if(n >= 100 && n <= 999)
	{
		printf("El n%cmero es de tres cifras.\n", 163);
		if (re == co)
		{	
			printf("El n%cmero %i es capic%co.\n\n", 163, n, 163);
		}
		else
		{
			printf("El n%cmero %i no es capic%co.\n\n", 163, n, 163);
		}	
	}
	else
	{
		printf("Tiene que ingresar un n%cmero de 3 cifras.\n\n", 163);	
	}
	
	//Finalización del condicional.
		
	system("pause");
	return 0;
}
