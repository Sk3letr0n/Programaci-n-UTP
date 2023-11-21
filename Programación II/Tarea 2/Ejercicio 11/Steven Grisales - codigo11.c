/*
Fecha de publicaci�n: 25/08/2022
Hora: 6:10 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa lee un valor de una compra e indica cuanto paga el cliente dependiendo si tienen el descuento del 20% si pagan m�s de 100k.
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
	//Finalizaci�n del condicional.
	
	system("pause");	
	return 0;	
}
