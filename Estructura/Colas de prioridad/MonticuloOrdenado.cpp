/*
Autor: Steven Grisales Lopez.
Fecha: 12/05/2023.
Descripción: Este programa rellena aleatoriamente datos enteros en un vector y, mediante la estructura de monton minimo
ordena el vector crecientemente y lo presenta en pantalla.
*/

// Librerias.
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Max2 100
#define MAXIMO 100
using namespace std;
// Definicion de un elemento.
typedef int Telemento;

// Definicion de la estructura monticulo.
typedef struct{
	Telemento a[MAXIMO+1];
	int n;
} Monticulo;

// Funcion que crea un monticulo.
void CrearMonticulo(Monticulo* monticulo){
	monticulo->n = 0;
}

// Funcion que sube los elementos menores encontrados en los monticulos a su respectivo lugar.
void Subir(Monticulo* monticulo, int pos){
	Telemento Clave;
	int padre, esMonton = 0;
	Clave = monticulo->a[pos];
	padre = pos/2;
	
	while((padre >= 1)&& !esMonton){
		if(monticulo->a[padre] > Clave){
			monticulo->a[pos] = monticulo->a[padre];
			pos = padre;
			padre = padre/2;
		} else {
			esMonton = 1;
		}
		monticulo->a[pos] = Clave;
	}
}

// Funcion que inserta elementos en el monticulo.
void insertar(Monticulo* monticulo, Telemento Clave){
	if(monticulo->n == MAXIMO){
		puts("No es posible insertar nuevas claves: monticulo lleno ");
	}else{
		(monticulo->n)++;
		monticulo->a[monticulo->n] = Clave;
		Subir(monticulo, monticulo->n);
	}
}

// Funcion que busca el minimo en un monticulo.
Telemento BuscarMinimo(Monticulo monticulo){
	if(monticulo.n == 0)
		puts("Monticulo vacio");
	
	return monticulo.a[1];
}

// Funcion que retorna si el monticulo esta vacio.
int EsVacio(Monticulo monticulo){
	return monticulo.n == 0;
}

// Funcion que toma los datos de un arreglo y los inserta al monticulo.
void Criba(int a[], int primero, int ultimo){
	int EsMonticulo = 0, HijoMenor, aux;
	
	while((2*primero <= ultimo) && !EsMonticulo){
		if(2*primero == ultimo) {
			HijoMenor = 2*primero;
		} else {
			if(a[2*primero] < a[2*primero+1]) {
				HijoMenor = 2*primero;
			} else {
				HijoMenor = 2*primero+1;
			}
		}
			
		if(a[HijoMenor] < a[primero]){
			aux = a[primero];
			a[primero] = a[HijoMenor];
			a[HijoMenor] = aux;
			primero = HijoMenor;
		} else {
			EsMonticulo = 1;
		}
	}
}

// Funcion que elimina el minimo de un monticulo.
void EliminarMinimo(Monticulo* monticulo){
	if(EsVacio(*monticulo)){
		puts("No es posible eliminar clave: monticulo vacio");
		exit(1);
	} else {
		monticulo->a[1] = monticulo->a[monticulo->n];
		monticulo->n = monticulo->n - 1;
		Criba(monticulo->a, 1, monticulo->n);
	}
}

// Funcion que rellena de manera aleatoria el monticulo.
void Rellena(Telemento A[Max2], int *n){
	int i;
	srand(time(NULL));
	*n = rand()%Max2;
	
	for(i = 0; i < (*n); i++)
		A[i] = rand() % Max2;
}

// Funcion que va escribiendo los elementos en el monticulo.
void Escribe(Telemento A[], int n){
	int i;
	for( i = 0; i < n; i++){
		if((i+1)%10 == 0){
			printf("%7d\n", A[i]);
		}else{
			printf("%7d", A[i]);
		}
	}
}

// Funcion Main.
int main(void){
	Telemento a[Max2];
	int n, i;
	Monticulo monticulo;
	Rellena(a, &n);
	Escribe(a, n);
	
	CrearMonticulo(&monticulo);
	
	for(i = 0; i < n; i++) {
		insertar(&monticulo, a[i]);
	}
		
	for(i = 0; i < n; i++){
		a[i] = BuscarMinimo(monticulo);
		EliminarMinimo(&monticulo);
	}
	
	printf("\n\nDatos Ordenados\n\n");
	Escribe(a,n);
	
	return 0;
}
