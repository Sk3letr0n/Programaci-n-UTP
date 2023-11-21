/*
Fecha de publicación: 25/08/2022
Hora: 11:37 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa hace un algoritmo que calcula el total a pagar por la compra de camisas con un descuento dependiendo la cantidad comprada.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int nc = 0; //Esta variable guardara el dato insertado por teclado, en este caso el número de camisas.
	float po = 0; //Esta variable guardara el dato insertado por teclado, en este caso el precio original.
	float pd = 0; // //Esta variable guardara el dato insertado por teclado, en este caso el precio con descuento.
	
	printf("Este programa lee cierto n%cmero de camisas y el precio para imprimir el precio con descuento de las camisas (< 3 [10%] y >= 3 [20%]).\n", 163, 37, 37);
	
	printf("Salvedad: No garantizamos resultados con valores negativos.\n");
	
	printf("\nIngrese la cantidad de camisas: ");
	
	scanf("%i", &nc); //Lee el dato insertado a la variable.
	
	printf("Ingrese el precio de las camisas: ");
	
	scanf("%f", &po);
		
	if (nc < 3) //Inicio de la sentencia if junto con su argumentador.
	{
		po = nc * po;
		pd = po - (po * 10)/100;
		printf("El precio con descuento de las camisas es: %0.1f\n\n", pd);
	}
	else //Inicio de la sentencia else en caso de if ser falso.
	{
		if (nc >= 3)
		{
			po = nc * po;
			pd = po - (po * 20)/100;
			printf("El precio con descuento de las camisas es: %0.1f\n\n", pd);
		}
		else
		{
			printf("\n");
		}
	}	
	//Finalización del condicional.
	
	system("pause");	
	return 0;	
}
