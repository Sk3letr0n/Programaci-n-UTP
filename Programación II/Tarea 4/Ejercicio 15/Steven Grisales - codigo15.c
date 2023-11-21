/*
Fecha de publicación: 11/09/2022
Hora: 6:42 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa imprime lo siguiente en pantalla
..... .....               ..... .....
		    A           A
			A A       A A
			A A	A   A A A
			A A	A A A A A
			A A	A	A A A
			A A		  A A
			A		    A
(con un máximo de cuatro(4) ordenes “IMPRIMIR”)
*/
#include <stdio.h>
#include <stdlib.h>

void fe();
void fA(int);
void fs();

int main(){
	int es1 = 27; //Esta variable son los espacios que hay entre el inicio y primera letra en cada fila
	int es2 = 5; //Esta variable son los espacios entre las letras de cada fila
	int cA = 1; //Esta variable será usada como las veces que se imprime el caracter 
	int f = 1; //Esta variable sirve para saber en que fila vamos
	
	for( ; f <= 3; f =  f + 1){ 
		//x es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
		for(int x = es1; x > 0; x = x - 1){ 
			fe();
		}
		fA(cA);
		
		//y es un iterador que dice cuantos espacios hay que imprimir entre las letras de cada fila
		for(int y = es2 ; y > 0; y = y - 1){
			fe();
		}
		fA(cA);
		fs();
		es2 = es2 - 2;
		cA = cA + 1;
	}
	for( ; f == 4; f = f + 1){
		
		for(int x = es1; x > 0; x = x - 1){
			fe();
		}
		fA(7);
		fs();
		es2 = es2 + 2;
		cA = cA - 1;
	}
	for( ;(f >= 5) && (f <= 7); f = f + 1){
		
		for(int x = es1; x > 0; x = x - 1){
			fe();
		}
	    fA(cA);
		
		for(int y = es2 ; y > 0; y = y - 1){
			fe();
		}
		fA(cA);
		fs();
		es2 = es2 + 2;
		cA = cA - 1;
	}
	system("pause");
	return 0;
}

void fe(){
	printf (" ");
	return;
}

void fA(int cA){
	
	for( ;cA > 0; cA = cA - 1){
	printf ("A");
	}
	return;
}

void fs(){
	printf ("\n");
	return;
}
