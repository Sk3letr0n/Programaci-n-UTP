/*
Fecha de publicación: 17/09/2022
Hora: 3:55 p.m.
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
	int es1 = 27; //Esta variable son los espacios que hay entre el inicio y primera letra en cada f
	int es2 = 5; //Esta variable son los espacios entre las letras de cada f
	int cA = 1; //Esta variable será usada como las veces que se imprime el caracter 
	int f = 1; // Es la f en la que vamos
	int x = 0; //Es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
	int y = 0; //Es un iterador que dice cuantas letras se van a imprimir en cada f
	
	do{ 
		x = es1;
		do{ 
			fe();
			x = x - 1;
		}while(x > 0);
		
		fA(cA);
		
		y = es2;
		do{
			fe();
			y = y - 1;
		}while(y > 0);
		
		fA(cA);
		
		fs();
		
		es2 = es2 - 2;
		cA = cA + 1;
		f =  f + 1;
	} while(f <= 3);
	
	do{
		x = es1;
		do{
			fe();
			x = x - 1;
		} while( x > 0);
		
		fA(7);
		
		fs();
		
		es2 = es2 + 2;
		cA = cA - 1;
		f = f + 1;
	} while(f == 4);
	
	do{
		x = es1;
		do{
			fe();
			x = x - 1;
		} while(x > 0);
		
	    fA(cA);
		
		y = es2 ;
		do{
			fe();
			y = y - 1;
		}while(y > 0);
		
		fA(cA);
		
		fs();
		
		es2 = es2 + 2;
		cA = cA - 1;
		f = f + 1;
 	} while(f >= 5 && f <= 7);
 	
	system("pause");
	return 0;
}

void fe(){
	printf (" ");
	return;
}

void fA(int cA){
	
	do{
	printf ("A");
	cA = cA - 1;
	} while(cA > 0);
	return;
}

void fs(){
	printf ("\n");
	return;
}
