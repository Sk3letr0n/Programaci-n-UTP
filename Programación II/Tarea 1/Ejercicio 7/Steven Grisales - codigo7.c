/*
Fecha de publicaci�n: 12/08/2022
Hora: 5:09 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n

Este programa pide nombre, apellido y a�o de nacimiento para despu�s imprimirlos juntos
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	char no[20], ap[30];
	int an;
	
	printf("Por favor digite su nombre: ");
	
	scanf("%s", no);
	
	printf("Por favor digite su apellido: ");
	
	scanf("%s", ap);
	
	printf("Por favor digite su a%co de nacimiento: ", 164);
	
	scanf("%i", &an);
	
	printf("\n%s %s %i\n\n", no, ap, an);
	
	system("pause");
	return 0;
}
