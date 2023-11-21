/*
Hecho por Steven Grisales López - 1034289634.
Fecha: 1/03/2023.
Punto 1. Busqueda binaria con ordenamiento de inserción.
*/
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TAM 100

// Esta función se encarga de imprimir todos los elementos que hayan en el arreglo
void imprimeCB(int *CB) {
	int i; // Esta variable es un iterador que lleva la cuenta de cuantas veces se imprime los elementos del array

	for(i = 0; i < TAM - 1; i++) {
		printf( "%d, ", CB[i]);
	}
	printf( "%d\n", CB[i]);
}

// Función main
int main() {
	int CB[TAM]; // Esta variable es un arreglo de 100 posiciones
	int ini = 0, fin = TAM - 1, mitad, dato, i, e = 0, k, temp; /* Estas variables son las siguientes:
	ini es el primer valor del arreglo, fin es el ultimo valor del arreglo, mitad es el valor medio del arreglo, dato es el valor a buscar.
	i es el iterador usado para recorrer el arreglo, e es el elemento inicial del arreglo para la inserción.
	k es la variable que nos ayuda a saber en que posición va cada valor según su ordenación y temp es un valor temporal que se ira modificando según i,e y k cambien.*/ 

	srand((unsigned int)time(NULL));
	for(i = 0; i < TAM; i++)
	CB[i] = (int)(rand() % 100);

	printf("\nAntes de ordenar----------------------------------------------\n");
	imprimeCB(CB);
	printf("\nDespues de ordenar----------------------------------\n");

	/*Ordenamiento por inserción. El primer elemento del array (CB[0]) se considera ordenado. A continuación se inserta el segundo elemento (CB[1]) en la posición correcta (delante o detrás de CB[0])
	dependiendo de que sea menor o mayor que CB[0]. Repetimos esta operación sucesivamente de tal modo que se va colocando cada elemento en la posición correcta. El proceso se repetirá TAM-1 veces.
	Para colocar el dato en su lugar, se debe encontrar la posición que le corresponde en la parte ordenada y hacerle un hueco de forma que se pueda insertar. Para encontrar la posición se puede hacer
	una búsqueda secuencial desde el principio del conjunto hasta encontrar un elemento mayor que el dado. Para hacer el hueco hay que desplazar los elementos pertinentes una posición a la derecha.*/ 
	for (e = 1; e < TAM; e++){
		temp = CB[e];
		i = 0;
		while (CB[i] <= temp)
		i++;
		if (i < e) {
			for(k = e; k > i; k--)
			CB[k] = CB[k-1];
			CB[i] = temp;
		}
	}

	imprimeCB(CB);

	// Generamos el dato mediante un random de 0 hasta 99
	dato = (int)(rand() % 100);
	CB[i] = dato;

	//Aplicamos el método de busqueda binaria. El cual consiste en dividir el arreglo en dos para colocar el dato necesitado en la mitad de este y así poder hallarlo más fácil.
	printf("Dato a buscar %d\n",dato);
	mitad = (ini + fin) / 2;

	while ((ini <= fin) && (CB[mitad] != dato)) {
		if (dato < CB[mitad])
		fin = mitad - 1;
		else ini = mitad + 1;
		mitad = (ini + fin) / 2;
	}
	if (dato == CB[mitad]) printf("Posicion %d\n", mitad);
	else printf("Elemento no esta en el array");

	getch();
	return 0;
}