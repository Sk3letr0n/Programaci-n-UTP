/*
Fecha de publicaci�n: 17/09/2022
Hora: 4:15 p.m.
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
	int es = 39; //Esta variable son los espacios que hay entre el inicio y la primera letra en cada f 
	int cA = 1; //Esta variable es la cantidad de veces que se va a imprimir la A en cada linea
	int f = 1; //La variable sirve para saber en que f  vamos
	int x = 0; //Es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
	int y = 0; //Es un iterador que dice cuantas letras se van a imprimir en cada f
	
	do{
		x = es;
		do{
			fe();
			x = x - 1;
		} while(x > 0);
		
		y = cA;
		do{
			fA();
			y = y - 1;
		} while(y > 0);
		
		fs();
		
		es = es - 1;
		cA = cA + 1;
		f =  f + 1;
	} while(f  <= 5);


    do{
		x = es;
		do{
			fe();
			x = x - 1;
		} while(x > 0);
		
		y = cA;
		do{
			fA();
			y = y - 1;
		} while(y > 0);
		
		fs();
		
		es = es + 1;
		cA = cA - 1;
		f  = f + 1;
	} while(f  == 6);
	
	do{
		x = es;
		do{
			fe();
			x = x - 1;
		}while(x > 0);
		
		y = cA;
		do{
			fA();
			y = y - 1;
		} while(y > 0);
		
		fs();
		
		es = es + 1;
		cA = cA - 1;
		f  = f + 1;
	} while(f >= 7 && f <= 11);
	
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
