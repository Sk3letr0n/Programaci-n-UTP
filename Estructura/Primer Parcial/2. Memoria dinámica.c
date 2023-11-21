// Punto 2 del Primer Parcial - Marzo 23/2023
// Realizado por Steven Grisales López - 1034289634

#include <stdio.h>
#include <stdlib.h>
#define maximo 20

typedef struct {
    unsigned int num_reg;
    char nombre[maximo];
    float nota;
} legajo;

void cargardatos(legajo *, int);
void mostrardatos(legajo *, int);

int main(){
    int nEst = 0;
    legajo *p = NULL;

    printf("Digite el numero de estudiantes: ");
    scanf("%i", &nEst);

    system("cls");

    p = (legajo *) malloc(nEst * sizeof(legajo));

    if(p == NULL){
        printf("No hay memoria disponible.");
        exit(-1);
    }

    cargardatos(p, nEst);

    printf("\n");
    mostrardatos(p, nEst);
    printf("\n");

    free(p);

    return 0;
} 

void cargardatos(legajo *p, int nEst) {
    int i;
    for(i = 0; i < nEst; i++) {
        (p+i)->num_reg = i+1;
        printf("Digite el nombre del estudiante %i: ", (p+i)->num_reg);
        scanf("%s", (p+i)->nombre);
        
        printf("Digite la nota del estudiante: ");
        scanf("%f", &(p+i)->nota);

        printf("\n");
    }
}

void mostrardatos(legajo *p, int nEst) {
    int i;
    for(i = 0; i < nEst; i++) {
        printf("Numero de registro: %i", (p+i)->num_reg);
        printf("\nNombre del estudiante: %s", (p+i)->nombre);
        printf("\nNota del estudiante: %0.2f", (p+i)->nota);
        printf("\n\n");
    }
}