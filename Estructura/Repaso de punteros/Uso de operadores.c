#include <stdio.h>
//El código si funciona 
int main() {
    int a;
    int *ptrA;
    
    a = 7;
    ptrA = &a;
    
    printf("La direccion de a es %p \nEl valor de ptrA es %p", &a, ptrA); //Nos muestra la dirección en Hexadecimal de a y ptrA que es la misma.
            
    printf("\n\nEl valor de a  %d \nEl valor de ptrA es %d", a, *ptrA); //Nos muestra el valor de la variable y el puntero que es el mismo.
            
    printf("\n\nMuestra de que * y & son complementos uno del otro \n&*ptrA = %p \n*&ptrA = %p\n", &*ptrA, *&ptrA); //Nos muestra la comprobación de que los punteros se complementan.

    return 0;
}
