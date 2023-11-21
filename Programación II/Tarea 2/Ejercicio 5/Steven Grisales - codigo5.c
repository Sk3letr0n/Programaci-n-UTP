/*
Fecha de publicación: 24/08/2022
Hora: 9:06 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa lee la antigüedad en años para calcular el sueldo de un empleado el cual cobra 40k euros al año.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int t = 0; //Esta variable guardara el dato insertado por teclado, en este caso el número.
	
	printf("Este programa leyendo por teclado la antig%cedad en a%cos, calcula el sueldo mensual que le corresponde al trabajador de una empresa que cobra 40.000 euros anuales, el programa debe realizar los c%clculos en funci%cn de los siguientes criterios:", 129, 164, 160, 162);
	
	printf("\na. Si lleva m%cs de 10 a%cos en la empresa se le aplica un aumento del 10%.", 160, 164);
	printf("\nb. Si lleva menos de 10 a%cos pero m%cs que 5 se le aplica un aumento del 7%.", 164, 160);
	printf("\nc. Si lleva menos de 5 a%cos pero m%cs que 3 se le aplica un aumento del 5%.", 164, 160);
	printf("\nd. Si lleva menos de 3 a%cos se le aplica un aumento del 3%.", 164);
	
	printf("\nSalvedad: Para valores negativos, no garantizamos el resultado del aumento.\n");
	
	printf("\nEntre el n%cmero de a%cos de antig%cedad del trabajador: ", 163, 164, 129);
	
	scanf("%i", &t); //Lee el dato insertado a la variable.
	
	if (t > 10)
	{
		printf("El sueldo mensual es de %0.2f euros\n\n", 40000.0/12.0*1.1);
	}
	else
	{
		if (t <= 10 && t > 5)
		{
			printf("El sueldo mensual es de %0.2f euros\n\n", 40000.0/12.0*1.07);
		}
		else
		{
			if (t <= 5 && t > 3)
			{
				printf("El sueldo mensual es de %0.2f euros\n\n", 40000.0/12.0*1.05);
			}
			else
			{
				if (t <= 3)
				{
					printf("El sueldo mensual es de %0.2f euros\n\n", 40000.0/12.0*1.03);
				}
				else
				{
					printf(" ");
				}
			}
		}
	}
	//Finalización del condicional.
	system("pause");	
	return 0;	
}
