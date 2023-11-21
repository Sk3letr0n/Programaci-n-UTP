/*
Fecha de publicaci�n: 27/08/2022
Hora: 3:21 a.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa lee un n�mero entero positivo de tres cifras y determina si es capic�o.
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	int n = 0; //Esta variable guardara el dato insertado por teclado, en este caso el n�mero.

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
	
	//Finalizaci�n del condicional.
		
	system("pause");
	return 0;
}
