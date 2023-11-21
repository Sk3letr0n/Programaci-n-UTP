/*
Fecha de publicaci�n: 2/09/2022
Hora: 7:02 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa imprime lo siguiente en pantalla
..... .....               ..... .....
		          Z      
			    Z Z Z     
			  Z Z Z Z Z   
			Z Z Z Z Z Z Z
			  Z Z Z Z Z
			    Z Z Z
			      Z
(con un m�ximo de cuatro(4) ordenes �IMPRIMIR�)
*/
#include <stdio.h>
#include <stdlib.h>

void aux(int, char, int, int);
void rep(int);
void mos(char, int);

int main() {
	int es = 9; //Esta variable es para los espacios en blanco y luego saltar de linea
	char lt = 'Z'; // esta vaariable guarda la letra que vamos a imprimir
	int n = 1; //esta variable permite saber la cantidad de veces que se repite la letra
	int fl = 1; //Esta variable permite ver en que linea estamos
	
	aux(es, lt, n, fl);
	
	system("pause");
	return 0;
}

void aux (int es, char lt, int n, int fl ) {
	if(fl <= 7) {
		if(fl <= 3) {
			rep(es);
			mos(lt, n);
			printf("\n");
			aux(es-1, lt, n+2, fl+1);
		}
		if(fl == 4) {
			rep(es);
			mos(lt, 7);
			printf("\n");
			aux(es+1, lt, n-2, fl+1);
		}
		if(fl >= 5) {
			rep(es);
			mos(lt, n);
			printf("\n");
			aux(es+1, lt, n-2, fl+1);
		}
	}
	return;
}

void rep(int es) {
	if(es >= 1) {
		printf(" ");
		rep(es-1);
	}
	return;
}

void mos(char lt, int n) {
	if(n >= 1) {
		printf("%c", lt);
		mos(lt, n-1);
	}
	return;
}

