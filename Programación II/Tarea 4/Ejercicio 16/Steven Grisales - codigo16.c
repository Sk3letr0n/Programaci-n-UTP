/*
Fecha de publicación: 11/09/2022
Hora: 7:02 p.m.
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
		          Z      
			    Z Z Z     
			  Z Z Z Z Z   
			Z Z Z Z Z Z Z
			  Z Z Z Z Z
			    Z Z Z
			      Z
(con un máximo de cuatro(4) ordenes “IMPRIMIR”)
*/
#include <stdio.h>
#include <stdlib.h>

void fe();
void fZ(int);
void fs();

int main(){
	int es = 9; //Esta variable son los espacios que hay entre el inicio y la primera letra en cada fila
	int cZ = 1; //Esta variable es la cantidad de veces que se va a imprimir la Z en cada linea
	int f = 1; //Esta variable sirve para saber en que fila vamos
	
	for( ; f <= 3; f =  f + 1){ 
		
		//x es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
		for(int x = es; x > 0; x = x - 1){ 
			fe();
		}
		fZ(cZ);
		fs();
		es = es - 1;
		cZ = cZ + 2; 
	}
	for( ; f == 4; f = f + 1){
		
		for(int x = es; x > 0; x = x - 1){ 
			fe();
		}
		fZ(7);
		fs();
		es = es + 1; 
		cZ = cZ - 2; 
	}
	for( ;(f >= 5) && (f <= 7); f = f + 1){
		
		for(int x = es; x > 0; x = x - 1){
			fe();
		}
	    fZ(cZ);
		fs();
		es = es + 1; 
		cZ = cZ - 2; 
	}
	system("pause");
	return 0;	
}

void fe(){
	printf (" ");
	return;
}

void fZ(int cZ){
	
	for( ;cZ > 0; cZ = cZ - 1){ 
	printf ("Z");
	}
	return;
}

void fs(){
	printf ("\n");
	return;
}
