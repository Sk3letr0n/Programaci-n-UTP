/*
Fecha de publicaci�n: 2/09/2022
Hora: 5:41 p.m.
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
		  .... ....
          .... ....
         ..... ....
  A A A A A A A A A	
(con un m�ximo de cuatro(4) ordenes �IMPRIMIR�)
*/
#include <stdio.h>
#include <stdlib.h>

void un(int, int);
void es(int);
void A(int);

int main(){
	int n = 79; //Esta variable guardar� los espacios entre caracteres
	int a = 1; //Esta variable guardar� el n�meros de A's que aparecen en pantalla
	un(n, a);
	
	system("pause");
	return 0;
}

void un(int n, int a){
	if(a <= 25){
		es(n);
		A(a);
		printf("\n");
		un(n-1, a+1);
	} else {
	}
	return;
}

void es(int n){
	if(n >= 1){
		printf(" ");
		es(n-1);
	} else{
	}
	return;
}

void A(int a){
	if(a >= 1){
		printf("A");
		A(a - 1);
	} else{
	}
	return;
}
