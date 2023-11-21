// Ejercicio 69 (a). Realizado por Steven Grisales López el 26/04/2023.

// Librerías.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	long letra[27] = {0}; // Arreglo que tiene la cantidad de letras del abecedario.
	long suma = 0; // Inicializa la variable en 0.
	FILE *archivo = fopen("quijote.txt", "r"); // Abre el archivo en modo lectura.
	
	if (archivo == NULL) { // Si el archivo no se pudo abrir.
	    printf("No se ha podido abrir el archivo.\n");
	    printf("Pulse una tecla para finalizar.");
	    getchar(); // Espera a que el usuario presione una tecla.
	    return 1; // Termina el programa.
	}
	
	int caracter; // Variable para almacenar el caracter leído.
	while ((caracter = fgetc(archivo)) != EOF) { // Mientras no se llegue al final del archivo.
	    if (isalpha(caracter)) { // Si el caracter es una letra.
	        int i = tolower(caracter) - 'a'; // Obtiene el índice de la letra.
	        letra[i]++; // Aumenta el contador de la letra.
	    } else { // Si el caracter no es una letra.
	        letra[26]++; // Aumenta el contador de otros caracteres.
	    }
	}
	
	fclose(archivo); // Cierra el archivo.
	
	for (int i = 0; i < 27; i++) { // Recorre el arreglo.
	    printf("[ %c ]= %10ld\t", (char)(i + 'A'), letra[i]); // Imprime el contador de la letra.
	    printf("%7.2lf\n", ((float)letra[i] / suma) * 100); // Imprime el porcentaje de la letra.
	    suma += letra[i]; // Suma el contador de la letra al total.
	}
	
	printf("\n\nTotal letras: %ld", suma);  // Imprime el total de letras.
	
	return 0;
}
