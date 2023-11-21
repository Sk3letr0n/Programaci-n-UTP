/*
Fecha de publicaci�n: 16/09/2022
Hora: 7:25 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa imprime lo siguiente en pantalla
 		 Z
	 	Z Z
	   Z   Z
      Z     Z
	 Z		 Z
	Z		  Z
   Z		   Z	
  Z				Z
 Z				 Z
Z				  Z
(con un m�ximo de cuatro(4) ordenes �IMPRIMIR�)
*/
#include <stdio.h>
#include <stdlib.h>

void fe();
void fZ();

int main(){
	int es1 = 9; //Esta variable son los espacios que hay entre el inicio y la primera letra en cada fila
	int es2 = 1; //Esta variable son los espacios entre las letras de cada fila
	int fila = 2; //Es en que fila vamos
	int x = 0; //Es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
	int y = 0; //Es un iterador que dice cuantos espacios hay que imprimir entre las letras de cada fila
	
	x = es1;
	while(x > 0){  
		fe();
		x = x - 1;
	}
	fZ();	
	printf("\n");
	es1 = es1 - 1;
		
	while(fila <= 10){
		
		x = es1;
		while(x > 0){ 
			fe();
			x = x - 1;
		}
		fZ();
		
		y = es2;
		while(y > 0){
			fe();
			y = y - 1;
		}
		
		fZ();
		printf ("\n");
		es1 = es1 - 1;
		es2 = es2 + 2;
		fila = fila + 1;
	}
	system("pause");
	return 0;
}

void fe(){
	printf (" ");
	return;
}

void fZ(){
	printf ("Z");
	return;
}
