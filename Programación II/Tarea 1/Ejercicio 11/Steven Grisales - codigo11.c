/*
Fecha de publicaci�n: 12/08/2022
Hora: 6:14 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n

Este programa pide horas, minutos y segundos y muestra el n�mero de milisegundos.
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	int h; //Esta variable guardara el dato insertado por teclado, en este caso las horas.
	int m; //Esta variable guardara el dato insertado por teclado, en este caso los minutos.
	int s; //Esta variable guardara el dato insertado por teclado, en este caso los segundos.
	
	printf("Por favor digite el numero de horas, minutos y segundos que \ndesea convertir a milisegundos.\n");
	
	printf("\nDigite horas: ");
	
	scanf("%i", &h); //Lee el dato insertado a la variable.
	
	printf("Digite minutos: ");
	
	scanf("%i", &m); //Lee el dato insertado a la variable.
	
	printf("Digite segundos: ");
	
	scanf("%i", &s); //Lee el dato insertado a la variable.
	
	printf("\nLa cantidad de milisegundos para %i hora, %i minutos y %i segundos es de %i milisegundos\n\n", h, m, s, (((h * 3600)+(m*60)+s)*1000));
	
	system("pause");
	return 0;
}
