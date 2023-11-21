/*
Fecha de publicaci�n: 27/08/2022
Hora: 2:30 a.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa determina el monto a pagar por el alquiler de un veh�culo y el monto incluido del impuesto.
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	float m = 0; //Esta variable guardara el dato del monto que se paga por el alquiler del veh�culo.
	float km = 0; //Esta variable guardara el dato insertado por teclado, en este caso la cantidad de kms que se pidio del veh�culo alquilado.
	float iva = 0;  //Esta variable guardara el dato del iva aplicado al monto total.

	printf("Este programa determina el monto a pagar por el alquiler de un vehiculo y el monto incluido del impuesto sabiendo que:\nCobra un monto fijo de $400000 para los primeros 300 km de recorrido.\nPara mas de 300 km y hasta 1000 km, cobra un monto adicional de $15.000 por cada kilometro en exceso sobre 300.\nPara mas de 1000 km cobra un monto adicional de $10.000 por cada kilometro en exceso sobre 1000.\nLos precios ya incluyen el 20%c del impuesto general a las ventas, IVA.", 37);
	
	printf("\n\nInserte la cantidad de km que uso en el vehiculo: ");
	
	scanf("%f", &km); //Lee el dato insertado a la variable.
	
	if(km <= 300){
		printf("\nEl monto total es: %0.0f", m = 400000);
		printf("\nEl monto con el iva aplicado es: %0.1f\n\n", iva = m + (m*0.2));
	}
	else
	{
		if (km > 300 && km <= 1000){
			printf("\nEl monto total es: %0.0f", m = 400000 + ((km - 300) * 15000));
			printf("\nEl monto con el iva aplicado es: %0.1f\n\n", iva = m + (m*0.2));
		}
		else
		{
			printf("\nEl monto total es: %0.0f", m = 400000 + 10500000 + ((km - 1000) * 10000));
			printf("\nEl monto con el iva aplicado es: %0.1f\n\n", iva= m + (m*0.2));	
		}
	}	
	//Finalizaci�n del condicional.
		
	system("pause");
	return 0;
}
