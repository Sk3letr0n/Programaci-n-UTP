/*
Fecha de publicaci�n: 16/09/2022
Hora: 6:42 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa imprime lo siguiente en pantalla
..... .....               ..... .....
		    A           A
			A A       A A
			A A	A   A A A
			A A	A A A A A
			A A	A	A A A
			A A		  A A
			A		    A
(con un m�ximo de cuatro(4) ordenes �IMPRIMIR�)
*/
#include <stdio.h>
#include <stdlib.h>

void fe();
void fA(int);
void fs();

int main(){
	int es1 = 27; //Esta variable son los espacios que hay entre el inicio y primera letra en cada fila
	int es2 = 5; //Esta variable son los espacios entre las letras de cada fila
	int cA = 1; //Esta variable ser� usada como las veces que se imprime el caracter 
	int fila = 1; //Es en que fila vamos
	int x = 0; //Es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
	int y = 0; //Es un iterador que dice cuantos espacios hay que imprimir entre las letras de cada fila
	
	while(fila <= 3){
	 
		x = es1;
		while(x > 0){ 
			fe();
			x = x - 1;
		}
		fA(cA);
		
		y = es2;
		while(y > 0){
			fe();
			y = y - 1;
		}
		fA(cA);
		
		fs();
		es2 = es2 - 2;
		cA = cA + 1;
		fila = fila + 1;
	}
	
	while(fila == 4){
		
		x = es1;
		while(x > 0){ 
			fe();
			x = x - 1;
		}
		fA(7);
		
		fs();
		es2 = es2 + 2;
		cA = cA - 1;
		fila = fila + 1;
	}
	while((fila >= 5) && (fila <= 7)){
		
		x = es1;
		while(x > 0){
			fe();
			x = x - 1;
		}
	    fA(cA);
		
		y = es2;
		while(y > 0){
			fe();
			y = y - 1;
		}
		fA(cA);
		
		fs();
		es2 = es2 + 2;
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

void fA(int cA){
	
	while(cA > 0){
	printf ("A");
	cA = cA - 1;
	}
	return;
}

void fs(){
	printf ("\n");
	return;
}
