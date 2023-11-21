#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coladinamica.h"
# define N 12

typedef struct {
    int numprioridades;
    Cola colas[N];
} ColaPrioridad;

void crearColaPrioridad(ColaPrioridad* cp);
void insertarEnPrioridad(ColaPrioridad* cp, Tarea t);
Tarea elementoMin(ColaPrioridad cp);
Tarea quitarMin(ColaPrioridad* cp);
int colaPrioridadVacia(ColaPrioridad cp);

void crearColaPrioridad(ColaPrioridad* cp) {
    int j;
    cp->numprioridades = N;
    for (j = 0; j < N; j++)
        crearCola(&(cp->colas[j]));
}

void insertarEnPrioridad(ColaPrioridad* cp, Tarea t) {
    if (t.prioridad < cp->numprioridades) {
        insertar(&(cp->colas[t.prioridad]), t);
    } else {
        puts("Tarea con prioridad fuera de rango");
    }
}

Tarea elementoMin(ColaPrioridad cp) {
    int i = 0;
    int indiceCola = -1;

    // Buscar la primera cola no vacía
    while (i < cp.numprioridades && colaVacia(cp.colas[i])) {
        i++;
    }

    if (i < cp.numprioridades) {
        // Obtener el elemento del frente de la cola no vacía
        TipoDato dato = frente(cp.colas[i]);
        Tarea tarea;
        tarea.prioridad = i;
        strcpy(tarea.nombre, dato.nombre);
        return tarea;
    } else {
        puts("Cola de prioridad vacía");
        exit(-1);
    }
}

Tarea quitarMin(ColaPrioridad* cp) {
    int i = 0;
    int indiceCola = -1;

    // Buscar la primera cola no vacía
    while (i < cp->numprioridades && colaVacia(cp->colas[i])) {
        i++;
    }

    if (i < cp->numprioridades) {
        // Quitar el elemento del frente de la cola no vacía
        TipoDato dato = quitarC(&(cp->colas[i]));
        Tarea tarea;
        tarea.prioridad = i;
        strcpy(tarea.nombre, dato.nombre);
        return tarea;
    } else {
        puts("Cola de prioridad vacía");
        exit(-1);
    }
}

int colaPrioridadVacia(ColaPrioridad cp) {
    int i = 0;

    while (colaVacia(cp.colas[i]) && i < cp.numprioridades - 1)
        i++;

    return colaVacia(cp.colas[i]);
}





