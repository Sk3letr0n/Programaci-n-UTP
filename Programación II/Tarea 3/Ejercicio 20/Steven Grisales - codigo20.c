/*
Fecha de publicación: 2/09/2022
Hora: 7:50 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa calcula los resultados de esta función usando la serie de Taylor
e^x =       x  +  x^2  + x^3  +  x^4...  
       1 + ---    ---    ---     ---
            1!     2!     3!      4!
se pide el valor de x y el número de terminos de la serie
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mos(int, int, int, float, float, int, int);

int main(){
	int x = 0; //Esta variable guardará el valor de x insertado por teclado
	int n = 0; //Esta variable guardará el valor del numero de terminos insertado por teclado
	int fac = 1; //Esta variable guardará el valor del factorial
	int a = 1; //Esta variable es el factorial del número
	float res = 0; //Esta variable guardará el valor del resultado de cada termino
	float s = 1; //Esta variable guardará el valor de la suma de todos los terminos
	int pot = 1; //Esta variable guardará el valor de la potencia
	
	printf ("Por favor digite el valor de (x): ");
	scanf ("%i", &x);

    printf ("Por favor digite el numero de terminos de la serie: ");
	scanf ("%i", &n);	
	
	mos(x, n, fac, res, s, pot, a);
	
	printf("\n\n");
	system("pause");
	return 0;
}

void mos(int x, int n, int fac, float res, float s, int pot, int a){
	if(n > 1){
		res = pow(x,pot)/fac; 
	 	s = s + res;	
	 	a = a + 1;
	 	mos(x, n-1, fac*a, res = 0, s, pot+1, a);
	} else {
		printf ("\nEl resultado de e^(%i): %f", x, s);
	}
	return;
}
