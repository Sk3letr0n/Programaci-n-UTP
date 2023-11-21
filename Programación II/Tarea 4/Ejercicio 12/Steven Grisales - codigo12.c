/*
Fecha de publicaci�n: 11/09/2022
Hora: 5:59 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa imprime lo siguiente en pantalla
P P P P P P P P P P P P P
  N N N N N N N N N N N
    L L L L L L L L L
      J J J J J J J
        H H H H H
          F F F
            D
(con un m�ximo de cuatro(4) ordenes �IMPRIMIR�)
*/

#include <stdio.h>
#include <stdlib.h>

void fe();
void fL();

int main(){
	int ces = 0; //Esta variable ser� usada para conocer la cantidad de espacios que hay despues de un salto de linea
	int clt = 13; //Esta variable guardar� el n�mero de la cantidad de veces que se ha de imprimir cada letra
	int ASCII = 80;  //Esta variable equivale al codigo ascii de la primera letra (P)
	
	//La variable f sirve para saber en que fila vamos
	for(int f = 1; f <= 7; f =  f + 1){
		
		//x es un iterador que dice cuantos espacios hay que imprimir luego de saltar linea
		for(int x = ces; x > 0; x = x - 1){ 
			fe();
		}
		
		//y es un iterador que dice cuantas letras se van a imprimir en cada fila
		for(int y = clt; y > 0; y = y - 1){
			fL(ASCII);
		}
		
		printf ("\n");
		ces = ces + 1;
		clt = clt - 2;
		ASCII = ASCII - 2;	
	}
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
