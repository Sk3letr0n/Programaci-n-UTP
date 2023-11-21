/*
Fecha de publicación: 31/08/2022
Hora: 9:20 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa lee un número e imprima su factorial, siendo:
N ! = 1 x 2 x 3 x 4 x...N
N ! = 1 si N = 0
Solo está definido el factorial para números enteros positivos.
*/
#include <stdio.h>
#include <stdlib.h>

void facto(int, int, int);
int main(){
	int n = 0; //Esta variable guardará el dato insertado por teclado, en este caso un número
	int con = 1; //Esta variable se toma como un contador que nos ayuda a identificar donde va el producto
	int fac = 1; //Esta variable guardará el factorial
	
	printf("Salvedad: No se garantizan los resultados para la suma de los factoriales despues de 12\n");
	printf("Digite un numero para sacar el factorial: ");
	scanf("%i", &n);
	
	printf("%i! = ", n);
	facto(n, con+1, fac);
	
	printf("\n\n");
	system("pause");
	return 0;
}
void facto(int n, int con, int fac){
	if(con < n){
		printf("%ix", con);
		fac = fac * con;
		facto(n, con+1, fac);
	}
	else{
		fac = fac * n;
		printf("%i = %i", n, fac);
	}
	return;
}
