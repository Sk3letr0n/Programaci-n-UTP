/*
Fecha de publicación: 2/09/2022
Hora: 5:59 p.m.
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
      J J J J J J J
        H H H H H
          F F F
            D
(con un máximo de cuatro(4) ordenes “IMPRIMIR”)
*/
#include <stdio.h>
#include <stdlib.h>

void mos(int, int, int, int, int, int);
void es(int, int);
void lt(int, int, int);

int main(){
	int con = 1; //Esta variable será usada para conocer cuando finaliza el programa
	int n = 0; //Esta variable será usada para conocer la cantidad de espacios que se han de imprimir
	int ces = 0; //Esta variable será usada para conocer la cantidad de espacios que hay despues de un salto de linea
	int m = 0; //Esta variable será usada para conocer la cantidad de veces que se han de imprimir las letras
	int clt = 13; //Esta variable guardará el número de la cantidad de veces que se ha de imprimir cada letra
	int ASCII = 80;  //Esta variable equivale al codigo ascii de la primera letra (P)
	
	mos(con, n, ces, m, clt, ASCII); 
	es(n, ces);
	
	system("pause");
	return 0;
}

void mos(int con, int n, int ces, int m, int clt, int ASCII){
	if(con <= 7){
		es(n, ces);
		lt(m, clt, ASCII);
		printf("\n");
		mos(con+1, n = 0, ces+1, m = 0, clt-2, ASCII-2);
	}
}

void es(int n, int ces){
	if(n < ces){
		printf(" ");
		es(n+1, ces);
	} else{
	}
	return;
}

void lt(int m, int clt, int ASCII){
	if(m < clt){
		printf("%c", ASCII);
		lt(m+1, clt, ASCII);
	} else {
	}
	return;
}
