/*
Fecha de publicaci�n: 31/08/2022
Hora: 9:20 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa lee un n�mero e imprima su factorial, siendo:
N ! = 1 x 2 x 3 x 4 x...N
N ! = 1 si N = 0
Solo est� definido el factorial para n�meros enteros positivos.
*/
#include <stdio.h>
#include <stdlib.h>

void facto(int, int, int);
int main(){
	int n = 0; //Esta variable guardar� el dato insertado por teclado, en este caso un n�mero
	int con = 1; //Esta variable se toma como un contador que nos ayuda a identificar donde va el producto
	int fac = 1; //Esta variable guardar� el factorial
	
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
