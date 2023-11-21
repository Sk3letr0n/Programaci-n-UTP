// Autor: Steven Grisales López. Fue modificado por errores de funcionalidad.
#include <stdio.h>
#include <stdbool.h>

#define MAXTAMQ 100

typedef struct {
    char listaCola[MAXTAMQ];
    int frente, final;
} Cola;

// Siguiente circular.
int siguiente(int n){
	return (n + 1) % MAXTAMQ;
}

// Crear Cola. Inicializa una cola vacía.
void crearCola(Cola* cola){
	cola->frente = 0;
	cola->final = MAXTAMQ - 1;
}

// Cola Vacía.
bool colaVacia(Cola cola){
	return cola.frente == siguiente(cola.final);
}

// Cola Llena. Prueba si la cola no puede contener más elementos. En el array queda una posición no ocupada, y así se distingue de la condición de cola vacía.
bool colaLlena(Cola cola){
	return cola.frente == siguiente(siguiente(cola.final));
}

// Insertar. El índice final apunta al último elemento insertado; éste avanza circularmente.
void insertar(Cola* cola, char entrada){
	if (colaLlena(*cola) ){
		puts("Desbordamiento de cola");
		return;
	}
	/* avance circular al siguiente del final */
	cola->final = siguiente(cola->final);
	cola->listaCola[cola->final] = entrada;
}

// Quitar. El índice frente avanza circularmente.
char* quitar(Cola* cola){
    char* tmp;
    if (colaVacia(*cola)){
        puts (" Extracción en cola vacía ");
        exit (1);
    }
    tmp = &(cola -> listaCola[cola -> frente]); // asignar puntero al elemento extraído
    /* avanza circularmente frente */
    cola -> frente = siguiente (cola -> frente);
    return tmp;
}

// Frente. Obtiene el elemento del frente o primero de la cola, sin modificar la cola.
char frente(Cola cola){
	if (colaVacia(cola)){
		puts("Se requiere frente de una cola vacía");
		return '\0';
	}
	return cola.listaCola[cola.frente];
}
