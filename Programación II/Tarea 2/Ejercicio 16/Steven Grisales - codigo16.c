/*
Fecha de publicación: 27/08/2022
Hora: 12:33 a.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa determina la compra que una empresa quiere hacer de varias piezas de la misma clase a una fabrica de refacciones. La empresa, dependiendo del
monto total de la compra, decidirá que hacer para pagar al fabricante.
Datos de entrada: CostoPieza, NumeroDePiezas.
Datos de salida: CantidadInvertida, ValorPrestamoBanco, ValorCreditoFabricante, InteresCobradoPorFabricante..
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	int p = 0; //Esta variable guardara el dato insertado por teclado, en este caso las piezas.
	float cp = 0; //Esta variable guardara el dato insertado por teclado, en este caso el costo de las piezas.
	float m = 0; //Esta variable guardara el dato insertado por teclado, en este caso el monto total. 
	float ci = 0; //Esta variable guardara el dato de la cantidad invertida.
	float cf = 0; //Esta variable guardara el dato del credito del fabricante.
	float pb = 0; //Esta variable guardara el dato del prestamo del banco.
	float ixf = 0; //Esta variable guardara el dato del interes cobrado por fabricante.
	
	printf("Este programa determina el monto total de la compra de varias piezas de la misma clase de una empresa a una fabrica de refacciones. La empresa, dependiendo del monto total de la compra, decidira que hacer para pagar al fabricante.");
	
	printf("\n\nSi el monto total de la compra excede de $500000 la empresa tendrá la capacidad de invertir de su propio dinero un 55%c del monto de la compra, pedir prestado al banco un 30% y el resto lo pagara solicitando un credito al fabricante.", 37);
	
	printf("\n\nSi el monto total de la compra no excede de $500000 la empresa tendra capacidad de invertir de su propio dinero un 70%c y el restante lo pagara solicitando crédito al fabricante. El fabricante cobra por concepto de intereses un 20%c sobre la cantidad que se le pague a credito.", 37, 37);
	
	printf("\n\nInserte la cantidad de piezas compradas: ");
	
	scanf("%i", &p); //Lee el dato insertado a la variable.
	
	printf("Inserte el costo de las piezas: ");
	
	scanf("%f", &cp); //Lee el dato insertado a la variable.
	
	m = p * cp;
	
	if(m > 500000){
		printf("\nLa cantidad a invertir es: $%0.1f", ci = (m * 0.55));
		printf("\nEl valor del prestamo del banco es: $%0.1f", pb = (m * 0.3));
		printf("\nEl valor del credito del fabricante es $%0.1f", cf = (m * 0.15));
		printf("\nEl valor que debe pagar de los intereses por el credito del fabricante es: $%0.1f\n\n", ixf = (ci + (ci * 0.2)));
	}
	else
	{
		printf("\nLa cantidad a invertir es: $%0.1f", ci = (m * 0.7));
		printf("\nEl valor del prestamo del banco es: %0.0f", pb);
		printf("\nEl valor del credito del fabricante es $%0.1f", cf = (m * 0.3));
		printf("\nEl valor que debe pagar de los intereses por el credito del fabricante es: $%0.1f\n\n", ixf = (ci + (ci * 0.2)));
	}

	//Finalización del condicional.
		
	system("pause");
	return 0;
}
