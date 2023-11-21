/*
Fecha de publicación: 17/09/2022
Hora: 4:10 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

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
(con un máximo de cuatro(4) ordenes “IMPRIMIR”)
*/
#include <stdio.h>
#include <stdlib.h>

void fe();
void fZ();

int main(){
	int es1 = 9; //Esta variable son los espacios que hay entre el inicio y la primera letra en cada f
	int es2 = 1; //Esta variable son los espacios entre las letras de cada f
	int f = 2; // Es la f en la que vamos
	int x = 0; //Es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
	int y = 0; //Es un iterador que dice cuantas letras se van a imprimir en cada f
	
	x = es1;
	do{  
		fe();
		x = x - 1;
	} while(x > 0);
		
	fZ();
		
	printf("\n");
		
	es1 = es1 - 1;
	
	f = 2;	
	do{ 
		
		x = es1;
		do{ 
			if(x != 0){
				fe();
				x = x - 1;
			}
		}while(x > 0);
		
		fZ();
		
		y = es2 ;
		do{
			fe();
			y = y - 1;
		} while(y > 0);
		
		fZ();
		
		printf ("\n");
		
		es1 = es1 - 1;
		es2 = es2 + 2;
		f =  f + 1;	
	} while(f <= 10);
	
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
