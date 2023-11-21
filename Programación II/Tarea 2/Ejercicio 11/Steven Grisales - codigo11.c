/*
Fecha de publicación: 25/08/2022
Hora: 6:10 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa lee un valor de una compra e indica cuanto paga el cliente dependiendo si tienen el descuento del 20% si pagan más de 100k.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	float v = 0; //Esta variable guardara el dato insertado por teclado, en este caso el valor de la compra.
	
	printf("Este programa lee un valor de una compra y se hace un 20%c de descuento a los clientes cuya compra supere los $100,000 indicando la cantidad que pagara el cliente.\n", 37);
	
	printf("\nEntre el valor de su compra: ");
	
	scanf("%f", &v); //Lee el dato insertado a la variable.	
		
	if (v > 100000) //Inicio de la sentencia if junto con su argumentador.
	{
		printf("La cantidad a pagar por su compra es: %0.0f.\n\n", (v * 0.8));
	}
	else //Inicio de la sentencia else en caso de if ser falso.
	{
		printf("La cantidad a pagar por su compra es: %0.0f.\n\n", v); 
	}	
	//Finalización del condicional.
	
	system("pause");	
	return 0;	
}
