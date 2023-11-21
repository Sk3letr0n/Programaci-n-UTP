// Punto 3 del Primer Parcial - Marzo 23/2023
// Realizado por Steven Grisales López - 1034289634

// Llamo como biblioteca a pilaarray.cpp debido a que si llamo a pilaarray.h en la misma carpeta suelta un error de doble definiciï¿½n de Pila.

#include <stdio.h>
#include "pilaarray.cpp"
#include <string.h>

int main() {
    Pila pila;
    char palindromo[TAMPILA];
    char palindromo_espacios[TAMPILA];
    crearPila(&pila); // Creamos una pila vacia 
    
    printf("Ingrese la palabra o frase la cual quiere saber si es un pal%cndromo o no: ", 161);
    gets(palindromo);

    int i;
    int j = 0;
	int len = strlen(palindromo);
	
	for (i = 0; i < len; i++)  {
		if(palindromo[i] != 32){
			palindromo_espacios[j] = palindromo[i];
			j++;
		}
	}
	
	int leng = strlen(palindromo_espacios);
    for (i = 0; i < leng; i++)  {
        if (!pilaLlena(pila)) {
            insertar(&pila, palindromo_espacios[i]);
        } else {
            printf("\n La pila est%c llena. \n", 160);
            break;
        }
    }

	for(i = 0; i < leng; i++){
        if (palindromo_espacios[i] == cima(pila)){
            quitar(&pila);
        } else {
            printf("La frase o palabra no es pal%cndromo.", 161);
            exit(1);
        }
    }
    printf("La frase o palabra si es un pal%cndromo.", 161);

    return 0;
} 
