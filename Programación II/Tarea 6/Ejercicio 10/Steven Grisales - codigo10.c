/*
Fecha de publicación: 17/09/2022
Hora: 3:30 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa imprime lo siguiente en pantalla
A      A
 A    A
  A  A
   AA
Requisitos. Puede usar un máximo de tres(3) funciones de impresión.
*/
#include <stdio.h>
#include <stdlib.h>

void fe();
void fA();

int main(){
	int es1 = 0; //Son los espacios que hay entre el inicio y la primera letra en cada fila
	int es2 = 6; //Son los espacios entre las letras de cada fila
	int f = 1; // Es la fila en la que vamos
	int x = 0; //Es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
	int y = 0; //Es un iterador que dice cuantas letras se van a imprimir en cada fila
	
	do{ 
		x = es1;
		do{
			if(x != 0){
			fe();
			x = x - 1;
			}
		} while(x > 0);
		
		fA();
		
		y = es2;
		do{
			if(y != 0){
			fe();
			y = y - 1;
			}
		}while(y > 0);
		
		fA();
		
		printf ("\n");
		
		es1 = es1 + 1;
		es2 = es2 - 2;
		f =  f + 1;
	} while(f <= 4);
	
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
