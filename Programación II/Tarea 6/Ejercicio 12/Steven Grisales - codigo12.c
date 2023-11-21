/*
Fecha de publicación: 17/09/2022
Hora: 3:40 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa imprime lo siguiente en pantalla
P P P P P P P P P P P P P
  N N N N N N N N N N N
    L L L L L L L L L
      y y y y y y y
        H H H H H
          F F F
            D
(con un máximo de cuatro(4) ordenes “IMPRIMIR”)
*/

#include <stdio.h>
#include <stdlib.h>

void fe();
void fL();

int main(){
	int ces = 0; //Esta variable será usada para conocer la cantidad de espacios que hay despues de un salto de linea
	int clt = 13; //Esta variable guardará el número de la cantidad de veces que se ha de imprimir cada letra
	int ASCII = 80;  //Esta variable equivale al codigo ascii de la primera letra (P)
	int f = 1; // Es la f en la que vamos
	int x = 0; //Es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
	int y = 0; //Es un iterador que dice cuantas letras se van a imprimir en cada f
	
	do{
		x = ces;
		do{ 
			if(x != 0){
				fe();
				x = x - 1;
			}
		} while(x > 0);
		
		y = clt;
		do{
			fL(ASCII);
			y = y - 1;
		}while(y > 0); 
		
		printf ("\n");
		
		ces = ces+1;
		clt = clt - 2;
		ASCII = ASCII-2;
		f =  f + 1;	
	} while(f <= 7);
	
	system("pause");
	return 0;
}

void fe(){
	printf (" ");
	return;
}

void fL(int ASCII){
	printf ("%c", ASCII);
	return;
}
