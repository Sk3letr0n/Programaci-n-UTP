// Hecho por Steven Grisales López.
#include <stdio.h>
#include "libreria.h"

int main(){
	int a, b;
	
	printf("Ingrese el valor de a: ");
	scanf("%i", &a);
	printf("Ingrese el valor de b: ");
	scanf("%i", &b);
	
	printf("Los valores de a y b son: %i, %i\n", a, b);
	
	printf("La funcion multiplicacion funciona: %i", multiplicacion(a,b));
	printf("\nLa funcion suma funciona: %i", suma(a,b));
	printf("\nLa funcion resta funciona: %i", resta(a,b));
	
	return 0;
}
