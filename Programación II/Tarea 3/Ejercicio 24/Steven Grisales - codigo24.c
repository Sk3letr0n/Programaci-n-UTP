/*
Fecha de publicaci�n: 03/09/2022
Hora: 3:11 a.m.
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
void mos(float, int, float, int, float, float, int);

int main(){
	float x = 0; //Esta variable guardar� el valor de x insertado por teclado
	int n = 0; //Esta variable guardar� el valor del numero de terminos insertado por teclado
	float con = 1;//Esta variable ser� inicializada en 1 hasta la cantidad total de terminos
	float res = 0; //Esta variable guardar� el valor del resultado de cada termino
	float s = 0; //Esta variable guardar� el valor de la suma de todos los terminos
	int pot = 1; //Esta variable guardar� el valor de la potencia
	int a = 1; //Para saber en que termino esta
	
	printf ("Por favor digite el valor de (x): ");
	scanf ("%f", &x);

    printf ("Por favor digite el numero de terminos de la serie: ");
	scanf ("%i", &n);	
	
	mos(x, n, con, a, res, s, pot);
	
	printf("\n\n");
	system("pause");
	return 0;
}

void mos(float x, int n, float con, int a, float res, float s, int pot){
	if(con <= n){
		if(a % 2 == 1){
			pot = con + 1;
			res = ((pow(-1, pot) * pow(x, con)) / con);
			s = s - res;
			mos(x, n, con+1, a+1, res = 0, s, pot);
		}
		if(a % 2 == 0){
			pot = con + 1;
			res = ((pow(-1, pot) * pow(x, con)) / con);
			s = s + res;
			mos(x, n, con+1, a+1, res = 0, s, pot);
		}
	} else {
		printf("\nEl ln(%f) es: %f", x, s);
	}
	return;
}
