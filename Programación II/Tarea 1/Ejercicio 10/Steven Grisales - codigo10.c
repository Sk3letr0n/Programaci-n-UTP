/*
Fecha de publicaci�n: 12/08/2022
Hora: 5:51 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n

Este programa hace la conversi�n mph a m/s, teniendo en cuenta las medidas respectivas:
1mp = 1609.344m y 1h = 3600s
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	float m; //Esta variable guardara el dato insertado por teclado, en este caso las millas.
	
	printf("Por favor digite la cantidad de mph que desea convertir a m/s: ");
	
	scanf("%f",&m); //Lee el dato insertado a la variable.
	
	printf("\n%0.1f mph equivalen a %0.4f m/s\n\n", m, ((m*1609.344)/3600)); 
	//Cabe recalcar que el resultado que viene adjunto en el documento, esta err�neo (la de 60mph) 
	
	system("pause");
	return 0;
}
