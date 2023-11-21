/*
Fecha de publicación: 12/08/2022
Hora: 5:09 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación

Este programa pide nombre, apellido y año de nacimiento para después imprimirlos juntos
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
