/*
Fecha de publicaci�n: 16/09/2022
Hora: 6:13 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa imprime lo siguiente en pantalla
..... ..... P P P P P P P P P P P P P ..... .....
			  P P P P P P P P P P P 
				P P P P P P P P P 
				  P P P P P P P 
					P P P P P 
					  P P P 
						P
(con un m�ximo de cuatro(4) ordenes �IMPRIMIR�)
*/
#include <stdio.h>
#include <stdlib.h>

void fe();
void fP();

int main(){
	int es = 33; //Esta variable son los espacios que hay entre el inicio y la primera letra en cada fila
	int cP = 13; //Esta variable es la cantidad de veces que se va a imprimir la P en cada linea
	int fila = 1; //Es en que fila vamos
	int x = 0; //Es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
	int y = 0; //Es un iterador que dice cuantos espacios hay que imprimir entre las letras de cada fila
	
	while(fila <= 7){
		
		x = es;
		while(x > 0){
			fe();
			x = x - 1;
		}
		
		y = cP;
		while(y > 0){
			fP();
			y = y - 1;
		}
		
		printf ("\n");
		
		es = es + 1;
		cP = cP - 2;
		fila = fila + 1;
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
