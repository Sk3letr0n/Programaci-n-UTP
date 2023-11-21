/*
Fecha de publicaci�n: 11/09/2022
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
	
	//x es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
	for(int x = es1; x > 0; x = x - 1){  
		fe();
	}
	fZ();	
	printf("\n");
	es1 = es1 - 1;
		
	//La variable f sirve para saber en que fila vamos
	for(int f = 2; f <= 10; f =  f + 1){
	 
		for(int x = es1; x > 0; x = x - 1){ 
			fe();
		}
		fZ();
		
		//y es un iterador que dice cuantos espacios hay que imprimir entre las letras de cada fila
		for(int y = es2 ; y > 0; y = y - 1){
			fe();
		}
		fZ();
		printf ("\n");
		es1 = es1 - 1;
		es2 = es2 + 2;
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
