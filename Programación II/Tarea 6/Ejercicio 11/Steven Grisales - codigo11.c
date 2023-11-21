/*
Fecha de publicación: 17/09/2022
Hora: 3:35 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

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
(con un máximo de cuatro(4) ordenes “IMPRIMIR”)
*/
#include <stdio.h>
#include <stdlib.h>

void fe();
void fA();

int main(){
	int es = 79; //son los espacios que hay entre el inicio y la primera letra en cada fila
	int cA = 1; //Es la cantidad de veces que se va a imprimir la A en cada linea
	int f = 1; // Es la fila en la que vamos
	int x = 0; //Es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
	int y = 0; //Es un iterador que dice cuantas letras se van a imprimir en cada fila
	
	printf ("Este programa muestra lo siguiente en pantalla: \n\n");
	
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
		
		printf ("\n");
		es = es-1;
		cA = cA+1;
		f = f + 1;
	} while(f <= 25);
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
