#include <stdio.h>
//El código si funciona
void cuboPorReferencia( int *ptrN);

int main() {
    int n = 5;
    
    printf("EL valor original de numero es %d", n); //Imprime el valor que hay en la variable n.

    cuboPorReferencia(&n); //Se le manda la dirección de memoria de la variable n a dicha función.

    printf("\nEl nuevo valor de n es %d\n", n); //Imprime el nuevo valor que hay en la variable n.

    return 0;
}

void cuboPorReferencia( int *ptrN ){
    *ptrN = *ptrN * *ptrN * *ptrN; //Se hace una multiplicación de si mismo 3 veces de lo que hay en el puntero.
}