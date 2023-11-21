/*
Fecha de publicaci�n: 16/09/2022
Hora: 7:38 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

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
(con un m�ximo de cuatro(4) ordenes �IMPRIMIR�)
*/
#include <stdio.h>
#include <stdlib.h>

void fe();
void fA();
void fs();

int main(){
	int es = 39; //Esta variable son los espacios que hay entre el inicio y la primera letra en cada fila
	int cA = 1; //Esta variable es la cantidad de veces que se va a imprimir la A en cada linea
	int fila = 1; //Es en que fila vamos
	int x = 0; //Es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
	int y = 0; //Es un iterador que dice cuantos espacios hay que imprimir entre las letras de cada fila
	
	while(fila <= 5){
		
		x = es;
		while(x > 0){
			fe();
			x = x - 1;
		}
		
		y = cA;
		while(y > 0){
			fA();
			y = y - 1;
		}
		
		fs();
		es = es - 1;
		cA = cA + 1;
		fila = fila + 1;
	}
    while(fila == 6){
    	
		x = es;
		while(x > 0){
			fe();
			x = x - 1;
		}
		
		y = cA;
		while(y > 0){
			fA();
			y = y - 1;
		}
		
		fs();
		es = es + 1;
		cA = cA - 1;	
		fila = fila + 1;
	}
	while((fila >= 7) && (fila <= 11)){
		
		x = es;
		while(x > 0){
			fe();
			x = x - 1;
		}
		
		y = cA;
		while(y > 0){
			fA();
			y = y - 1;
		}
		
		fs();
		es = es + 1;
		cA = cA - 1;
		fila = fila + 1;
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
