/*
Fecha de publicaci�n: 2/09/2022
Hora: 6:13 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa imprime lo siguiente en pantalla
..... ..... P P P P P P P P P P P P P ..... .....
			  P P P P P P P P P P P 
				P P P P P P P P P 
				  P P P P P P P 
					P P P P P 
					  P P P 
						P
(con un m�ximo de cuatro(4) ordenes �IMPRIMIR�)
*/
#include <stdio.h>
#include <stdlib.h>

void mos(int, int, int, int, int);
void es(int, int);
void P(int, int);

int main(){
	int con = 1; //Esta variable ser� usada para conocer cuando finaliza el programa
	int n = 0; //Esta variable ser� usada para conocer la cantidad de espacios que se han de imprimir
	int ces = 33; //Esta variable ser� usada para conocer la cantidad de espacios que hay despues de un salto de linea
	int m = 0; //Esta variable ser� usada para conocer la cantidad de veces que se han de imprimir las letras
	int clt = 13; //Esta variable guardar� el n�mero de la cantidad de veces que se ha de imprimir cada letra
	
	mos(con, n, ces, m, clt); 
	
	system("pause");
	return 0;
}

void mos(int con, int n, int ces, int m, int clt){
	if(con <= 7){
		es(n, ces);
		P(m, clt);
		printf("\n");
		mos(con+1, n = 0, ces+1, m = 0, clt-2);
	}
	return;	
}

void es(int n, int ces){
	if(n < ces){
		printf(" ");
		es(n+1, ces);
	} else{
	}
	return;
}

void P(int m, int clt){
	if(m < clt){
		printf("P");
		P(m+1, clt);
	} else {
	}
	return;
}
