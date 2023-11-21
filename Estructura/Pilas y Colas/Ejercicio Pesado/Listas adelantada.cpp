//Hecho por Steven Grisales López el 12/04/2023

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MX 101
typedef int Item;
typedef struct Elemento {
	Item dato;
	struct Elemento* siguiente;
} Nodo;

void insertaOrden (Nodo** cabeza, Item entrada);
Nodo* crearNodo (Item x);
void recorrer (Nodo* cabeza);
void eliminar (Nodo** cabeza, Item entrada);
void impar(Nodo* cabeza);
void inserFinal (Nodo** cabeza, int entrada);

int main (){
	Item d;
	Nodo* cabeza;
	cabeza = NULL; /* lista vacía */
	srand(time(NULL));
	//randomize ();
	/* bucle termina cuando se genera el número aleatorio 0 */
	for (d = rand()%MX; d;){
		insertaOrden (&cabeza,d);
		d = rand()%MX;
	}
	recorrer(cabeza);
	impar(cabeza);
	
	int entrada;
	printf("Ingrese un elemento al final: ");
	scanf("%i", &entrada);
	inserFinal(&cabeza,entrada);
	recorrer(cabeza);
}

void insertaOrden (Nodo** cabeza, Item entrada){
	Nodo *nuevo;
	nuevo = crearNodo (entrada);
	if (*cabeza == NULL)
		*cabeza = nuevo;
	else if (entrada < (*cabeza) -> dato) /* primer nodo */ {
		nuevo -> siguiente = *cabeza;
		*cabeza = nuevo;
	}
	else /* búsqueda del nodo anterior a partir del que se debe insertar */ {
		Nodo* anterior, *p;
		anterior = p = *cabeza;
		while ( (p -> siguiente != NULL) && (entrada > p -> dato) ){
			anterior = p;
			p = p -> siguiente;
		}
	if (entrada > p -> dato) /* inserta por el final */
		anterior = p;
		/* Se procede al enlace del nuevo nodo */
		nuevo -> siguiente = anterior -> siguiente;
		anterior -> siguiente = nuevo;
	}
}

Nodo* crearNodo (Item x){
	Nodo *a ;
	a = (Nodo*)malloc (sizeof(Nodo) );
	a -> dato = x;
	a -> siguiente = NULL;
	return a;
}

void recorrer (Nodo* cabeza){
	int k;
	printf ("\n\t\t Lista Ordenada \n");
	for (k = 0; cabeza; cabeza = cabeza -> siguiente){
		printf ("%d ",cabeza -> dato);
		k++;
		printf ("%c",(k%15 ?' ':'\n') );
	}
	printf ("\n\n");
}

void eliminar (Nodo** cabeza, Item entrada){
	Nodo* actual, *anterior;
	int encontrado = 0;
	actual = *cabeza; anterior = NULL;
	while ( (actual!=NULL) && (!encontrado) ){
		encontrado = (actual -> dato == entrada);
		if (!encontrado){
			anterior = actual;
			actual = actual -> siguiente;
		}
	}
	if (actual != NULL){
		if (actual == *cabeza)
			*cabeza = actual -> siguiente;
		else
			anterior -> siguiente = actual -> siguiente;
			free (actual);
	}
	else
	puts ("Nodo no eliminado, elemento no esta en la lista ");
}

void impar(Nodo* cabeza){
	int k;
	printf("\n\t\t Lista Ordenada con Impares \n");
	for(k = 0; cabeza; cabeza = cabeza -> siguiente){
		if((cabeza->dato) % 2 != 0){
			printf("%d ", cabeza -> dato);
			k++;
			printf("%c", (k % 15 ? ' ':'\n'));
		} else {
			k++;
		}
	}
	printf("\n\n");
}

void inserFinal (Nodo** cabeza, int entrada){
	Nodo *ultimo;
	ultimo = *cabeza;
	if (ultimo == NULL) /* lista vacía */ {
		*cabeza = crearNodo (entrada);
	} else {
		for (; ultimo -> siguiente; ) /* termina con ultimo referenciando al nodo final */
			ultimo = ultimo -> siguiente;
			ultimo -> siguiente = crearNodo (entrada);
	}
}
