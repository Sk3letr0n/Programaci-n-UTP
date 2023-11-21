#include <stdio.h>
//El código si funciona
int cuboPorValor( int );

int main() {
    int n = 5;
    
    printf("El valor original del numero es %d", n); //Imprime el valor que hay en la variable n.

    n = cuboPorValor( n ); //Le asignamos a la variable n lo que nos devuelva la función a la que le mandamos el valor de dicha variable.

    printf("\nEl nuevo valor de numero es %d\n", n); //Imprime el nuevo valor que hay en la variable n.

    return 0;
}

int cuboPorValor( int n ){
    return n * n * n; //Se retorna el valor a main que se obtiene multiplicando el dato que hay en la variable 3 veces. 
}