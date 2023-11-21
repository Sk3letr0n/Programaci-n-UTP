// Ejercicio 69 modificado. Realizado por Steven Grisales López el 26/04/2023.

// Librerías.
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *archivo_entrada, *archivo_salida; // Declaración de variables.
    char nombre_archivo_entrada[100], nombre_archivo_salida[100], c; // Declaración de variables.

    // Pedir el nombre del archivo de entrada
    printf("Ingrese el nombre del archivo de entrada: ");
    scanf("%s", nombre_archivo_entrada);

    // Abrir el archivo de entrada
    archivo_entrada = fopen(nombre_archivo_entrada, "r");
    if (archivo_entrada == NULL) { // Si el archivo no se puede abrir, se muestra un mensaje de error.
        printf("No se pudo abrir el archivo de entrada.\n");
        return 1; // Se retorna 1 para indicar que hubo un error.
    }

    // Pedir el nombre del archivo de salida
    printf("Ingrese el nombre del archivo de salida: ");
    scanf("%s", nombre_archivo_salida);

    // Abrir el archivo de salida
    archivo_salida = fopen(nombre_archivo_salida, "w"); // Se abre el archivo en modo escritura.
    if (archivo_salida == NULL) { // Si el archivo no se puede abrir, se muestra un mensaje de error.
        printf("No se pudo abrir el archivo de salida.\n");
        return 1; // Se retorna 1 para indicar que hubo un error.
    }

    // Leer el archivo de entrada caracter por caracter
    while ((c = fgetc(archivo_entrada)) != EOF) { // Se lee el archivo de entrada caracter por caracter.
        // Convertir el caracter a mayuscula o minuscula segun corresponda
        if (isupper(c)) { // Si el caracter es mayúscula.
            c = tolower(c); // Se convierte a minúscula.
        } else if (islower(c)) { // Si el caracter es minúscula.
            c = toupper(c); // Se convierte a mayúscula.
        }

        // Mostrar o escribir el caracter modificado
        putchar(c); // Se muestra el caracter modificado.
        fputc(c, archivo_salida); // Se escribe el caracter modificado en el archivo de salida.
    }

    // Cerrar los archivos
    fclose(archivo_entrada); 
    fclose(archivo_salida);

    return 0;
}