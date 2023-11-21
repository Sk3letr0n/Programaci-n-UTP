// Ejercicio 70. Realizado por Steven Grisales López el 26/04/2023.

// Librerías.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

// Estructura para almacenar los datos de una asignatura.
typedef struct {
    unsigned long clave;
    char descr[50];
    double cred;
} asignatura;

// Prototipos de las funciones.
short mostrar_opciones(void);
void error(void);
short anyadir(char*);
short pantalla(char*);
short impresora(char*);

int main() {
    char nombre_archivo[80]; // Almacena el nombre del archivo.
    short opcion; // Almacena la opción seleccionada.
    short oK; // Almacena el resultado de la operación.

    printf("Nombre del archivo de asignaturas."); 
    gets(nombre_archivo); // Obtiene el nombre del archivo.
    do {
        opcion = mostrar_opciones(); // Muestra las opciones y obtiene la opción seleccionada.
        switch(opcion) { 
            case '1': oK = anyadir(nombre_archivo); // Añade una nueva asignatura.
                if(oK) error(); // Si hubo un error, muestra un mensaje y termina el programa.

            break;

            case '2': oK = pantalla(nombre_archivo); // Muestra el listado por pantalla.
                if(oK) error(); // Si hubo un error, muestra un mensaje y termina el programa
                system("pause"); // Pausa el programa.

            break;

            case '3': oK = impresora(nombre_archivo); // Imprime el listado en la impresora.
                if(oK) error(); // Si hubo un error, muestra un mensaje y termina el programa
                system("pause"); // Pausa el programa.

            break;

            case '4': exit(1); // Termina el programa.
        }
    } while(1); 
}

// Función que muestra las opciones y obtiene la opción seleccionada.
short mostrar_opciones(void) {  
    char opcion; // Almacena la opción seleccionada.
	system("cls"); // Limpia la pantalla.

    printf("\n\n\t\tOPCIONES Y TAREAS");
    printf("\n\n\t1. A%cadir nueva asignatura.", 164);
    printf("\n\t2. Mostrar listado por pantalla.");
    printf("\n\t3. Mostrar listado en archivo.");
    printf("\n\t4. Salir del programa.");
    printf("\n\n\t\t\tElegir opcion: ");
    
    do opcion = getchar(); while(opcion <'0'&&opcion >'4'); // Obtiene la opción seleccionada.

    return opcion; // Retorna la opción seleccionada.
}

// Función que muestra un mensaje de error y termina el programa.
void error(void) { 
    printf("Error en la operacion de acceso disco.\n");
    printf("Pulse una tecla para terminar ... \n");
    getchar(); // Pausa el programa y espera una tecla por parte del usuario.
    exit(1); // Termina el programa.
}

// Función que añade una nueva asignatura.
short anyadir(char archivo[]) { 
    FILE *ARCH; // Almacena el archivo.
    asignatura asig; // Almacena los datos de una asignatura.

    printf("\n\n\nDATOS DE LA NUEVA ASIGNATURA.\n\n");
    printf("Clave de la asignatura: ");
    scanf("%lu", &asig.clave);  

    printf("\nDescripcion: ");

    fflush(stdin); // Limpia el buffer del teclado.
    gets(asig.descr); // Obtiene la descripción de la asignatura.

    printf("\nCreditos: ");
    scanf("%lf", &asig.cred);

    ARCH = fopen(archivo,"ab"); // Abre el archivo en modo añadir binario.
    fwrite(&asig, sizeof(asig), 1, ARCH); // Escribe los datos de la asignatura en el archivo.

    printf("\n\n\tPulsar una tecla para continuar ... ");
    getchar(); // Pausa el programa y espera una tecla por parte del usuario.
    if(ferror(ARCH)) return 1; // Si hubo un error, retorna 1.
    
    fclose(ARCH); // Cierra el archivo.

    return 0;
}

// Función que muestra el listado por pantalla.
short pantalla(char archivo[]) { 
    FILE *ARCH; // Almacena el archivo.
    asignatura asig; // Almacena los datos de una asignatura.

    ARCH = fopen(archivo,"a+b"); // Abre el archivo en modo añadir binario.
    rewind(ARCH); // Posiciona el puntero al inicio del archivo.

    while(fread(&asig,sizeof(asig),1,ARCH) == 1) { // Mientras se pueda leer una asignatura del archivo.
        printf("\n\nClave ....... %lu", asig.clave); 
        printf("\nDescripcion ... %s", asig.descr);
        printf("\nCreditos ...... %6.1lf", asig.cred);
    }

    printf("\n\n\tPulsar una tecla para continuar.");
    getchar(); // Pausa el programa y espera una tecla por parte del usuario.
    if(ferror(ARCH)) return 1; // Si hubo un error, retorna 1.

    fclose(ARCH); // Cierra el archivo.
    
    return 0;
}

// Función que imprime el listado en la impresora.
short impresora(char archivo[]) { 
    FILE *ARCH1, *ARCH2; // Almacena los archivos.
    asignatura asig; // Almacena los datos de una asignatura.

    ARCH1 = fopen(archivo,"rb"); // Abre el archivo en modo lectura binaria.
    ARCH2 = fopen("impresora","w"); // Abre el archivo en modo escritura.

    while(fread(&asig,sizeof(asig),1,ARCH1) == 1) { // Mientras se pueda leer una asignatura del archivo.
        fprintf(ARCH2,"\n\nClave\t%lu", asig.clave); 
        fprintf(ARCH2,"\nDescripcion \t%s", asig.descr);
        fprintf(ARCH2,"\nCreditos\t%6.1lf", asig.cred);
    }

    printf("\n\n\tPulsar una tecla para continuar ... ");
    getchar(); // Pausa el programa y espera una tecla por parte del usuario.
    if(ferror(ARCH1)) return 1; // Si hubo un error, retorna 1.
 
    // Cierra los archivos.
    fclose(ARCH1); 
    fclose(ARCH2); 
   
    return 0;
}
