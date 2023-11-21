// Ejercicio 69 (b). Realizado por Steven Grisales López el 26/04/2023.

// Librerías.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	long letra[27]; // Arreglo que tiene la cantidad de letras del abecedario.
	short caracter; // Variable para almacenar el caracter leído.
	long suma = 0; // Inicializa la variable en 0.
	short int i; // Variable para el ciclo for.
	FILE *archivo;  // Abre el archivo en modo lectura.
	
	for(i = 0 ; i < 27 ; i++) letra[i] = 0; // Inicializa el arreglo en 0.
	
	archivo = fopen("quijote.txt", "r"); // Abre el archivo en modo lectura.
	
	if(archivo == NULL) { // Si el archivo no se pudo abrir.
		printf("No se ha podido abrir el archivo.\n");
		printf("Pulse una tecla para finalizar.");
		getchar(); // Espera a que el usuario presione una tecla.
		exit(1); // Termina el programa.
	}
	
	while((caracter = fgetc(archivo)) != EOF) { // Mientras no se llegue al final del archivo.
		if(caracter == 209 || caracter == 241) 
		letra[27]++; // letras ñ y Ñ
		
		else if(caracter == 225 || caracter == 193)
		letra['a' - 'a']++; // letras á y Á
		
		else if(caracter == 233 || caracter == 201)
		letra['e' - 'a']++; // letras é y É
		
		else if(caracter == 237 || caracter == 205)
		letra['i' - 'a']++; // letras í e Í
		
		else if(caracter == 243 || caracter == 211)
		letra['o' - 'a']++; // letras ó y Ó
		
		else if(caracter == 250 || caracter == 218)
		letra['u' - 'a']++; // letras ú y Ú
		
		else if(caracter == 252 || caracter == 220)
		letra['u' - 'a']++; // letras ü y Ü
		
		else if(isalpha(caracter)) { // Si el caracter es una letra.
			i = (short)tolower(caracter) - (short)'a'; // Obtiene el índice de la letra.
			if(i >= 0 && i < 27) letra[i]++; // Aumenta el contador de la letra.
		}
	}
	
	fclose(archivo); // Cierra el archivo.
	
	for(i = 0 ; i < 27 ; i++) suma += letra[i]; // Suma el contador de la letra al total.
	
	for(i = 0 ; i < 27 ; i++) { // Recorre el arreglo.
		printf("[ %c ]= %10ld\t", (char)(i + 'A'), letra[i]); // Imprime el contador de la letra.
		printf("%7.2lf\n",((float)letra[i] / suma) * 100); // Imprime el porcentaje de la letra.
	}
	 
	printf("[ %c ] = %10ld\t", 165,letra[27]); // Imprime el contador de la letra.
	printf("%7.2lf\n", ((float)letra[27] / suma) * 100); // Imprime el porcentaje de la letra.
	printf("\n\nTotal letras: %ld", suma); // Imprime el total de letras.
	
	return 0;
}
