/*
Fecha de publicaci�n: 2/09/2022
Hora: 5:37 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa imprime lo siguiente en pantalla
A      A
 A    A
  A  A
   AA
Requisitos. Puede usar un m�ximo de tres(3) funciones de impresi�n.
*/
#include <stdio.h>
#include <stdlib.h>

void pa(int, int, int, int);
void A();
void es1(int, int);
void es2(int, int);

int main(){
	int n = 7; //Esta variable cuenta los espacios entre caracteres
	int m = 1; //Esta variable cuenta los espacios en los que se mueve la impresion del caracter
	int con = 1; //Esta variable funciona como contador que indica cuantos espacios se mueve despues de un salto de linea
	int cont = 1; //Esta variable es otro contador que nos indica cuantos espacios hay entre caracteres
	pa(n, m, con, cont);
	
	system("pause");
	return 0;
}

void pa(int n, int m, int con, int cont){ 
	if(n > 0){
		es1(m, con);
		A();
		es2(n, cont);
		A();
		printf("\n");
		pa(n-2, m = 1, con+1, cont = 1);
	} else{
	}
	return;
}

void es1(int m, int con){
	if(m < con){
		printf(" ");
		es1(m+1, con);
	} else {
	}
	return;
}

void A(){
	printf("A");
	return;
}

void es2(int n, int cont){
	if(cont < n){
		printf(" ");
		es2(n, cont+1);
	} else {
	}
	return;
}
