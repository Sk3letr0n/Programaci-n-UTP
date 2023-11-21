// Código (apuntador a arreglo) - Revisado por Steven Grisales López
/* Toco hacer ajustes en los 3 printf cambiando todo por %p */

#include <stdio.h>

/* Este programa crea un apuntador de tipo entero
que apunta al inicio de un arreglo. */

int main(){
    short arr[5], *apArr;
    apArr = &arr[0];
    // imprime la dirección de memoria del arreglo en la posición [0]
    printf("Direccion del arreglo en la primera posicion: %p\n", &arr[0]);
    // imprime la dirección de memoria del arreglo
    // (el nombre del arreglo es un apuntador)
    printf("Direccion del arreglo: %p\n", &arr);
    // imprime la direccion de memoria del apuntador apArr
    printf("Direccion del apuntador: %p\n", apArr);

    return 0;
}