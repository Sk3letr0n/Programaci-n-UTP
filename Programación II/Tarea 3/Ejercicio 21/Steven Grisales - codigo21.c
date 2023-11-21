/*
Fecha de publicación: 2/09/2022
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
void mos(int, int, int, int, float, float, int, int);
int fact(int, int, int);

int main(){
	int x = 0; //Esta variable guardará el valor de x insertado por teclado
	int n = 0; //Esta variable guardará el valor del numero de terminos insertado por teclado
	int fac = 1; //Esta variable guardará el valor del factorial
	int fan = 2; //Esta variable es el numero al que le vamos a sacar factorial
	float res = 0; //Esta variable guardará el valor del resultado de cada termino
	float s = 1; //Esta variable guardará el valor de la suma de todos los terminos
	int pot = 2; //Esta variable guardará el valor de la potencia
	int a = 2; //Esta variable ayudara a saber en que termino vamos
	
	printf ("Por favor digite el valor de (x): ");
	scanf ("%i", &x);

    printf ("Por favor digite el numero de terminos de la serie: ");
	scanf ("%i", &n);	
	
	mos(x, n, fac, fan, res, s, pot, a);
	
	printf("\n\n");
	system("pause");
	return 0;
}


void mos(int x, int n, int fac, int fan, float res, float s, int pot, int a){	
	if(n > 1){ 
		if(a % 2 == 0){
			fac = fact(1, fan, fac);
	        res = pow(x,pot) / fac; 
	        s = s - res;	
	        mos(x, n-1, fac = 1, fan+2, res = 0, s, pot+1, a+1);
	    }
	    if(a % 2 == 1){
	    	fac = fact(1, fan, fac);
		    res = pow(x,pot) / fac; 
	        s = s + res;	
	        mos(x, n-1, fac = 1, fan+2, res = 0, s, pot+1, a+1);
	    }  
	} else{	
		printf ("\nCon 10 terminos el COS(%i) es: %f", x, s); 
	}
	return;
}
//con es un contador que siempre recibe un 1
int fact(int con, int fan, int fac){
	if(con <= fan){
		fac = fac * con;
		fact(con+1, fan, fac);
	}
	else{
		return fac;
	}
}
