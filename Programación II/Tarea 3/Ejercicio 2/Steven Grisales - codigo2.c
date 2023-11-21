/*
Fecha de publicación: 30/08/2022
Hora: 7:27 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa presenta la suma de los elementos de la serie de Fibonacci entre 0 y 100.
*/

#include <stdio.h>
#include <stdlib.h>

void fibo(int, int, int, int);

int main(){
	int n = 0; //Esta variable guardara el # fibonacci para después imprimirlo 
	int m = 1; //Esta variable guardara el # en el que se este en ese momento en la serie fibonacci
	int o = 0; //Esta variable guardara el # anterior del que vayamos en la serie fibonacci
	int s = 0; //Esta variable guardara el dato de la suma de los números de la serie fibonacci entre 0 y 100
	
	printf("Este programa presenta la suma de los elementos de la serie de Fibonacci entre 0 y 100.");

	printf("\nLos numeros a sumar son:\n\n");
	
	fibo(n, m, o, s); 
	
	printf("\n\n");
	system("pause");
	return 0;	
}

void fibo(int n, int m, int o, int s){
	if (n <= 100) { //Inicio de la sentencia if junto con su argumentador.
		printf("%i, ", n); 
		s = s + n; 
		n = m + o;
		m = o; 
		o = n;
		fibo(n, m, o, s);
	//Finalización del condicional.
	}
	else{
		printf(" Y la suma es: %i", s);
	}
	return;
}
