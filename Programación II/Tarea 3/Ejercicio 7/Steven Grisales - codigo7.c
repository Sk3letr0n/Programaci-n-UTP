/*
Fecha de publicación: 2/09/2022
Hora: 4:27 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa lee un número entero N, no negativo(validar
esto) y muestra la suma de los factoriales de todos los números desde 0 hasta N. así:

Si n = 5
= 0! + 1! + 2! + 3! + 4! + 5!
= 1 + 1 + 2 + 6 + 24 + 120 = 154
*/
#include <stdio.h>
#include <stdlib.h>

int f(int);
void sumaf(int, int, int, float);

int main(){
	int n = 0; //Esta variable guardará el dato insertado por teclado, en este caso un número
	int con = 1; //Esta variable se toma como un contador que nos ayuda a identificar donde va el producto
	int fac = 1; //Esta variable guardará el dato del factorial
	float suma = 0; //Esta variable guardará el dato de la suma de los factoriales de cada numero
	
	printf("Salvedad: No se garantizan los resultados para la suma de los factoriales despues de 12\n");
	printf("Este programa lee un numero entero N y muestra la suma de los factoriales de todos los numeros desde 0 hasta N\n\n");
	
	n = f(n);
	sumaf(n, con, fac, suma);
	
	printf("\n\n");
	system("pause");
	return 0;
}

int f(int n){
	printf("Digite un numero entero positivo: ");
	scanf("%i", &n);
	
	if(n < 0){
		printf("Por favor digite un numero mayor o igual a 0\n\n");
		f(n);
	} 
	else {
	}
	return n;
}

void sumaf(int n, int con, int fac, float suma){
	if(n > 0){
		if(con <= n){
			fac = fac * con;
			sumaf(n, con+1, fac, suma);
		}
		else{
			suma = suma + fac;
			sumaf(n-1, con = 1, fac = 1, suma);
		}
		
	}
	else{
		suma = suma + 1;
		printf("\nLa suma de los factoriales desde 0 hasta su numero es: %0.2f ", suma);
	}
	return;
}
