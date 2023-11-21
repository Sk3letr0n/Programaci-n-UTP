/*
Fecha de publicación: 2/09/2022
Hora: 6:42 p.m.
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
		    A           A
			A A       A A
			A A	A   A A A
			A A	A A A A A
			A A	A	A A A
			A A		  A A
			A		    A
(con un máximo de cuatro(4) ordenes “IMPRIMIR”)
*/
#include <stdio.h>
#include <stdlib.h>

void mos(int, char, int, int, int);
void rep(int);
void frel(char, int);

int main(){
	int es = 27; //Esta variable será usada para ser espacios en blanco para empezar a imprimir desde la linea 28
	char lt = 'A'; //Esta variable guardará la letra que sera impresa
	int n = 1; //Esta variable será usada como las veces que se imprime el caracter
	int m = 5; //Esta variable será usada como la cantidad de espacios entre las A
	int fl = 1; //Esta variable será usada para conocer en que fila vamos
	
	mos(es, lt, n, m, fl); 
	
	system("pause");
	return 0;
}

void mos(int es, char lt, int n, int m, int fl){
	if(fl <= 7){
		if(fl <= 3){
			rep(es);
			frel(lt, n);
			rep(m);
			frel(lt, n);
			printf("\n");
			mos(es, lt, n+1, m-2, fl+1);
		}
		if(fl == 4){
			rep(es);
			frel(lt, 7);
			printf("\n");
			mos(es, lt, n-1, m+2, fl+1);
		}
		if(fl >= 5){
			rep(es);
			frel(lt, n);
			rep(m);
			frel(lt, n);
			printf("\n");
			mos(es, lt, n-1, m+2, fl+1);
		}
	} else {
	}	
	return;
}

void rep(int es){
	if(es >= 1){
		printf(" ");
		rep(es - 1);
	} else {
	}
	return;
}

void frel(char lt, int n){
	if(n >= 1){
		printf("%c", lt);
		frel(lt, n-1);
	} else {
	}
	return;
}
