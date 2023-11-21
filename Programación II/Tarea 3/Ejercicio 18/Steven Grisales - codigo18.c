/*
Fecha de publicación: 2/09/2022
Hora: 7:25 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa imprime lo siguiente en pantalla
 		 Z
	 	Z Z
	   Z   Z
      Z     Z
	 Z		 Z
	Z		  Z
   Z		   Z	
  Z				Z
 Z				 Z
Z				  Z
(con un máximo de cuatro(4) ordenes “IMPRIMIR”)
*/
#include <stdio.h>
#include <stdlib.h>

void aux(int, char, int, int);
void rep(int);
void mos(char);

int main() {
	int es = 9; //Esta variable es para los espacios en blanco y luego saltar de linea
	char lt = 'Z'; // esta vaariable guarda la letra que vamos a imprimir
	int n = 0; //esta variable permite saber la cantidad de veces que se repite la letra
	int fl = 1; //Esta variable permite ver en que linea estamos
	
	aux(es, lt, n, fl);
	
	system("pause");
	return 0;
}

void aux(int es, char lt, int n, int fl) {
	if(fl <= 10) {
		if(fl == 1) {
			rep(es);
			mos(lt);
			printf("\n");
			aux(es-1, lt, n+1, fl+1);
		} else {
			rep(es);
			mos(lt);
			rep(n);
			mos(lt);
			printf("\n");
			aux(es-1, lt, n+2, fl+1);
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

void mos(char lt) {
	printf("%c", lt);
	return;
}
