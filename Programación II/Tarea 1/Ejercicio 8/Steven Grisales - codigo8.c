/*
Fecha de publicaci�n: 12/08/2022
Hora: 5:25 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n

Este programa pide 2 datos y realiza la suma, resta, multiplicaci�n y divisi�n mostrando sus resultados
de manera ordenada.
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	float d; //Esta variable guardara el dato insertado por teclado, en este caso el primer n�mero.
	float o; //Esta variable guardara el dato insertado por teclado, en este caso el segundo n�mero.
	
	printf("Por favor digite el primer numero: ");
	
	scanf("%f",&d); //Lee el dato insertado a la variable.
	
	printf("Por favor digite el segundo numero: ");
	
	scanf("%f",&o); //Lee el dato insertado a la variable.
	
	printf("\nSuma: %0.1f \nResta: %0.1f \nMultiplicacion: %0.1f \nDivision: %0.1f\n\n", d+o, d-o, d*o, d/o);
	
	system("pause");
	return 0;
}
