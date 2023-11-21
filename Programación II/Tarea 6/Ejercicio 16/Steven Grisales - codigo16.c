/*
Fecha de publicación: 17/09/2022
Hora: 4:00 p.m.
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
	int es = 9; //Esta variable son los espacios que hay entre el inicio y la primera letra en cada f 
	int cZ = 1; //Esta variable es la cantidad de veces que se va a imprimir la Z en cada linea
	int f = 1; // Es la f en la que vamos
	int x = 0; //Es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
	
	do{ 
		x = es ;
		do{ 
			fe();
			x = x - 1;
		}while(x > 0);
		
		fZ(cZ);
		
		fs();
		
		es = es - 1;
		cZ = cZ + 2; 
		f  =  f + 1;
	} while(f  <= 3);
		
	do{
		x = es ;
		do{ 
			fe();
			x = x - 1;
		}while(x > 0);
		
		fZ(7);
		
		fs();
		
		es = es + 1; 
		cZ = cZ - 2; 
		f  = f + 1;
	} while(f  == 4);
	
	
	
	do{
		x = es ;
		do{
			fe();
			x = x - 1;
		}while(x > 0);
		
	    fZ(cZ);
		
		fs();
		
		es = es + 1; 
		cZ = cZ - 2;
		f  = f + 1; 
	} while(f >= 5 && f <= 7);
	
	system("pause");
	return 0;	
}

void fe(){
	printf (" ");
	return;
}

void fZ(int cZ){
	
	do{ 
	printf ("Z");
	cZ = cZ - 1;
	} while(cZ > 0);
	return;
}

void fs(){
	printf ("\n");
	return;
}
