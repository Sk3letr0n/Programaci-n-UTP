/*
Fecha de publicación: 12/08/2022
Hora: 5:51 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación

Este programa hace la conversión mph a m/s, teniendo en cuenta las medidas respectivas:
1mp = 1609.344m y 1h = 3600s
*/

#include <stdio.h>
#include <stdlib.h>
int main (){
	float m; //Esta variable guardara el dato insertado por teclado, en este caso las millas.
	
	printf("Por favor digite la cantidad de mph que desea convertir a m/s: ");
	
	scanf("%f",&m); //Lee el dato insertado a la variable.
	
	printf("\n%0.1f mph equivalen a %0.4f m/s\n\n", m, ((m*1609.344)/3600)); 
	//Cabe recalcar que el resultado que viene adjunto en el documento, esta erróneo (la de 60mph) 
	
	system("pause");
	return 0;
}
