// Librerias.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/************************************************************************\
* Programa: FARMACIA (PUNTEROS)                                          *
* Autores: Steven Grisales Lopez
\************************************************************************/

// Vamos a introducir medicamentos con la estructura Bloque y trabajaremos desde block
struct Bloque {
    char Laboratorio[30]; // Nombre del laboratorio
    char Nombre[25]; // Nombre del medicamento
    int Cantidad; // Cantidad de medicamentos disponibles
    float Precio_Venta; // Precio de venta
    char Cobertura[2]; // Si se necesita receta o no
};

struct Bloque block; // Creamos un bloque llamado block

// Trabajamos con la estructura nodo a la cual apuntamos con punteros e introducimos
// Distintos datos tipo Bloque en la parte datos y enlacaremos otro nodo en la parte sig
struct Nodo {
    struct Bloque datos; // Datos del medicamento
    struct Nodo * sig; // Puntero al siguiente nodo
};

// Creamos el inicio de la lista que es un puntero vacio (puntero maestro)
// Tambien creamos los punteros aux y atras que utilizaremos para distintas funciones
struct Nodo * inicio; 
struct Nodo * aux, * atras ;

/* CREAR MEDICAMENTO */
int crear(void){
    // Creamos un medicamento en block
    printf("Introduzca el nombre del medicamento: "); 
	scanf("%s", block.Nombre);
    printf("Introduzca el nombre del laboratorio: "); 
	scanf("%s" , block.Laboratorio);
    printf("Se puede solicitar receta? (escribe 'si' o 'no'): "); 
	scanf("%s", block.Cobertura);
    printf("Introduzca la cantidad de medicamentos disponibles: "); 
	scanf ("%d", &block.Cantidad);
    printf("Introduzca el precio de venta: "); 
	scanf ("%f", &block.Precio_Venta);

    // Se introducen los datos de block en la parte datos del nodo
    aux -> datos = block;
    // Reservamos un nuevo espacio de memoria
    aux -> sig = (Nodo*)malloc( sizeof(struct Nodo));
    // Nuestro puntero auxiliar apunta a este nuevo espacio.
    aux = aux -> sig;
    aux -> sig = NULL;

    printf("\n");printf("       *Medicamento Creado*");printf("\n \n");
    system("PAUSE");

    return 0;
    }

// Crear Medicamento en el archivo
int crear_archivo(){
    FILE *archivomedicamento; // Creamos un puntero a archivo

    archivomedicamento = fopen("DatosFarmacia.dat", "a"); // Abrimos el archivo en modo escritura

    printf("Introduzca el nombre del medicamento: "); 
	scanf("%s", block.Nombre);
    printf("Introduzca el nombre del laboratorio: "); 
	scanf("%s" , block.Laboratorio);
    printf("Se puede solicitar receta? (escribe 'si' o 'no'): "); 
	scanf("%s", block.Cobertura);
    printf("Introduzca la cantidad de medicamentos disponibles: "); 
	scanf ("%d", &block.Cantidad);
    printf("Introduzca el precio de venta: "); 
	scanf ("%f", &block.Precio_Venta);
    
    fwrite(&block, sizeof(Bloque), 1, archivomedicamento); // Escribimos en el archivo	 
    fclose(archivomedicamento);
    
    return 0;
}    

/* ELIMINAR */
int eliminar(void){
	int encontrado; // Variable para saber si se ha encontrado el medicamento
	char compara[25]; // Variable para comparar el medicamento que queremos eliminar con los que hay en la lista

	/* La estructura basica de eliminar trata que mediante el puntero atras (que apunta al anterior que aux)
	vamos a enlazar el nodo al que apunta atras con el siguiente al que apunta aux de forma que se ignorara
	el nodo al que esta apuntando actualmente aux puesto que no lo tenemos enlazado de ninguna forma y
	acto seguido borrraremos todos los datos que se encuentran en el. */

    encontrado = 0; // Variable para saber si se ha encontrado el medicamento
    printf("\n");
	printf(" Que medicamento quieres eliminar?: "); scanf("%s",compara);

	for (atras = NULL, aux = inicio; aux != NULL; atras = aux, aux = aux -> sig) { // Recorremos la lista
	    if (strcmp (compara , aux -> datos.Nombre) == 0 ) { // Comparamos el medicamento que queremos eliminar con los que hay en la lista
	        if (atras == NULL) { // Si el medicamento a eliminar es el primero de la lista
		        inicio = aux -> sig; // El inicio de la lista pasa a ser el siguiente al que apunta aux
		        free(aux); // Liberamos el espacio de memoria que ocupa aux
	        } else { // Si el medicamento a eliminar no es el primero de la lista
		        atras -> sig = aux -> sig; // Enlazamos el nodo anterior al que apunta aux con el siguiente al que apunta aux
		        free(aux); // Liberamos el espacio de memoria que ocupa aux
		        aux = atras -> sig; // Aux pasa a apuntar al siguiente al que apuntaba antes
	        }
	        printf("\n"); printf("        El medicamento ha sido eliminado correctamente"); printf("\n");
	        encontrado = 1;
//      	Return inicio;
	    }

	}

    if (encontrado == 0) { // Si no se ha encontrado el medicamento
        printf("\n"); printf("*No existe ese medicamento*" ); printf("\n");
    }
    printf("\n \n");
    system("PAUSE");
    
    return 0;
}

//Eliminar del archivo
int eliminar_archivo() {
    FILE *fp; // Creamos un puntero a archivo
    int  cont = 0; // Variable para contar los medicamentos
    char eli[25]; // Variable para comparar el medicamento que queremos eliminar con los que hay en el archivo
    printf("\nQue medicamento quieres eliminar?: "); 
    scanf("%s", eli);
    fp = fopen("DatosFarmacia.dat", "rb");

    // Cantidad de medicamentos
    while(fread(&block, sizeof(Bloque), 1, fp)) { 
        cont++;
    }
    Bloque vectorAux[cont]; // Creamos un vector auxiliar para guardar los medicamentos que no queremos eliminar

    rewind(fp); // Ponemos el puntero al principio del archivo

    // Rellenar la lista con los medicamentos del archivo
    int cont2 = 0;
    while(fread(&block,sizeof(Bloque), 1, fp)){ // Leemos el archivo
        if(strcmp(block.Nombre, eli) != 0){ // Si el medicamento que queremos eliminar no es igual al que estamos leyendo
	        vectorAux[cont2] = block; // Guardamos el medicamento en el vector auxiliar
	        cont2++; // Aumentamos el contador
        }
    }

    fp = fopen("DatosFarmacia.dat","wt");
    
    int cont3; // Variable para recorrer el vector auxiliar
    for (cont3 = 0; cont3 < cont-1 ; cont3++){ // Recorremos el vector auxiliar
        fwrite(&vectorAux[cont3], sizeof(Bloque), 1, fp); // Escribimos en el archivo	 
    }

    fclose(fp);
    printf("\nMedicamento eliminado...");
    system("pause");
    
    return 0;
}

/* MOSTRAR TODOS */
int mostrar_todos(void) {
	// Motramos todos los medicamentos haciendo que el puntero aux avance por toda la lista.
    printf("\n");
    aux = inicio; // Aux apunta al inicio de la lista

	while (aux -> sig != NULL) {
        printf("Nombre: %s \n", aux -> datos.Nombre); 
        printf("Laboratorio: %s \n", aux -> datos.Laboratorio); 
        printf("Receta: %s \n", aux -> datos.Cobertura); 
        printf("Cantidad: %d \n", aux -> datos.Cantidad); 
        printf("Precio: %f \n", aux -> datos.Precio_Venta); 
        printf("\n \n");
        aux = aux -> sig; // Aux avanza por la lista
	}
	// Para hacer una pausa en el programa
    system("PAUSE");
    
    return 0;
}


/* CONSULTAR */
int consultar(void) {
    int encontrado; // Variable para saber si se ha encontrado el medicamento
    char compara [25]; // Variable para comparar el medicamento que queremos consultar con los que hay en la lista
    encontrado = 0; // Variable para saber si se ha encontrado el medicamento

    printf("\n");
    printf(" Que medicamento quieres consultar?: "); 
    scanf("%s", compara);

    aux = inicio; // Aux apunta al inicio de la lista
    while (aux -> sig != NULL) {
        // Mediante un comparador de strings se encontrara el medicamento adecuado por su nombre.
       if (strcmp (compara , aux -> datos.Nombre) == 0) {
            printf("Nombre: %s ", aux -> datos.Nombre); printf("\n");
            printf("Laboratorio: %s ", aux -> datos.Laboratorio); printf("\n");
            printf("Receta: %s ", aux -> datos.Cobertura); printf("\n");
            printf("Cantidad: %d ", aux -> datos.Cantidad); printf("\n");
            printf("Precio: %f ", aux -> datos.Precio_Venta); printf("\n");
            // Si encuentra el medicamento lo anotamos en la variable encontrado
            encontrado = 1;
        }
        aux = aux -> sig; // Aux avanza por la lista
    }

    // Si no encuentra el medicamento
    if (encontrado == 0) { 
        printf("\n"); printf("*No existe ese medicamento*" ); printf("\n");
    }
    printf("\n \n");
    system("PAUSE");
    
    return 0;
}

// Consultar en el archivo
int consultar_archivo(){
	int encontrado; // Variable para saber si se ha encontrado el medicamento
	FILE *fp; // Creamos un puntero a archivo
    encontrado = 0; // Variable para saber si se ha encontrado el medicamento
    char comp [25]; // Variable para comparar el medicamento que queremos consultar con los que hay en el archivo
    
    printf(" Que medicamento quieres consultar?: "); 
	scanf("%s",comp);

    fp = fopen("DatosFarmacia.dat", "rb");

    while(fread(&block,sizeof(Bloque), 1, fp)) { // Leemos el archivo
        if(strcmp(comp,block.Nombre) == 0){    
        	printf("\nMedicamento encontrado:\n");
            printf("Nombre: %s ", block.Nombre); printf("\n");
            printf("Laboratorio: %s ", block.Laboratorio); printf("\n");
            printf("Receta: %s ", block.Cobertura); printf("\n");
            printf("Cantidad: %d ", block.Cantidad); printf("\n");
            printf("Precio: %f ", block.Precio_Venta); printf("\n\n");
        	encontrado = 1; 
            }
        }
    if (encontrado == 0) { 
        printf("\nMedicamento no encontrado...\n");
    }
    system("pause");
    fclose(fp);
    return 0;
}

/* MODIFICAR */
int modificar(void){
	int encontrado; 
	int r;
	int opcion1;
	char compara [25];
    r = 1;
    
    printf("\n Que medicamento quieres modificar?: "); 
	scanf("%s", compara); 
	printf("\n");
    
    encontrado = 0;
    aux = inicio;
    while (aux -> sig != NULL) {
        if (strcmp (compara, aux -> datos.Nombre) == 0 ) {
            // R utilizada para volver a modificar dato
            while (r == 1) {
	            printf("    Nombre: %s \n", aux -> datos.Nombre); 
	            printf("    Laboratorio: %s \n", aux -> datos.Laboratorio); 
	            printf("    Receta: %s \n", aux -> datos.Cobertura); 
	            printf("    Cantidad: %d \n", aux -> datos.Cantidad); 
	            printf("    Precio: %f \n\n", aux -> datos.Precio_Venta); 
	
	            printf("            *MENU Modificar* \n \n");
	            printf("       1) Cambiar nombre                                \n");
	            printf("       2) Cambiar Laboratorio                           \n");
	            printf("       3) Cambiar opcion receta                         \n");
	            printf("       4) Cambiar cantidad de medicamentos disponibles  \n");
	            printf("       5) Cambiar precio                                \n \n");
	            printf("       6) Salir del menu                                \n \n \n ");
	            printf("            *Fin Menu Modificar* \n \n  ");
	            printf("Que desea hacer: ");
	            scanf("%d", &opcion1);
	            
	            switch (opcion1) {
	            case 1:
	//              Cambiar nombre
	                printf("Introduzca el nombre del medicamento: "); 
					scanf("%s", aux -> datos.Nombre);
	                break;
	            case 2:
	//              Cambiar laboratorio
	                printf("Introduzca el nombre del laboratorio: "); 
					scanf("%s" , aux -> datos.Laboratorio);
	                break;
	            case 3:
	//              Cambiar opcion de receta
	                printf("Se puede solicitar receta? (escribe 'si' o 'no'): "); 
					scanf("%s", aux -> datos.Cobertura);
	                break;
	            case 4:
	//              Cambiar cantidad de medicamentos disponibles
	                printf("Introduzca la cantidad de medicamentos disponibles: "); 
					scanf ("%d", &aux -> datos.Cantidad);
	                break;
	            case 5:
	//              Cambiar precio de venta
	                printf("Introduzca el precio de venta: "); 
					scanf ("%f", &aux -> datos.Precio_Venta);
	                break;
	            case 6:
	//              Salir del menu
					printf("\n  **Saliendo del menu.**\n"); 
	                break;
	            default:
					printf("\n   Opcion no valida.\n"); 
	                break;
	            }
            
            printf("\n");
            printf("    Nombre: %s ", aux -> datos.Nombre); printf("\n");
            printf("    Laboratorio: %s ", aux -> datos.Laboratorio); printf("\n");
            printf("    Receta: %s ", aux -> datos.Cobertura); printf("\n");
            printf("    Cantidad: %d ", aux -> datos.Cantidad); printf("\n");
            printf("    Precio: %f ", aux -> datos.Precio_Venta); printf("\n \n");

            printf("Quieres modificar algun dato mas de este medicamento?(si = 1, no = 0) :  ");
            scanf("%d", &r);
                // Sale del while
        	}
            // Si encuentra el medicamento lo anotamos en la variable encontrado
            encontrado = 1;
        }
        aux = aux -> sig;
    }
    // Si no encuentra el medicamento
    if (encontrado == 0) {

		printf("\n*No existe ese medicamento*\n" ); 
    }
    printf("\n \n");
    system("PAUSE");
    
    return 1;
}


int modificar_archivo(){
    FILE *fp; // Creamos un puntero a archivo
    int  cont = 0, cont2; // Contadores
    char cambio[25]; // Variable para comparar el medicamento que queremos modificar con los que hay en el archivo
    int option; // Opcion que queremos modificar

    fp = fopen("DatosFarmacia.dat", "rb");
    
    printf("\nQue medicamento quieres eliminar?: "); 
    scanf("%s", cambio);

    printf("\nIngrese la opción que desea modificar:");
    printf("\n1.nombre del medicamento");
    printf("\n2.nombre del laboratorio");
    printf("\n3.solitud de receta");
    printf("\n4.cantidad del medicamento");
    printf("\n5.precio del medicamento");
    printf("\nQue desea hacer:");
    
    fflush(stdin); // Limpiamos el buffer
    scanf("%i", &option);

    // Cantidad de medicamentos
    while(fread(&block, sizeof(Bloque), 1, fp)) { 
        cont++;
    }
    Bloque vectorAux[cont];

    for (cont2 = 0; cont2 < cont-1 ; cont2++) {
       if(vectorAux[cont2].Nombre == cambio && option == 1) {
            printf("\nIngrese el nuevo nombre del medicamento:");
            fflush(stdin);
            scanf("%s", vectorAux[cont2].Nombre);
       }
       else if(vectorAux[cont2].Nombre == cambio && option == 2) {
            printf("\nIngrese el nuevo nombre del laboratorio:");
            fflush(stdin);
            scanf("%s", vectorAux[cont2].Laboratorio);
       }
       else if(vectorAux[cont2].Nombre == cambio && option == 3) {
            printf("\nSe puede solicitar receta? (escribe 'si' o 'no'): ");
            fflush(stdin);
            scanf("%s", vectorAux[cont2].Cobertura);
       }
       else if(vectorAux[cont2].Nombre == cambio && option == 4) {
            printf("\nIngrese la nueva cantidad del medicamento disponible:");
            fflush(stdin);
            scanf("%d", &vectorAux[cont2].Cantidad);
       }
       else if(vectorAux[cont2].Nombre == cambio && option == 5) {
            printf("<\nIngrese el nuevo precio del medicamento:");
            fflush(stdin);
            scanf("%f", &vectorAux[cont2].Precio_Venta);
       }
    }
    fp = fopen("DatosFarmacia.dat","wt");

    int cont3;
    for (cont3 = 0; cont3 < cont-1 ; cont3++){
        fwrite(&vectorAux[cont3], sizeof(Bloque), 1, fp);	
    }
    fclose(fp);
    
    return 0;
}


/* GUARDAR */
int guardar(void) {
    int continuar;
    FILE *fp;
    
    // Guardamos nuestros datos en un fichero .dat escrito en binario "wb"
	printf("\nSe sobreescribira el fichero DatosFarmacia.dat desea continuar? (si=1 no=0): "); 
    scanf("%d", &continuar); 
	printf("\n");
    if (continuar == 1) {
	    fp = fopen("DatosFarmacia.dat","wb");
	    aux = inicio;
	    while (aux -> sig != NULL) {
	        fwrite(&aux -> datos, sizeof(struct Bloque), 1, fp);
	        aux = aux -> sig;
	    }
	    fclose(fp);
	    
		printf("\n      ****Guardado Correctamente****\n\n"); 
	    system("PAUSE");
    }
    
    return 0;
}

/* RECUPERAR */
int recuperar(void){
	FILE *fp;
	// Recuperamos nuestros datos de un fichero .dat escrito en binario "rb"
	fp = fopen("DatosFarmacia.dat", "rb");
	
	if (fp != NULL) {
		while(feof(fp) == 0) {
		    fread(&aux -> datos,sizeof(struct Bloque),1,fp);
		    aux -> sig = (Nodo*)malloc( sizeof(struct Nodo));
		    atras = aux;
		    aux = aux -> sig;
		}
		fclose(fp);
		free(aux);
		aux = atras;
		aux -> sig = NULL;
		printf("\nArchivo Recuperado\n"); 
	} else {
		printf("\nNo existe ningun archivo\n"); 
	}
	
	printf("\n");
	system("PAUSE");
	    
	return 0;
}

/* MENU */
int main(){
	int opcion;
    // Definimos la cabecera con el puntero inicio
    inicio = (Nodo*)malloc(sizeof(struct Nodo));
    aux = inicio;
    aux -> sig = NULL;
    system("cls");	

    printf("\n");
    printf("########    ###    ########  ##     ##    ###     ######  ####    ###"); printf("\n");
    printf("##         ## ##   ##     ## ###   ###   ## ##   ##    ##  ##    ## ##"); printf("\n");
    printf("##        ##   ##  ##     ## #### ####  ##   ##  ##        ##   ##   ##"); printf("\n");
    printf("######   ##     ## ########  ## ### ## ##     ## ##        ##  ##     ##"); printf("\n");
    printf("##       ######### ##   ##   ##     ## ######### ##        ##  #########"); printf("\n");
    printf("##       ##     ## ##    ##  ##     ## ##     ## ##    ##  ##  ##     ##"); printf("\n");
    printf("##       ##     ## ##     ## ##     ## ##     ##  ######  #### ##     ##"); printf("\n \n \n");
	// Este es nuestro menu principal que se incia al empezar el programa y desde el cual podremos acceder a la funcion que deseemos
    system("PAUSE");

    while (opcion != 12) {
        //  cls para limpiar la pantalla
        system("cls");
        
        // Mostramos menu
        printf("\n");
        printf("                **MENU** \n  \n ");
        printf("     |  1) Crear Medicamento       |  \n ");
        printf("     |  2) CrearArc Medicamento    |  \n ");
        printf("     |  3) Eliminar Medicamento    |  \n ");
        printf("     |  4) EliminarArc Medicamento |  \n ");
        printf("     |  5) Consultar Medicamento   |  \n ");
        printf("     |  6) ConsultarArc Medicamento|  \n ");
        printf("     |  7) Modificar Medicamento   |  \n ");
        printf("     |  8) ModificarArc Medicamento|  \n ");
        printf("     |  9) Mostrar Todos           |  \n ");
        printf("     |  10) Guardar                |  \n ");
        printf("     |  11) Recuperar programa     |  \n ");
        printf("     |  12) Salir del Programa     |  \n \n ");
        printf("             **Fin Menu** \n \n");
        printf("Que desea hacer: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
//              Crear Medicamento
                crear();
                break;

            case 2:
//              Crear Medicamento
                crear_archivo();
                break;

            case 3:
//              Eliminar Medicamento
                eliminar();
                break;

            case 4:
//              Eliminar Medicamento
                eliminar_archivo();
                break;

            case 5:
//              Consultar Medicamento
                consultar();
                break;

            case 6:
//              Consultar Medicamento en el archivo
                consultar_archivo();
                break;

            case 7:
//              Modificar Datos
                modificar();
                break;

            case 8:
//              Modificar Datos
                modificar_archivo();
                break;

            case 9:
//              Mostrart todos
                mostrar_todos();
                break;

            case 10:
//              Guardar datos
                guardar();
                break;

            case 11:
//              Recuperar Datos
                recuperar();
                break;

            case 12:
//              FIN DEL PROGRAMA
				printf("\n      **FIN DEL PROGRAMA.**\n\n"); 
                break;

            default:
				printf("\n       Opcion no valida.\n");
                system("PAUSE");
                break;
            };
        };
    };
