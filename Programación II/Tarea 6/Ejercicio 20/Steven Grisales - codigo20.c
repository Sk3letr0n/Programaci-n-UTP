/*
Fecha de publicación: 17/09/2022
Hora: 4:20 p.m.
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

int ff(int, int);

int main(){
	float x = 0; //Esta variable guardará el valor de x insertado por teclado
	int n = 0; //Esta variable guardará el valor del numero de terminos insertado por teclado
	int fac = 1; //Esta variable guardará el valor del factorial
	int fan = 1; //Esta variable es el factorial del número
	float res = 0; //Esta variable guardará el valor del resultado de cada termino
	float s = 0; //Esta variable guardará el valor de la suma de todos los terminos
	int pot = 1; //Esta variable guardará el valor de la pot
	int i = 0; //Es un iterador que nos indica en que termino vamos
	
	printf ("Este programa lee por teclado un numero para asignarle el valor a (x), para calcular e^x.\n\n");
	printf ("Por favor digite el valor de (x): ");
	scanf ("%f", &x);

    printf ("Por favor digite el numero de terminos de la serie: ");
	scanf ("%i", &n);
	
	i = 2;
	do{
		fac = ff(fan, fac);
		res = pow(x, pot) / fac;
		s = s + res;
		fac = 1;
		fan = fan + 1;
		pot = pot + 1;
		i = i + 1;
	} while(i <= n);
	
	s = s + 1;
	printf ("\n\nEl resultado de e^(%0.0f) es: %f", x, s);
	
	printf("\n\n");
	system("pause");
	return 0;
}

int ff(int fan, int fac){
	int i = 1;
	do{
		fac = fac*i;
		i = i + 1;
	} while(i <= fan);

	return fac;
}
