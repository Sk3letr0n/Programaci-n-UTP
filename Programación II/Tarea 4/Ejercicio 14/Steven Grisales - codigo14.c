/*
Fecha de publicación: 11/09/2022
Hora: 6:26 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa imprime lo siguiente en pantalla
			P P P P P P P P P P P P P
			  P P P P P P P P P P P 
				P P P P P P P P P 
				  P P P P P P P 
					P P P P P 
					  P P P 
						P
(con un máximo de cuatro(4) ordenes “IMPRIMIR”)
*/
#include <stdio.h>
#include <stdlib.h>

void fe();
void fP();

int main(){
	int es = 0; //Esta variable son los espacios que hay entre el inicio y la primera letra en cada fila
	int cP = 13; //Esta variable es la cantidad de veces que se va a imprimir la P en cada linea
	
	
	//La variable f nos sirve para saber en que fila vamos
	for(int f = 1; f <= 7; f =  f + 1){ 
		
		//x es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
		for(int x = es; x > 0; x = x - 1){ 
			fe();
		}
		
		//y es un iterador que dice cuantas P se van a imprimir en cada fila
		for(int y = cP; y > 0; y = y - 1){ 
			fP();
		}
		
		printf ("\n");
		es = es + 1;
		cP = cP - 2;
	}
	system("pause");
	return 0;
}

void fe(){
	printf (" ");
	return;
}

void fP(){
	printf ("P");
	return;
}
