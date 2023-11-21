/*
Fecha de publicación: 27/08/2022
Hora: 1:49 a.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa determina el monto de la compra, el monto del descuento, el monto a pagar y el número de unidades
de obsequio por la compra de cierta cantidad de docenas del producto de un supermercado.
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	int d = 0; //Esta variable guardara el dato insertado por teclado, en este caso las decenas.
	int o = 0; //Esta variable guardara el dato de las unidades de obsequio.
	float mc = 0; //Esta variable guardara el dato, en este caso el monto de la compra. 
	float md = 0; //Esta variable guardara el dato del descuento del monto.
	float mp = 0; //Esta variable guardara el dato del total a pagar.
	float p = 0; //Esta variable guardara el dato insertado por teclado, en ese caso el precio.

	printf("Este programa determina el monto de la compra, el monto del descuento, el monto a pagar y el numero de unidades de obsequio por la compra de cierta cantidad de docenas del producto de un supermercado.");
	
	printf("\n\nLa oferta de la venta al por mayor del producto es: El descuento del 15%c por la compra de mas de 3 docenas y 10%c en caso contrario. Ademas por la compra de mas de 3 docenas se obsequia una unidad del producto por cada docena en exceso sobre 3.", 37, 37);
	
	printf("\n\nInserte la cantidad de docenas que compro del producto: ");
	
	scanf("%i", &d); //Lee el dato insertado a la variable.
	
	printf("Inserte el precio de las docenas del producto: ");
	
	scanf("%f", &p); //Lee el dato insertado a la variable.
	
	if(d > 3){
		printf("\nEl monto de la compra es: $%0.1f", mc = (d * p));
		printf("\nEl monto del descuento es: $%0.1f", md = (mc * 0.15));
		printf("\nEl monto a pagar es $%0.1f", mp = (mc - md));
		printf("\nEl numero de unidades de obsequio es: %i\n\n", o = (d - 3));
	}
	else
	{
		printf("\nEl monto de la compra es: $%0.1f", mc = (d * p));
		printf("\nEl monto del descuento es: $%0.1f", md = (mc * 0.1));
		printf("\nEl monto a pagar es $%0.1f", mp = (mc - md));
		printf("\nEl numero de unidades de obsequio es: %i\n\n", o);
	}

	//Finalización del condicional.
		
	system("pause");
	return 0;
}
