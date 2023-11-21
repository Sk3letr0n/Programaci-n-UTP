// Revisado por Steven Grisales López. AL momento de hacer la prueba de escritorio se vuelve un poco confuso el hacerlo al final, así que por eso no lo adjunto.
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
//#include <alloc.h>
// definicion de la estructura de pila dinamica

struct nodo
{
	int dato;
	struct nodo * ant;
};

int vacia(struct nodo *tope) {
	return (!tope)? 1:0;
}

struct nodo * crearnodo(int dato){
	struct nodo* p;
	p=(struct nodo*)malloc (sizeof (p));
	p->dato=dato;
	p->ant=NULL;
	return(p);
}

//empilar: introducir un nuevo dato en la pila
struct nodo* push(struct nodo * tope,int dato){
	struct nodo *aux;
	aux=crearnodo(dato);
	aux->ant=tope;
	tope=aux;
return(tope);
}

//muestra todos los elementos de la pila
void mostrar(struct nodo *tope){
	struct nodo *aux;
	if(!tope) printf("Esta vacia");
	else
	{ aux=tope;
	do{
		printf("\n%d",aux->dato);
		aux=aux->ant;
	}while(aux!= NULL);
	}
}

// desempilar: sacar un dato de la pila
struct nodo* pop(struct nodo *tope,int* valor){
	struct nodo *aux;

	int dato;
	aux=tope;
	*valor=tope->dato;
	tope=tope->ant;
	free(aux);
return(tope);
}


main()
{
	struct nodo *tope=NULL;
	char opc;
	int dato,ban;
	do{
		printf("\n 1. Meter dato en la Pila");
		printf("\n 2. Sacar Dato de la Pila");
		printf("\n 3. Mostrar Pila");
		printf("\n 4. Salir");
		printf("\nOpcion: ");
		opc=getche();
		switch(opc)
		{
			case '1':

			printf("\nEscribe dato: ");
			scanf("%d",&dato);
			if(tope==NULL)
				tope=crearnodo(dato);
			else
				tope=push(tope,dato);
				break;

			case '2':

			if(!vacia(tope)) {
				tope=pop(tope,&dato);
				printf("El dato en la cima es: %d",dato);
			}
			else printf("Pila Vacia");
			getch();
			break;

			case '3':

			if (!vacia(tope)){
				printf("\nPila: ");
				mostrar(tope);
			}
			else printf("Pila Vacia");
			getch();
			break;
			
			case '4': break;
		}
	}while(opc!='4');
}