/*						OPERACIONES
1. Siguiente: Obtiene la posición siguiente de una cola.
2. Crear cola: Inicia la cola como vacia.
3. Insertar: Añade un dato por el final de la cola.
4. Quitar: Retira (extrae) el elemento frente de la cola.
5. Frente: Obtiene el elemento frente o primero de la cola.
6. Cola Vacia: Comprobar si la cola no tiene elementos.
7. Cola llena: Comprobar si la cola está llena de elementos.
*/

#include <stdlib.h>
#include <stdio.h>

#define MAXTAMQ 100

typedef struct {
    int prioridad;
    char nombre[51];
} Tarea;

typedef Tarea TipoDato;

typedef struct {
    TipoDato listaCola[MAXTAMQ];
    int frente, final;
} Cola;

int siguiente(int n);
void crearCola(Cola* cola);
void insertar(Cola* cola, TipoDato entrada);
TipoDato quitarC(Cola* cola);
TipoDato frente(Cola cola);
int colaVacia(Cola cola);
int colaLlena(Cola cola);

int siguiente(int n) {
    return (n + 1) % MAXTAMQ;
}

void crearCola(Cola* cola) {
    cola->frente = 0;
    cola->final = MAXTAMQ - 1;
}

void insertar(Cola* cola, TipoDato entrada) {
    if (colaLlena(*cola)) {
        puts("Desbordamiento de cola");
        exit(1);
    }
    
    cola->final = siguiente(cola->final);
    cola->listaCola[cola->final] = entrada;
}

TipoDato quitarC(Cola* cola) {
    TipoDato tmp;
    
    if (colaVacia(*cola)) {
        puts("Extracción en cola vacía");
        exit(1);
    }
    
    tmp = cola->listaCola[cola->frente];
    cola->frente = siguiente(cola->frente);
    return tmp;
}

TipoDato frente(Cola cola) {
    if (colaVacia(cola)) {
        puts("Se requiere frente de una cola vacía");
        exit(1);
    }
    
    return cola.listaCola[cola.frente];
}

int colaVacia(Cola cola) {
    return cola.frente == siguiente(cola.final);
}

int colaLlena(Cola cola) {
    return cola.frente == siguiente(siguiente(cola.final));
}
