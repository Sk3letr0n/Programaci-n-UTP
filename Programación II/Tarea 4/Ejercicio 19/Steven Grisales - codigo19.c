/*
Fecha de publicación: 11/09/2022
Hora: 7:38 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa imprime lo siguiente en pantalla
 	             A
 	           A A
 	         A A A
 	       A A A A
 	     A A A A A
 	   A A A A A A
 	     A A A A A
 	       A A A A
 	         A A A
 	           A A
 	             A
(con un máximo de cuatro(4) ordenes “IMPRIMIR”)
*/
#include <stdio.h>
#include <stdlib.h>

void fe();
void fA();
void fs();

int main(){
	int es = 39; //Esta variable son los espacios que hay entre el inicio y la primera letra en cada fila
	int cA = 1; //Esta variable es la cantidad de veces que se va a imprimir la A en cada linea
	int f = 1; //La variable sirve para saber en que fila vamos
	
	for( ; f <= 5; f = f + 1){
		
		//x es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
		for(int x = es; x > 0; x = x-1){
			fe();
		}
		
		//y es un iterador que dice cuantas A se van a imprimir en cada fila
		for(int y = cA; y > 0; y = y-1){
			fA();
		}
		fs();
		es = es - 1;
		cA = cA + 1;
	}
    for( ; f == 6; f = f + 1){
		
		for(int x = es; x > 0; x = x-1){
			fe();
		}
		
		for(int y = cA; y > 0; y = y-1){
			fA();
		}
		fs();
		es = es + 1;
		cA = cA - 1;	
	}
	for( ;(f >= 7) && (f <= 11); f = f + 1){
		
		for(int x = es; x > 0; x = x-1){
			fe();
		}
		for(int y = cA; y > 0; y = y - 1){
			fA();
		}
	fs();
	es = es + 1;
	cA = cA - 1;
	}
	system("pause");
	return 0;	
}

void fe(){
	printf (" ");
	return;
}

void fA(){
	printf ("A");
	return;
}

void fs(){
	printf ("\n");
	return;
}
