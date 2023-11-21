// Punto 1 del Primer Parcial - Marzo 23/2023
// Realizado por Steven Grisales López - 1034289634
#include <stdio.h>

int main(){
	int u1, u2;
	int v = 3;
	int *pv; /* puntero a enteros*/
	u1 = 2 * (v + 5); /* expresion ordinaria */
	pv = &v; /* pv a punta a v */
	
	/* expresion alternativa */ u2 = 2 * (*pv + 5);
	
	printf("\n u1 = %i u2 = %i", u1, u2);
	
	return 0; 
}
