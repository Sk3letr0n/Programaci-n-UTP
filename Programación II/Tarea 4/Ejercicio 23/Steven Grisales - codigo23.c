/*
Fecha de publicación: 11/09/2022
Hora: 9:43 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa calcula los resultados de esta función usando la serie de Taylor
cosh(x) =       x^2     x^4    x^6     x^8  
            1 + ---  +  --- +  ---  +  --- ...
                2!       4!     6!      8!
se pide el valor de x y el número de terminos de la serie
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ff(int, int);

int main(){
	float x = 0; //Esta variable guardará el valor de x insertado por teclado
	int n = 0; //Esta variable guardará el valor del numero de terminos insertado por teclado
	int fac = 1; //Esta variable guardará el valor del factorial
	int fan = 2; //Esta variable es el numero al que le vamos a sacar factorial
	float res = 0; //Esta variable guardará el valor del resultado de cada termino
	float s = 0; //Esta variable guardará el valor de la suma de todos los terminos
	int pot = 2; //Esta variable guardará el valor de la pot
	
	printf ("Este programa lee por teclado un numero para asignarle el valor a (x), para calcular cosh(x).\n\n");
	printf ("Por favor digite el valor de (x): ");
	scanf ("%f", &x);

    printf ("Por favor digite el numero de terminos de la serie: ");
	scanf ("%i", &n);
	
	//i es un iterador que nos indica en que termino vamos
	for(int i = 2; i <= n; i = i + 1){
		fac = ff(fan, fac);
	    res = pow(x,pot)/fac; 
	    s = s + res;	
		fac = 1;
		fan = fan + 2;
	    pot = pot + 2;
	}
	s = s + 1;
	printf ("\n\nEl resultado de cosh^(%0.0f) es: %f", x, s);
	
	printf("\n\n");
	system("pause");
	return 0;
}

int ff(int fan, int fac){
	for(int i = 1; i <= fan; i = i + 1){
		fac = fac*i;
	}
	return fac;
}
