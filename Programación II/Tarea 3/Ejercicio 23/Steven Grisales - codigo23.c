/*
Fecha de publicaci�n: 2/09/2022
Hora: 9:43 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa calcula los resultados de esta funci�n usando la serie de Taylor
cosh(x) =       x^2     x^4    x^6     x^8  
            1 + ---  +  --- +  ---  +  --- ...
                2!       4!     6!      8!
se pide el valor de x y el n�mero de terminos de la serie
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void mos(int, int, int, int, float, float, int);
int fact(int, int, int);

int main(){
	int x = 0; //Esta variable guardar� el valor de x insertado por teclado
	int n = 0; //Esta variable guardar� el valor del numero de terminos insertado por teclado
	int fac = 1; //Esta variable guardar� el valor del factorial
	int fan = 2; //Esta variable es el numero al que le vamos a sacar factorial
	float res = 0; //Esta variable guardar� el valor del resultado de cada termino
	float s = 1; //Esta variable guardar� el valor de la suma de todos los terminos
	int pot = 2; //Esta variable guardar� el valor de la potencia
	
	printf ("Por favor digite el valor de (x): ");
	scanf ("%i", &x);

    printf ("Por favor digite el numero de terminos de la serie: ");
	scanf ("%i", &n);	
	
	mos(x, n, fac, fan, res, s, pot);
	
	printf("\n\n");
	system("pause");
	return 0;
}

void mos(int x, int n, int fac, int fan, float res, float s, int pot){
	if(n > 1){
       fac = fact(1, fan, fac);
	   res = pow(x,pot) / fac; 
	   s = s + res;	
	   mos(x, n-1, fac = 1, fan+2, res = 0, s, pot+2);
	}
	else{
		printf ("\nEl COSH(%i) es: %f", x, s);
	} 
	return;
}
//cont es un contador al que siempre le mando un 1
int fact(int con, int fan, int fac){
	if(con <= fan){
		fac = fac * con;
		fact(con+1, fan, fac);
	}
	else{
		return fac;
	}
}
