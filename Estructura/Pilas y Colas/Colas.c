// Modificado y realizado por Steven Grisales López el 29/03/2023.

typedef char TipoDato;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "colacircular.h"
#include "libreria.h"

int main(){
    char d;
    Cola cola;
    Pila pila;
    int capicua = 0;
    crearCola(&cola);
    inicializar_pila(&pila);
    while (!capicua){
        printf (" N%cmero a investigar: ", 163);
        while ( (d = getchar ( ) )!= '\n'){
            if ( d < '0' || d > '9') {
                printf(" \n Error en el n%cmero introducido ", 163);
            } else {
                insertar(&cola, d);
                push(&pila, d);
            }
        }
        capicua = 0;
        do {
            capicua = *(quitar(&cola)) == pop(&pila);
        } while (capicua && !colaVacia (cola) );
        if (capicua){
            printf(" \n El numero introducido es capic%ca ", 163);
        } else {
            printf(" \n El numero no es capic%ca, intente con otro. \n ", 163 );
            crearCola (&cola); /* se inicializan las estructuras */
            inicializar_pila(&pila);
        }
    }
    return 0;
}