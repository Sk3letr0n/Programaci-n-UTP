/*
Fecha de publicaci�n: 26/08/2022
Hora: 5:22 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa determina cuanto debe pagar un cliente por el estacionamiento de su veh�culo.
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	int h = 0; //Esta variable guardara el dato insertado por teclado, en este caso las horas.
	int m = 0; //Esta variable guardara el dato insertado por teclado, en este caso los minutos.
	int p = 0; //Esta variable guardara el dato insertado por teclado, en este caso el pago.
	
	printf("Este programa determina cuanto debe pagar un cliente por el estacionamiento de su veh%cculo, conociendo el tiempo de estacionamiento en horas y minutos.($1.800 por hora o fracci%cn).", 161, 162);
	
	printf("\n\nInserte las horas que estuvo en el estacionamiento: ");
	
	scanf("%i", &h); //Lee el dato insertado a la variable.
	
	printf("Inserte los minutos que estuvo en el estacionamiento: ");
	
	scanf("%i", &m); //Lee el dato insertado a la variable.
	
	if(m > 0){
		h = h + 1;
	}
	
	p = h * 1800;
	printf("El valor total a pagar en el estacionamiento es: $%i\n\n", p);	
	
	//Finalizaci�n del condicional.
		
	system("pause");
	return 0;
}
