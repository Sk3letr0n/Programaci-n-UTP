/*
Fecha de publicaci�n: 16/09/2022
Hora: 5:29 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa lee un n�mero entero N, no negativo(validar
esto) y muestra la suma de los factoriales de todos los n�meros desde 0 hasta N. as�:

Si n = 5
= 0! + 1! + 2! + 3! + 4! + 5!
= 1 + 1 + 2 + 6 + 24 + 120 = 154
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	char b = 'F'; //Nos permite saber si el numero es valido para sacar su factorial
	int n = 0; //Esta variable guardar� el dato insertado por teclado, en este caso un n�mero	
	int fac = 1; //Esta variable guardar� el dato del factorial
	int suma = 0; //Esta variable guardar� el dato de la suma de los factoriales de cada numero
	int i = 1; //Es un iterador que nos sirve para sacarle el factorial a cada numero
	
	printf("Salvedad: Para un valor mayor a 13 no se garantizan los resultados\n");
	
	while(b == 'F'){
    	printf ("Por favor digite un numero entero positivo: ");
	    scanf ("%i", &n);
	    if(n >= 0){
	    	b = 'V';
	    }
	}
	while(i <= n){ 
		fac = fac * i; 
		suma = suma + fac; 
		i = i + 1;
	}
	suma = suma + 1; 
	printf ("\nLa suma de los factoriales desde 0 hasta su numero es: %i ", suma);
	
	printf("\n\n");
	system("pause");
	return 0;
}
