/*
Fecha de publicación: 16/09/2022
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
	int fila = 1; //Es en que fila vamos
	int x = 0; //Es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
	
	while(fila <= 3){ 
		
		x = es;
		while(x > 0){ 
			fe();
			x = x - 1;
		}
		
		fZ(cZ);
		fs();
		es = es - 1;
		cZ = cZ + 2; 
		fila = fila + 1;
	}
	while(fila == 4){
		
		x = es;
		while(x > 0){ 
			fe();
			x = x - 1;
		}
		fZ(7);
		
		fs();
		es = es + 1; 
		cZ = cZ - 2; 
		fila = fila + 1;
	}
	while((fila >= 5) && (fila <= 7)){
		
		x = es;
		while(x > 0){
			fe();
			x = x - 1;
		}
	    fZ(cZ);
	    
		fs();
		es = es + 1; 
		cZ = cZ - 2; 
		fila = fila + 1;
	}
	system("pause");
	return 0;	
}

void fe(){
	printf (" ");
	return;
}

void fZ(int cZ){
	while(cZ > 0){ 
	printf ("Z");
	cZ = cZ - 1;
	}
	return;
}

void fs(){
	printf ("\n");
	return;
}
