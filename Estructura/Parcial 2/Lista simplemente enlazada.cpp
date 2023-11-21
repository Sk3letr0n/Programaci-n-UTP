// Parcial 2 Estructura de Datos. Código de practica 3 (Lista simplemente enlazada) Hecho por Steven Grisales López.

#include <stdio.h>
#include <stdlib.h>

// Estructura de la lista.
typedef struct Nodo{
	int codigo; // Dato que va a guardar la lista.
	struct Nodo* siguiente; // Puntero que apunta al siguiente elemento de la lista.
} Nodo;

// Prototipos de las funciones.
Nodo* crearNodo(int x);
void insert_order(Nodo** cabeza, int entrada);
void mostrar(Nodo *cabeza);

int main(){
	Nodo *cabeza = NULL;
	int entrada, valor;
	char validacion = 0;
	
    printf("Ingrese un numero: ");
    scanf("%i", &valor);
    insert_order(&cabeza, valor); // Llamamos a la función insert_order para insertar los números ordenados de menor a mayor.
	mostrar(cabeza); // Llamamos a la función mostrar para recorrer mediante la cabeza la lista y así imprimir la lista.
	
	printf("\nDesea ingresar otro numero? (s/n): ");
	scanf("%s", &validacion);
	
	// Validamos que la opción sea s o S para volver a ingresar otro numero.
	while(validacion == 's' || validacion == 'S') { 
		printf("Ingrese un numero: ");
		scanf("%i", &valor);
		insert_order(&cabeza, valor); // Llamamos a la función insert_order para insertar los números ordenados de menor a mayor.
		mostrar(cabeza); // Llamamos a la función mostrar para recorrer mediante la cabeza la lista y así imprimir la lista.
		
		printf("\nDesea ingresar otro numero? (s/n): ");
		scanf("%s", &validacion);
		
		if(validacion == 's' || validacion == 'S'){
			printf("Ingrese un numero: ");
			scanf("%i", &valor);
			insert_order(&cabeza, valor); // Llamamos a la función insert_order para insertar los números ordenados de menor a mayor.
			mostrar(cabeza); // Llamamos a la función mostrar para recorrer mediante la cabeza la lista y así imprimir la lista.
		} else {
			exit(1);
		}
    }
    	
    return 0;
}

// Función para crear un nuevo nodo.
Nodo* crearNodo(int x){
    Nodo *a; // Puntero al nuevo nodo.
    a = (Nodo*) malloc(sizeof(Nodo)); // Reserva memoria para el nuevo nodo.
    a -> codigo = x; // Asigna el dato al nodo.
    a -> siguiente = NULL; // Inicializa el puntero al siguiente nodo en NULL.
    return a; 
}

// Función para insertar un nodo en orden ascendente.
void insert_order(Nodo **cabeza, int entrada) {
    Nodo *nuevo = crearNodo(entrada); // Crea el nuevo nodo.
    if (*cabeza == NULL || entrada < (*cabeza) -> codigo) { // Si la lista está vacía o el dato es menor que el primer nodo, se inserta al inicio de la lista.
        // Inserta al inicio de la lista.
        nuevo -> siguiente = *cabeza;
        *cabeza = nuevo; 
    } else {
        // Busca el nodo anterior al punto de inserción.
        Nodo *anterior = *cabeza; // Se inicia con el primer nodo.
        while (anterior -> siguiente != NULL && anterior -> siguiente -> codigo < entrada) { // Mientras no se llegue al final de la lista y el nodo siguiente sea menor que el que se quiere insertar, se sigue buscando.
            anterior = anterior -> siguiente; // Se avanza en la lista.
        }
        // Inserta el nuevo nodo en el lugar adecuado.
        nuevo -> siguiente = anterior -> siguiente;
        anterior -> siguiente = nuevo; 
    }
}

// Función para recorrer e imprimir la lista.
void mostrar(Nodo* cabeza){
	int k; // Variable para el salto de línea.	
    printf ("\n\t\t Lista \n"); // Imprime el título de la lista.
	for (k = 0; cabeza; cabeza = cabeza -> siguiente){ // Recorre la lista.
		printf ("%d ",cabeza -> codigo); // Imprime el dato del nodo actual.
		k++;
		printf ("%c",(k % 15 ?' ':'\n') ); // Si k es múltiplo de 15, imprime un salto de línea, de lo contrario, imprime un espacio.
	}
	printf ("\n\n");
}
