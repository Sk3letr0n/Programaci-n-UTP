/*
Fecha de publicación: 12/08/2022
Hora: 5:25 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación

Este programa pide 2 datos y realiza la suma, resta, multiplicación y división mostrando sus resultados
de manera ordenada.
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	float d; //Esta variable guardara el dato insertado por teclado, en este caso el primer número.
	float o; //Esta variable guardara el dato insertado por teclado, en este caso el segundo número.
	
	printf("Por favor digite el primer numero: ");
	
	scanf("%f",&d); //Lee el dato insertado a la variable.
	
	printf("Por favor digite el segundo numero: ");
	
	scanf("%f",&o); //Lee el dato insertado a la variable.
	
	printf("\nSuma: %0.1f \nResta: %0.1f \nMultiplicacion: %0.1f \nDivision: %0.1f\n\n", d+o, d-o, d*o, d/o);
	
	system("pause");
	return 0;
}
