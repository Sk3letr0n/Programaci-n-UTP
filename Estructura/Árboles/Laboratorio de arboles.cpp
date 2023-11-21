/*
Autor: Steven Grisales López.
Fecha: 2023-05-08.
Descripción: Este programa lee un archivo de texto y cuenta el número de palabras diferentes que contiene y la frecuencia de cada una.
*/

// Librerías.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

#define MAX_CAR 100 // Número máximo de caracteres por palabra.
#define DIMBUFFER 100 // Dimensión del buffer para almacenar las palabras.

using namespace std;

char buffer[DIMBUFFER]; // Buffer para almacenar las palabras.

// Prototipos de funciones.
int leerArchivo();
int leerTeclado();

int main() {

    int opcion = 0; // Opción del menú.

    printf("############## MENU #############\n");
    printf("\nOpcion 1: Leer un archivo.");
    printf("\nOpcion 2: Leer cadena de texto por teclado.");
    printf("\nOpcion 3: Salir");
    printf("\nDigite una opcion: ");
    scanf("%i", &opcion);


    switch (opcion){
        case 1:
            leerArchivo();
        break;
        case 2: 
            leerTeclado(); 
        break;
        case 3: 
            printf("\nSaliendo del programa...");
            exit(0);
        default: 
        printf("\nOpcion invalida");
        break;
    }
}

//Esta estructura almacena una palabra y su frecuencia.
typedef struct nodo{
    char palabra[50]; // Palabra almacenada en el nodo.
    int contador; // Frecuencia de la palabra.
    struct nodo *izquierda; // Subárbol izquierdo.
    struct nodo *derecha; // Subárbol derecho.
} Nodo;

// Esta función agrega una palabra al árbol.
void agregar_palabra(Nodo **raiz, char *palabra){
    if(*raiz == NULL){ // Verifica si el árbol está vacío.
        *raiz = (Nodo*) malloc(sizeof(Nodo)); // Reserva memoria para un nuevo nodo.
        strcpy((*raiz) -> palabra, palabra); // Copia la palabra al nodo.
        (*raiz) -> contador = 1; // Inicializa la frecuencia de la palabra.
        (*raiz) -> izquierda = NULL; // Inicializa los subárboles izquierdo y derecho.
        (*raiz) -> derecha = NULL; // Inicializa los subárboles izquierdo y derecho.
    } else {
        int cmp = strcmp(palabra, (*raiz) -> palabra); // Compara la palabra con la palabra almacenada en el nodo.
        if (cmp == 0){ // Verifica si la palabra es igual a la palabra almacenada en el nodo.
            (*raiz) -> contador++; // Incrementa la frecuencia de la palabra.
        }
        else if (cmp < 0){ // Verifica si la palabra es menor que la palabra almacenada en el nodo.
            agregar_palabra(&((*raiz) -> izquierda), palabra); // Agrega la palabra al subárbol izquierdo.
        } else {
            agregar_palabra(&((*raiz) -> derecha), palabra); // Agrega la palabra al subárbol derecho.
        }
    }
}

// Esta función cuenta el número de palabras diferentes en el árbol.
int contar_palabras_diferentes(Nodo *raiz){
    if (raiz == NULL){
        return 0; // Si el árbol está vacío, devuelve 0.
    } else {
        return 1 + contar_palabras_diferentes(raiz->izquierda) + contar_palabras_diferentes(raiz->derecha); // Suma 1 por cada nodo.
    }
}

// Esta función imprime el árbol en orden.
void imprimir_arbol(Nodo *raiz) { 
    if (raiz != NULL) { // Verifica que el árbol no esté vacío.
        imprimir_arbol(raiz -> izquierda); // Recorre el subárbol izquierdo.
        printf("%s = %d\n", raiz -> palabra, raiz -> contador); // Imprime la palabra y su frecuencia.
        imprimir_arbol(raiz -> derecha); // Recorre el subárbol derecho.
    }
}

// Esta función libera la memoria reservada para el árbol.
void liberar_arbol(Nodo *raiz){
    if (raiz != NULL) { // Verifica que el árbol no esté vacío.
        liberar_arbol(raiz -> izquierda); // Libera el subárbol izquierdo.
        liberar_arbol(raiz -> derecha); // Libera el subárbol derecho.
        free(raiz); // Libera el nodo.
    }
}

// Esta función lee un archivo de texto y cuenta el número de palabras diferentes que contiene y la frecuencia de cada una.
int leerArchivo(){
    Nodo *arbol = NULL; // Árbol binario.
    char palabra[50]; // Almacena una palabra.
    int total_palabras = 0; // Almacena el total de palabras.
    int total_palabras_diferentes = 0; // Almacena el total de palabras diferentes.

    FILE *archivo = fopen("texto.txt", "r"); // Abre el archivo en modo lectura.
 
    if (archivo == NULL) { // Verifica si el archivo se abrió correctamente.
        printf("Error al abrir el archivo\n"); // Imprime un mensaje de error.
        return 1; 
    }

    while (fscanf(archivo, "%s", palabra) != EOF) {  // Lee una palabra del archivo.
        total_palabras++; // Incrementa el total de palabras.

        for (int i = 0; i < strlen(palabra); i++) { // Convierte la palabra a minúsculas.
            palabra[i] = tolower(palabra[i]); // Convierte el caracter a minúscula.
        }

        agregar_palabra(&arbol, palabra); // Agrega la palabra al árbol.
    }

    fclose(archivo); 
    printf("Frecuencia de palabras:\n"); 

    imprimir_arbol(arbol); // Imprime el árbol en orden.
    total_palabras_diferentes = contar_palabras_diferentes(arbol); // Cuenta el número de palabras diferentes.
    printf("Total de palabras: %d\n", total_palabras); 
    printf("Total de palabras diferentes: %d\n", total_palabras_diferentes);
    liberar_arbol(arbol); // Libera la memoria reservada para el árbol.

    return 0;
}

//--------------------------------------------------------------------------//
// Esta función lee una palabra desde el teclado y la agrega al árbol.
int leerTeclado(){

    system("cls"); // Limpia la pantalla.

    Nodo *arbol = NULL; // Árbol binario.
    char palabra[50]; // Almacena una palabra.
    int total_palabras = 0; // Almacena el total de palabras.
    int total_palabras_diferentes = 0; // Almacena el total de palabras diferentes.
    int i; // Contador.
    

    while (strcmp(palabra,"!") != 0) { // Verifica si la palabra es igual a !.
        fflush(stdin); // Limpia el buffer del teclado.
        printf("\nIngrese una palabra.Si no desea ingresar mas palabras ingrese [!]:");
        scanf("%s",palabra);

        if (strcmp(palabra,"!") == 0){ // Verifica si la palabra es igual a !.

            printf("\nIngreso de palabras terminado...");
            printf("\n\nFrecuencia de palabras:\n");

            imprimir_arbol(arbol); // Imprime el árbol en orden.
            total_palabras_diferentes = contar_palabras_diferentes(arbol); // Cuenta el número de palabras diferentes.

            printf("\nTotal de palabras: %d\n", total_palabras);
            printf("\nTotal de palabras diferentes: %d\n\n", total_palabras_diferentes);

            liberar_arbol(arbol); // Libera la memoria reservada para el árbol.
            system("pause");

            return 0;
        }
    

        total_palabras++;

        for (i = 0; i < (int) strlen(palabra); i++) { // Convierte la palabra a minúsculas.
            palabra[i] = tolower(palabra[i]); // Convierte el caracter a minúscula.
        }

        agregar_palabra(&arbol, palabra); // Agrega la palabra al árbol.
    }

    return 0;
}