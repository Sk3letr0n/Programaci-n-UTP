/* 
Hecho por: Steven Grisales López
Fecha: 14/04/2023.
Versión: 1.4
Descripción: Este programa nos genera un menú que tiene unas funciones que nos ayudan a trabajar con Listas simplemente enlazadas(Insertar al inicio, al final, ordenado y borrar elemento)
Se va a ir documentando según vamos haciendo el código (solo las partes complicadas y variables)
*/

#define MX 50 // Constante que nos ayuda a generar números aleatorios.
const char bo1 = 201, bo2 = 200, bo3 = 187, bo4 = 188, vert = 186, hori = 205, esq1 = 204, esq2 = 185; // Constantes que nos ayudan a dibujar el menú.
typedef int Item; // Item que vamos a usar durante todo el programa.

// Estructura de la lista.
typedef struct Elemento {
	Item dato; // Dato que va a guardar la lista.
	struct Elemento* siguiente; // Puntero que apunta al siguiente elemento de la lista.
} Nodo;

// Prototipos de funciones.
void insert_end (Nodo** cabeza, int entrada);
void insert_begin(Nodo** cabeza, Item entrada);
Nodo* crearNodo(Item x);
void recorrer (Nodo* cabeza);
void insert_order(Nodo** cabeza, Item entrada);
void erase_element(Nodo** cabeza, Item entrada);
void clean_list(Nodo** cabeza);

// Bibliotecas usadas.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Aclaración: Se trabaja con distintas listas en cada opción del menu para comodidad del programador(Yo). */
int main(){
    int op = 0; // Opción del switch.
    int salir = 0; // Variable para salir del programa.
    char validacion = 0; // Verificación para borrar un elemento.
    char validacion2 = 0; // Verificación para volver a main.
    Item d; // Dato que se va a insertar en la lista.
	Nodo* cabeza; // Puntero que apunta al inicio de la lista.
	cabeza = NULL; // Inicializamos el puntero a NULL.
	srand(time(NULL)); // Inicializamos la semilla para generar números aleatorios.

    // Menu principal de Listas Simplemente Enlazadas. Los %c son las constantes mencionadas en la linea 6.
    printf("\n");
    printf("\tLISTAS SIMPLEMENTE ENLAZADAS\n");
    printf("%c============================================%c\n", bo1, bo3);
    printf("%c              MEN%c PRINCIPAL                %c\n", vert, 233, vert);
    printf("%c============================================%c\n", esq1, esq2);
    printf("%c 1. Insertar n%cmeros aleatorios al inicio.  %c\n", vert, 163, vert);
    printf("%c 2. Insertar n%cmeros al final.              %c\n", vert, 163, vert);
    printf("%c 3. Insertar ordenado.                      %c\n", vert, vert);
    printf("%c 4. Borrar un elemento                      %c\n", vert, vert);
    printf("%c 5. Salir                                   %c\n", vert, vert);
    printf("%c============================================%c\n", bo2, bo4);
    
    // Este while permite que el programa no se cierre hasta que el usuario lo desee o si digita una opción invalida regrese al menu principal.
    while(!salir) {
        printf("\nSelecciona una opci%cn: ", 162);
        scanf("%i", &op);

        switch(op){
        case 1:
            printf("N%cmeros generados:\n", 163);
            // Este bucle genera números aleatorios y los guarda en la variable d, termina de generar números cuando se genera un 0 aleatoriamente.
            for (; (d = rand() % MX) != 0;) {
                printf("%d ", d); // Imprimimos los números generados para visualizar primero cuantos generó para luego meterlos a la lista.
                insert_begin(&cabeza, d); // Llamamos a la función insert_begin para insertar los números al inicio de la lista.
            }
            recorrer(cabeza); // Llamamos a la función recorrer para recorrer mediante la cabeza la lista y así imprimir la lista.

            printf("Desea volver al menu principal? (s/n): ");
            scanf(" %c", &validacion2);
            // Validamos que la opción sea s o S para volver al menu principal.
            if (validacion2 == 's' || validacion2 == 'S') {
                printf("Regresando al men%c principal...\n\n", 163);
                main();
            } else { // Si no es s o S, se sale del programa, por lo tanto, cuidado al digitar una letra o número diferentes a s ó n.
                printf("Saliendo del programa...\n\n");
                free(cabeza); // Liberamos la memoria.
                exit(0); // Salimos del programa.
            }
            break;
        case 2:
            printf("N%cmeros generados:\n", 163);
            // Este bucle genera números aleatorios y los guarda en la variable d, termina de generar números cuando se genera un 0 aleatoriamente.
            for (; (d = rand() % MX) != 0;) {
                printf("%d ", d); // Imprimimos los números generados para visualizar primero cuantos generó para luego meterlos a la lista.
                insert_end(&cabeza, d); // Llamamos a la función insert_end para insertar los números al final de la lista.
            }
            recorrer(cabeza); // Llamamos a la función recorrer para recorrer mediante la cabeza la lista y así imprimir la lista.

            printf("Desea volver al menu principal? (s/n): ");
            scanf(" %c", &validacion2);
            // Validamos que la opción sea s o S para volver al menu principal.
            if (validacion2 == 's' || validacion2 == 'S') {
                printf("Regresando al men%c principal...\n\n", 163);
                main();
            } else { // Si no es s o S, se sale del programa, por lo tanto, cuidado al digitar una letra o número diferentes a s ó n.
                printf("Saliendo del programa...\n\n");
                free(cabeza); // Liberamos la memoria.
                exit(0); // Salimos del programa.
            }
            break;
        case 3:
            cabeza = NULL; // Reiniciamos la cabeza a NULL.
            printf("N%cmeros generados:\n", 163);
            // Este bucle genera números aleatorios y los guarda en la variable d, termina de generar números cuando se genera un 0 aleatoriamente.
            for (; (d = rand() % MX) != 0;) {
                printf("%d ", d); // Imprimimos los números generados para visualizar primero cuantos generó para luego meterlos a la lista.
                insert_order(&cabeza, d); // Llamamos a la función insert_order para insertar los números ordenados de menor a mayor.
            }
            recorrer(cabeza); // Llamamos a la función recorrer para recorrer mediante la cabeza la lista y así imprimir la lista.

            printf("Desea volver al menu principal? (s/n): ");
            scanf(" %c", &validacion2);
            // Validamos que la opción sea s o S para volver al menu principal.
            if (validacion2 == 's' || validacion2 == 'S') {
                printf("Regresando al men%c principal...\n\n", 163);
                main();
            } else { // Si no es s o S, se sale del programa, por lo tanto, cuidado al digitar una letra o número diferentes a s ó n.
                printf("Saliendo del programa...\n\n");
                free(cabeza); // Liberamos la memoria.
                exit(0); // Salimos del programa.
            }
            break;
        case 4:
            // Este bucle genera números aleatorios y los guarda en la variable d, termina de generar números cuando se genera un 0 aleatoriamente.
            for (d = rand()%MX; d;){
                insert_begin(&cabeza,d); // Llamamos a la función insert_begin para insertar los números al inicio de la lista(podiamos generar una lista con cualquiera de las otras 2 funciones).
                d = rand()%MX; // Generamos un nuevo número aleatorio.
            }
            recorrer(cabeza); // Llamamos a la función recorrer para recorrer mediante la cabeza la lista y así imprimir la lista.
            if(cabeza == NULL){ // Validamos que la lista no esté vacía.
                printf("La lista est%c vac%ca.\n", 160, 161);
            } else {
                printf("Ingrese el elemento a borrar: ");
                scanf("%d", &d);
                erase_element(&cabeza, d); // Llamamos a la función erase_element para borrar el elemento que el usuario digite.
                recorrer(cabeza); // Llamamos a la función recorrer para recorrer mediante la cabeza la lista y así imprimir la nueva lista.

                printf("Desea borrar otro elemento? (s/n): ");
                scanf("%s", &validacion);
                // Validamos que la opción sea s o S para volver a borrar otro elemento.
                while (validacion == 's' || validacion == 'S') {
                    printf("Ingrese el elemento a borrar: ");
                    scanf("%d", &d);
                    erase_element(&cabeza, d); // Llamamos a la función erase_element para borrar el nuevo elemento que el usuario digite.
                    recorrer(cabeza); // Llamamos a la función recorrer para recorrer mediante la cabeza la lista y así imprimir la nueva lista.
                    
                    printf("\nDesea eliminar otro elemento? (s/n): ");
                    scanf(" %c", &validacion);
                    
                    // Validamos la opción y si es distinta de s, S, n y N le pediremos al usuario que ingrese una opción correcta para volver a borrar otro elemento o no hacerlo.
                    while (validacion != 's' && validacion != 'S' && validacion != 'n' && validacion != 'N') {
                        printf("Ingrese una opcion valida (s/n): ");
                        scanf(" %c", &validacion);
                    }
                }
            }

            printf("Desea volver al menu principal? (s/n): ");
            scanf(" %c", &validacion2);

            // Validamos que la opción sea s o S para volver al menu principal.
            if (validacion2 == 's' || validacion2 == 'S') {
                printf("Regresando al men%c principal...\n\n", 163);
                main();
            } else { // Si no es s o S, se sale del programa, por lo tanto, cuidado al digitar una letra o número diferentes a s ó n.
                printf("Saliendo del programa...\n\n");
                free(cabeza); // Liberamos la memoria.
                exit(0); // Salimos del programa.
            }
            clean_list(&cabeza); // Llamamos a la función clean_list para borrar la lista para no generar conflictos con otras opciones.
            break;
        case 5:
            printf("Saliendo del programa...\n\n");
            free(cabeza); // Liberamos la memoria.
            exit(0); // Salimos del programa.
            break;
        default:
            printf("La opci%cn es inv%clida.\n\n", 162, 160);
            printf("Regresando al men%c principal...\n\n", 163);
            main(); // Volvemos a la función main para que el usuario pueda elegir una opción correcta.
            break;
        }
    }
}

// Función para crear un nuevo nodo.
Nodo* crearNodo(Item x){
    Nodo *a; // Puntero al nuevo nodo.
    a = (Nodo*) malloc(sizeof(Nodo)); // Reserva memoria para el nuevo nodo.
    a -> dato = x; // Asigna el dato al nodo.
    a -> siguiente = NULL; // Inicializa el puntero al siguiente nodo en NULL.
    return a; 
}

// Función para insertar un nodo al inicio de la lista.
void insert_begin(Nodo** cabeza, Item entrada){
    Nodo *nuevo; // Puntero al nuevo nodo.
    nuevo = crearNodo(entrada); // Crea un nuevo nodo.
    nuevo -> siguiente = *cabeza; // Inserta el nuevo nodo al inicio de la lista.
    *cabeza = nuevo; // Actualiza la cabeza de la lista.
}

// Función para insertar un nodo al final de la lista.
void insert_end(Nodo** cabeza, int entrada){
	Nodo *ultimo; // Puntero al último nodo de la lista.
	ultimo = *cabeza; // Inicializa el puntero al primer nodo de la lista.
	if (ultimo == NULL) { // Lista vacia.
		*cabeza = crearNodo (entrada); // Crea el primer nodo de la lista.
	} else {
		for(;ultimo -> siguiente; ){ // Termina con ultimo referenciando al nodo final.
			ultimo = ultimo -> siguiente; // Avanza al siguiente nodo.
        }
        ultimo -> siguiente = crearNodo (entrada); // Crea el nuevo nodo al final de la lista.
	}
}

// Función para insertar un nodo en orden ascendente.
void insert_order(Nodo **cabeza, Item entrada) {
    Nodo *nuevo = crearNodo(entrada); // Crea el nuevo nodo.
    if (*cabeza == NULL || entrada < (*cabeza) -> dato) { // Si la lista está vacía o el dato es menor que el primer nodo, se inserta al inicio de la lista.
        // Inserta al inicio de la lista.
        nuevo -> siguiente = *cabeza;
        *cabeza = nuevo; 
    } else {
        // Busca el nodo anterior al punto de inserción.
        Nodo *anterior = *cabeza; // Se inicia con el primer nodo.
        while (anterior -> siguiente != NULL && anterior -> siguiente -> dato < entrada) { // Mientras no se llegue al final de la lista y el nodo siguiente sea menor que el que se quiere insertar, se sigue buscando.
            anterior = anterior -> siguiente; // Se avanza en la lista.
        }
        // Inserta el nuevo nodo en el lugar adecuado.
        nuevo -> siguiente = anterior -> siguiente;
        anterior -> siguiente = nuevo; 
    }
}

// Función para borrar un nodo de la lista.
void erase_element (Nodo** cabeza, Item entrada){
    Nodo* actual, *anterior; // Declaración de punteros.
    int encontrado = 0; // Variable para saber si se encontró el nodo.
    actual = *cabeza; anterior = NULL; // Asignación de punteros.
    // Búsqueda del nodo y del anterior.
    while((actual!=NULL) && (!encontrado)){ // Mientras no se llegue al final de la lista y no se encuentre el nodo, se sigue buscando.
        encontrado = (actual -> dato == entrada); // Si el nodo actual es el que se busca, encontrado = 1.
        if (!encontrado){ // Si no se encuentra el nodo, se avanza en la lista.
            anterior = actual; // El nodo actual se convierte en el nodo anterior.
            actual = actual -> siguiente; // Avanza al siguiente nodo.
        }
    }
    // Enlace de nodo anterior con siguiente.
    if (actual != NULL) {
    // Distingue entre que el nodo sea el cabecera o del resto de la lista.
        if (actual == *cabeza){
            *cabeza = actual -> siguiente; // El nodo siguiente del nodo actual se convierte en la cabeza de la lista.
        } else { 
            anterior -> siguiente = actual -> siguiente; // El nodo siguiente del nodo actual se convierte en el nodo siguiente del nodo anterior.
            free(actual); // Liberamos la memoria.
        }
    }
}

// Función para recorrer e imprimir la lista.
void recorrer (Nodo* cabeza){
	int k; // Variable para el salto de línea.	
    printf ("\n\t\t Lista \n"); // Imprime el título de la lista.
	for (k = 0; cabeza; cabeza = cabeza -> siguiente){ // Recorre la lista.
		printf ("%d ",cabeza -> dato); // Imprime el dato del nodo actual.
		k++;
		printf ("%c",(k % 15 ?' ':'\n') ); // Si k es múltiplo de 15, imprime un salto de línea, de lo contrario, imprime un espacio.
	}
	printf ("\n\n");
}

// Función para limpiar la lista.
void clean_list(Nodo** cabeza) {
    Nodo* actual = *cabeza; // Nodo actual le asignamos el puntero de la cabeza de la lista.
    Nodo* siguiente = NULL; // Nodo siguiente lo inicializamos en NULL.

    while (actual != NULL) { 
        siguiente = actual -> siguiente; // Nodo siguiente le asignamos el puntero del nodo actual.
        free(actual); // Liberamos la memoria.
        actual = siguiente; // Nodo actual le asignamos el puntero del nodo siguiente.
    }
    *cabeza = NULL; // La cabeza de la lista le asignamos en NULL.
}