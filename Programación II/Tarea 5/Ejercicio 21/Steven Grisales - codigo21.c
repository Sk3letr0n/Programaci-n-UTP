/*
Fecha de publicación: 16/09/2022
Hora: 8:30 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa calcula los resultados de esta función usando la serie de Taylor
cos(x) =    x^2     x^3      x^4     x^5  
       1 -  ---  +  ---  -   ---  +  --- ....
             2!      4!       6!      8!
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
	int i = 2; //Es un iterador que nos indica en que termino vamos
	
	printf ("Este programa lee por teclado un numero para asignarle el valor a (x), para calcular cos(x).\n\n");
	printf ("Por favor digite el valor de (x): ");
	scanf ("%f", &x);

    printf ("Por favor digite el numero de terminos de la serie: ");
	scanf ("%i", &n);
	
	while(i <= n){
		
		if(i % 2 == 0){ 
			fac = ff(fan, fac);
	        res = pow(x,pot) / fac; 
	        s = s - res;	
	    }
	    else{
		}
		
	    if(i % 2 == 1){
	    	fac = ff(fan, fac);
		    res = pow(x,pot) / fac; 
	        s = s + res;	
	    }
	    else{
		}
		fac = 1;
		fan = fan + 2;
	    pot = pot + 1;
	    i = i + 1;
	}	
	s = s + 1;
	printf ("\n\nEl resultado de cos^(%0.0f) es: %f", x, s);
	
	printf("\n\n");
	system("pause");
	return 0;
}

int ff(int fan, int fac){
	int i = 1; //Esta variable multiplica al factorial
	
	while(i <= fan){
		fac = fac * i;
		i = i + 1; 
	}
	return fac;
}
