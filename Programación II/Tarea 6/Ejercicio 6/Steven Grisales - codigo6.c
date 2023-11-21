/*
Fecha de publicación: 17/09/2022
Hora: 3:10 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa lee un número e imprima su factorial, siendo:
N ! = 1 x 2 x 3 x 4 x...N
N ! = 1 si N = 0
Solo está definido el factorial para números enteros positivos.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0; //Esta variable guardará el dato insertado por teclado, en este caso un número
	int con = 1; //Esta variable se toma como un contador que nos ayuda a identificar donde va el producto
	int fac = 1; //Esta variable guardará el factorial
	
	printf("Por favor ingrese el n%cmero al que desea sacar el factorial: ", 163);
	scanf("%i", &n);
	printf("%i! = ", n);
	
	do{
		fac = fac * con; 
		printf("%i x ", con); 
		con = con + 1; 
	} while(con <= n);
	
	printf("= %i \n", fac); 

	system("pause");
	return 0;
}
