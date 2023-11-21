#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "malloc.h"
#include "ctype.h"
#include "time.h"

 /* Estructura de un nodo del Arbol */
typedef struct nodo arbol;
struct nodo{
	int dato;
	arbol *izquierdo;
	arbol *derecho;
};


/* Programa Principal */
int main(){
	int n, i, dato; // Variables de control
	char op; // Variable de control
	arbol *p = NULL; /* Arbol vacio */
	while(1){
		menu(); 
		op = tolower(getch()); // Lee la opcion
		switch(op){ 
			case 'a': printf("\nNumero de nodos del arbol"); 
				scanf("%d", &n);
				n = abs(n); /* Solo n positivo */
				srand(time(NULL)); // Generamos numero aleatorio en base al tiempo
				for(i = 0; i < n; i++){ // Llenamos el arbol
					printf("\n\tElemento No. %d : ", i + 1);
					dato = rand() % 200; // Genera un numero aleatorio entre 0 y 199
					printf("%d", dato);
					p = insertar(dato, p); // Inserta el dato en el arbol
				}
			break;
			case 'c' : printf("\nNumero de nodos del arbol: ");
				scanf("%d", &n);
				n = abs(n); /* Solo n positivo */
				for(i = 0; i < n; i++){ // Llenamos el arbol
					printf("\n\tElemento No. %d: ",i + 1); 
					scanf("%d" , &dato) ; 
					p = insertar(dato, p); // Inserta el dato en el arbol
				}
			break;
			case 'v': printf("Arbol Binario");
				ver(0, p); // Muestra el arbol
			break;
			case 'm': 
				printf("\n\n\tMinimo = %d",buscar_min(p));
				printf("\n\n\tMaximo = Xd",buscar_max(p));
			break;
			case 'n': printf("\n\n\tNodos: %d",num_nodos(p)) ;
			break;
			case 'b':
				printf("\n\tDato a Buscar : ");
				scanf("%d",&dato) ;
				printf("\n\t");	
				if(buscar(p, dato) != NULL) // Busca el dato	 
				printf("\n\tSe encontr� el dato %d", dato);	
				else printf("\n\t\aNo se encontr� el dato %d", dato);
			break;
			case 'r': printf("Recorrido en Pre-Orden:");
				pre_orden(p); // Recorre el arbol en Pre-Orden
				printf("Recorrido En Orden:");
				en_orden(p); // Recorre el arbol en En-Orden
				printf("Recorrido en Post-Orden:");
				post_orden(p) ; // Recorre el arbol en Post-Orden
				break; 
				case 's':printf("Dato a Suprimir: ");
					scanf("%d", &dato) ;
					suprimir(p, dato) ; // Suprime el dato del arbol
				break;
				case 'q':
					exit(1);
				break;
		}
		getch(); // Espera una tecla
	}
	return 0;
}

 /* Mensaje de ERROR */
void error (void){
perror("\n\tERROR: Memoria insuficiente...");
exit(1);
}

 /* Crea un nuevo nodo del tipo de La estructura */
arbol *Nuevo(){
	arbol *q = (arbol*)malloc (sizeof(arbol)); // Reserva memoria
	if(!q) error (); // Si no hay memoria disponible
	return (q);
}

/* Cambia el dato de p por el dato de S */
arbol *cambia (arbol *p, arbol *s){ 
	arbol *temp; // Variable temporal
	if(s -> derecho != NULL) 
        s -> derecho = cambia(p, s -> derecho); // Busca el dato mas grande
	else { // Si no hay mas nodos a la derecha
		temp = s; // Guarda el nodo
		p -> dato = s -> dato; // Cambia el dato
		s = s -> izquierdo; // Cambia el puntero
		free(temp); // Libera el nodo
	}
	return (s);
}

/* Cuenta el n�mero de nodos en el arbol */
int num_nodos(arbol *p){
	if(p == NULL) return (0); // Si el arbol esta vacio
	return(num_nodos (p -> izquierdo) + 1 + num_nodos(p -> derecho)); // Cuenta los nodos
}

/* Busca y suprime un dato del arbol */
arbol *suprimir(arbol *p,int dato){
	arbol *temp; // Variable temporal
	if(p == NULL) printf("\n\tArbol Vacio..."); // Si el arbol esta vacio
	else if(dato < p -> dato) // Si el dato es menor que el nodo
		p -> izquierdo = suprimir(p -> izquierdo,dato); // Busca el dato a la izquierda
	else if(dato > p -> dato) // Si el dato es mayor que el nodo
		p -> derecho = suprimir(p -> derecho,dato); // Busca el dato a la derecha
	else {
		temp = p; // Guarda el nodo
		if(temp -> derecho == NULL) { // Si no hay nodos a la derecha
			p = temp -> izquierdo; // Cambia el puntero
			free(temp); // Libera el nodo    
		}
		else if(temp -> izquierdo == NULL){ // Si no hay nodos a la izquierda
			p = temp -> derecho; // Cambia el puntero
			free(temp); // Libera el nodo
		}
		else temp -> izquierdo = cambia(temp,temp -> izquierdo); // Busca el dato mas grande
	}
	return(p);
}

/* Busca un dato en el arbol */
int buscar(arbol *p,int dato){
	if(p == NULL) return(NULL); // Si el arbol esta vacio
	if(dato == p -> dato) return(1); // Si el dato es igual al nodo
	if(dato < p -> dato) return(buscar(p -> izquierdo,dato)); // Busca el dato a la izquierda
	else return(buscar(p -> derecho,dato)); // Busca el dato a la derecha
}
/* Busca el dato minimo en el arbol */

int buscar_min(arbol *p){ 
	if(p == NULL) return(NULL); // Si el arbol esta vacio
	else if(p -> izquierdo == NULL) return(p -> dato); // Si no hay mas nodos a la izquierda
	else return(buscar_min(p -> izquierdo)); // Busca el dato mas pequeño
}

/* Busca el dato maximo en el arbol */
int buscar_max(arbol *p){
	if(p == NULL) return(NULL); // Si el arbol esta vacio
	else if(p -> derecho == NULL) return(p -> dato); // Si no hay mas nodos a la derecha
	else return(buscar_max(p -> derecho)); // Busca el dato mas grande
}
/* Recorre y muestra todos Los nodos; Breadth first Order */
void ver(int nivel,arbol *p){
	int i; // Variable de control
	if(p != NULL) { // Si el arbol no esta vacio 
		ver(nivel + 1,p -> derecho); // Busca el dato mas grande
		printf("\n"); 
		for (i = 0; i < nivel; i++) printf(" "); // Imprime los espacios
		printf("%d", p -> dato); // Imprime el dato
		ver(nivel + 1,p -> izquierdo); // Busca el dato mas pequeño
	} 
}
/* Recorre el Arbol en Pre-Orden; Depth first Order */
void pre_orden(arbol *p){
	if (p != NULL){ // Si el arbol no esta vacio
		printf("%d ",p -> dato); // Imprime el dato
		pre_orden(p -> izquierdo); // Busca el dato mas pequeño
		pre_orden(p -> derecho); // Busca el dato mas grande
	}
}
/* Recorre el Arbol en En-Orden */
void en_orden(arbol *p){
	if(p != NULL) { // Si el arbol no esta vacio
		en_orden(p -> izquierdo); // Busca el dato mas pequeño
		printf("%d ",p -> dato); // Imprime el dato
		en_orden(p -> derecho); // Busca el dato mas grande
	}
}

/* Recorre el drbol en Post-Orden */
void post_orden(arbol *p){
	if(p != NULL){ // Si el arbol no esta vacio
		post_orden(p -> izquierdo); // Busca el dato mas pequeño
		post_orden(p -> derecho); // Busca el dato mas grande
		printf("%d ", p -> dato); // Imprime el dato
	}
}

/* Insertar un nuevo nodo en el drbol */
arbol *insertar(int dato,arbol *p){
	if(p == NULL) { // Si el arbol esta vacio
		p = Nuevo(); // Crea un nuevo nodo
		p -> dato = dato; // Guarda el dato
		p -> izquierdo = NULL; // Pone los punteros a NULL
		p -> derecho = NULL; // Pone los punteros a NULL
		return(p);
	}
	if(dato < p -> dato)
		p -> izquierdo = insertar(dato,p -> izquierdo); // Busca el dato mas pequeño
	else p -> derecho = insertar(dato,p -> derecho); // Busca el dato mas grande
	return(p);
}

/* Pone menu */
void menu(void){
	printf("\n\nOperaciones Basicas con un arbol Binario\n\n");
	printf("A = Llenar un arbol de forma aleatoria\n") ;
	printf("C = Llenar un arbol de forma manual\n");
	printf("B = Buscar un dato\n");
	printf("S = Suprimir un Dato\n");
	printf("M = Buscar Minimo y Miximo\n") ;
	printf("N = Contar Nodos\n");
	printf("R = Ver Recorridos\n") ;
	printf("V = Ver arbol\n");
	printf("Q = Salir\n\n");
	printf("Elija una Opcion: ");
}