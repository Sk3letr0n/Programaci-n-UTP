#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// Definicion de la estructura Monticulo
#define MAXNODOS 1001 // Constante que define el tamaño maximo del Monticulo

typedef struct {
    
    int v[MAXNODOS + 1]; // Arreglo de enteros que representa el Monticulo
    
    int maxNodos; // Tamano maximo del Monticulo
    
    int n; // Numero actual de elementos en el Monticulo

} Monticulo;

// Funcion para flotar un nodo hacia arriba en el Monticulo
void flotar(Monticulo *mnlo, int i) {
    int nuevaClave;

    nuevaClave = mnlo->v[i]; // Almacenar la clave del nodo a flotar
    
    while ((i > 1) && (mnlo->v[i / 2] > nuevaClave)) { // Mientras el nodo padre sea mayor que el nodo actual
        
        mnlo->v[i] = mnlo->v[i / 2]; // Intercambiar los nodos
        
        i = i / 2; // Actualizar la posicion del nodo actual
    
    }
    
    mnlo->v[i] = nuevaClave; // Colocar el nodo actual en su posicion correcta
}

// Funcion para insertar un nuevo nodo en el Monticulo
void insertar(Monticulo *mnlo, int clave) {
    if (mnlo->n == mnlo->maxNodos) { // Si el Monticulo esta lleno
        
        printf("\nNo es posible insertar nuevas claves: monticulo lleno");
        
        return;
    }
    
    mnlo->n++; // Incrementar el numero de nodos en el Monticulo
    
    mnlo->v[mnlo->n] = clave; // Agregar el nuevo nodo en la ultima posicion
    
    flotar(mnlo, mnlo->n); // Flotar el nuevo nodo hasta su posicion correcta
}

// Funcion para verificar si el Monticulo esta vacio
bool esVacio(Monticulo *mnlo) {

    return (mnlo->n == 0);

}

// Funcion para buscar la clave del nodo con el valor minimo en el Monticulo
int buscarMinimo(Monticulo *mnlo) {

    if (!esVacio(mnlo)) { // Si el Monticulo no esta vacio

        return mnlo->v[1]; // La clave del valor minimo es la del primer nodo
    
    }
}

// Funcon para intercambiar dos valores enteros
void intercambiar(int *a, int *b) {

    int temp = *a;

    *a = *b;

    *b = temp;
}

void criba(int v[], int primero, int ultimo){
    // Declaracion de variables locales
    int esMonticulo;

    int hijo;

    // Inicializacion de variable esMonticulo
    esMonticulo = 0;

    // Mientras el primer nodo no sobrepase el ultimo y no sea un monticulo
    while ((primero <= ultimo) && !esMonticulo){
        
        // Si el primer nodo tiene un solo hijo
        if (2*primero == ultimo){
            // El hijo es el unico hijo del nodo
            hijo = 2*primero;

        } else {
            // Si no, se compara los dos hijos del nodo y se escoge el menor
            if (v[2*primero] < v[2*primero+1]){

                hijo = 2*primero;

            } else {

                hijo = 2*primero+1;

            }

            // Si el valor del hijo es menor que el valor del padre, se intercambian
            if (v[hijo] < v[primero]){

                intercambiar(&v[primero], &v[hijo]);

                primero = hijo;

            } else {
                // Si no se cumple la condicion anterior, el arbol es un monticulo
                esMonticulo = 1;

            }
        }
    }
}

// Funcion que elimina el valor minimo del monticulo
int eliminarMinimo(Monticulo* mnlo){

    // Si el monticulo no esta vacio
    if(!esVacio(mnlo)){

        // Buscar el valor minimo
        int menor = buscarMinimo(mnlo);

        // Reemplazar el valor minimo por el ultimo valor del monticulo
        mnlo ->v[1] = mnlo ->v[mnlo->n];

        // Decrementar el numero de elementos en el monticulo
        (mnlo->n)++;

        // Mantener la propiedad de monticulo a partir del nodo raiz (1)
        criba(mnlo->v ,1 , mnlo->n);

        // Retornar el valor minimo eliminado
        return menor;

    }

}

