/*
Fecha de publicaci�n: 2/09/2022
Hora: 5:41 p.m.
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
	
	printf ("Este programa muestra lo siguiente en pantalla: \n\n");
	
	//La variable f nos sirve para saber en que fila vamos
	for(int f = 1; f <= 25; f = f + 1){ 
		
		//x es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
		for(int x = es; x > 0; x = x - 1){ 
			fe();
		}
		
		//y es un iterador que dice cuantas A se van a imprimir en cada fila
		for(int y = cA; y > 0; y = y - 1){ 
			fA();
		}
		printf ("\n");
		es = es-1;
		cA = cA+1;
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
