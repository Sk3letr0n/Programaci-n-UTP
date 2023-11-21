#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct nodo {

    char palabra[50];

    int contador;

    struct nodo *izquierda;

    struct nodo *derecha;
    
} Nodo;

void agregar_palabra(Nodo **raiz, char *palabra) {

    if (*raiz == NULL) {

        *raiz = (Nodo*)malloc(sizeof(Nodo));

        strcpy((*raiz)->palabra, palabra);

        (*raiz)->contador = 1;

        (*raiz)->izquierda = NULL;

        (*raiz)->derecha = NULL;

    } else {

        int cmp = strcmp(palabra, (*raiz)->palabra);

        if (cmp == 0) {

            (*raiz)->contador++;

        } else if (cmp < 0) {

            agregar_palabra(&((*raiz)->izquierda), palabra);

        } else {

            agregar_palabra(&((*raiz)->derecha), palabra);

        }
    }
}

int contar_palabras_diferentes(Nodo *raiz) {

    if (raiz == NULL) {

        return 0;

    } else {

        return 1 + contar_palabras_diferentes(raiz->izquierda) + contar_palabras_diferentes(raiz->derecha);

    }
}


void imprimir_arbol(Nodo *raiz) {

    if (raiz != NULL) {

        imprimir_arbol(raiz->izquierda);

        printf("%s = %d\n", raiz->palabra, raiz->contador);

        imprimir_arbol(raiz->derecha);

    }
}

void liberar_arbol(Nodo *raiz) {

    if (raiz != NULL) {

        liberar_arbol(raiz->izquierda);

        liberar_arbol(raiz->derecha);

        free(raiz);

    }
}

int leerArchivo(){
    
    Nodo *arbol = NULL;

    char palabra[50];

    int total_palabras = 0;

    int total_palabras_diferentes = 0;

    FILE *archivo = fopen("../prueba.txt", "r");

    if (archivo == NULL) {

        printf("Error al abrir el archivo\n");

        return 1;
    }

    while (fscanf(archivo, "%s", palabra) != EOF) {
        total_palabras++;

        for (int i = 0; i < strlen(palabra); i++) {

            palabra[i] = tolower(palabra[i]);

        }

        agregar_palabra(&arbol, palabra);
    }

    fclose(archivo);

    printf("Frecuencia de palabras:\n");

    imprimir_arbol(arbol);

    total_palabras_diferentes = contar_palabras_diferentes(arbol);

    printf("Total de palabras: %d\n", total_palabras);

    printf("Total de palabras diferentes: %d\n", total_palabras_diferentes);

    liberar_arbol(arbol);

    return 0;
}

int main() {

    leerArchivo();
    
    return 0;
}
