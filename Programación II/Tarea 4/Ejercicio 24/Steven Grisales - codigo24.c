/*
Fecha de publicaci�n: 11/09/2022
Hora: 9:21 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa calcula los resultados de esta funci�n usando la serie de Taylor
ln(x+1) =  ((-1)^n+1)x^n     ((-1)^(n+1)+1) x^n+1     ((-1)^(n+1)+1) x^n+1 
         - -------------  +  --------------------  -  ---------------------  +  ....
                 n                    n+1                      n+1
se pide el valor de x y el n�mero de terminos de la serie
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	float x = 0; //Esta variable guardar� el valor de x insertado por teclado
	int n = 0; //Esta variable guardar� el valor del numero de terminos insertado por teclado
	float de = 2; //Esta variable guardar� el numero que va a dividir cada termino
	float res = 0; //Esta variable guardar� el valor del resultado de cada termino
	float s = 0; //Esta variable guardar� el valor de la suma de todos los terminos
	int pot = 2; //Esta variable guardar� el valor de la potencia
	int i = 0; //Esta variable es un iterador que nos indica en que termino vamos
	
	printf ("Este programa lee por teclado un numero para asignarle el valor a (x), para calcular ln(x).\n\n");
	printf ("Por favor digite el valor de (x): ");
	scanf ("%f", &x);

    printf ("Por favor digite el numero de terminos de la serie: ");
	scanf ("%i", &n);
		
	for(i = 2; i <= n; i = i + 1){
		if(i % 2 == 0){
	        res = pow((x-1),pot) / de; 
	        s = s - res;	
	    }
	    else{
		}
	    if(i % 2 == 1){
	    	res = pow((x-1),pot) / de; 
	        s = s + res;	
	    } 
		else {
		}
	    pot = pot + 1;
	    de = de + 1;
	}	
	s = s + (x-1);
	printf ("\n\nEl resultado de ln^(%0.0f) es: %f", x, s);
	
	printf("\n\n");
	system("pause");
	return 0;
}
