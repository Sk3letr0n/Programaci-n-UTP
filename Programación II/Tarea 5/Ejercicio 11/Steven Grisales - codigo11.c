/*
Fecha de publicaci�n: 16/09/2022
Hora: 5:48 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa imprime lo siguiente en pantalla
				  80
				  A 
			    A A 
		   	  A A A 
			A A A A 
		  A A A A A 
        A A A A A A 
		  .... ....
          .... ....
         ..... ....
  A A A A A A A A A	 25
(con un m�ximo de cuatro(4) ordenes �IMPRIMIR�)
*/
#include <stdio.h>
#include <stdlib.h>

void fe();
void fA();

int main(){
	int es = 79; //son los espacios que hay entre el inicio y la primera letra en cada fila
	int cA = 1; //Es la cantidad de veces que se va a imprimir la A en cada linea
	int fila = 1; //Es en que fila vamos
	int x = 0; //Es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
	int y = 0; //Es un iterador que dice cuantos espacios hay que imprimir entre las letras de cada fila
	
	printf ("Este programa muestra lo siguiente en pantalla: \n\n");
	
	while(fila <= 25){ 
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
		printf ("\n");
		es = es - 1;
		cA = cA + 1;
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
