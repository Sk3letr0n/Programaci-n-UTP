// Ejercicio 4 Arboles Hecho por Steven Grisales López.

#include <stdio.h>
#include<stdlib.h>

struct arbol{
	int dato;
	arbol *izquierdo;
	arbol *derecho;
};

arbol* insertarNodo(arbol *cabeza, int entrada){
	if(cabeza == NULL){
		arbol *nuevo = new(arbol);
		nuevo->dato = entrada;
		nuevo->derecho = NULL;
		nuevo->izquierdo = NULL;
		cabeza = nuevo;
		
	}else{
		if(entrada > cabeza->dato){
			cabeza = insertarNodo(cabeza->derecho, entrada);
		}
		else if(entrada < cabeza->dato){
			cabeza = insertarNodo(cabeza->izquierdo, entrada);
		}
		else{
			printf("\n Dato Repetido\n ");
			exit(1);
		}
	}
	
}

int main (){
	int elemento, opcion;
	arbol *raiz = NULL;
	
	return 0;
}
