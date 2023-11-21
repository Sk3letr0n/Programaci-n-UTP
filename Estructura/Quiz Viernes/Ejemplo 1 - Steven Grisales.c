// Código (apuntador a carácter) - Revisado por Steven Grisales López
/* Toco hacerle unos ajustes, en la linea 16 cambie %d por %i 
y en la 18 %d por %p para que no suelte errores de impresión*/  

#include <stdio.h>

/* Este programa crea un apuntador de tipo carácter */

int main(){
    char *ap, c;
    c = 'x';
    ap = &c;

    // imprime el carácter de la localidad a la que apunta
    printf("Caracter: %c\n", *ap);
    // imprime el código ASCII de la localidad a la que apunta
    printf("Codigo ASCII: %i\n", *ap);
    // imprime la dirección de memoria de la localidad a la que apunta
    printf("Direccion de memoria: %p\n", ap);

    return 0;
}