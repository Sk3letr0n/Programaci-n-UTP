/*
Fecha de publicaci�n: 25/08/2022
Hora: 11:04 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa hace un descuento al precio de un art�culo dependiendo la clave que inserta el usuario.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int c = 0; //Esta variable guardara el dato insertado por teclado, en este caso la clave.
	float po = 0; //Esta variable guardara el dato insertado por teclado, en este caso el precio original.
	float pd = 0; // //Esta variable guardara el dato insertado por teclado, en este caso el precio con descuento.
	
	printf("Este programa lee una clave y un precio para imprimir la clave, el precio y el descuento en base a la clave de un art%cculo (solo existen dos claves [1 = 10%c, 2 = 20%c]).\n", 161, 37, 37);
	
	printf("\nIngrese el precio original del art%cculo: ", 161);
	
	scanf("%f", &po); //Lee el dato insertado a la variable.
	
	printf("Ingrese la clave [1 o 2]: ");
	
	scanf("%i", &c); //Lee el dato insertado a la variable.
		
	if (c == 1) //Inicio de la sentencia if junto con su argumentador.
	{
		pd = po - (po * 10)/100;
		printf("\nEl precio original del art%cculo es: %0.1f\n", 161, po);
		printf("La clave del producto es: %i\n", c);
		printf("El precio con descuento del art%cculo es: %0.1f\n\n", 161, pd);
	}
	else //Inicio de la sentencia else en caso de if ser falso.
	{
		if (c == 2)
		{
			pd = po - (po * 20)/100;
			printf("\nEl precio original del art%cculo es: %0.1f\n", 161, po);
			printf("La clave del producto es: %i\n", c);
			printf("El precio con descuento del art%cculo es: %0.1f\n\n", 161, pd);
		}
		else
		{
			printf("\n");
		}
	}	
	//Finalizaci�n del condicional.
	
	system("pause");	
	return 0;	
}
