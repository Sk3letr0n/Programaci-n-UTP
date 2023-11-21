// Revisado por Steven Grisales López. AL momento de hacer la prueba de escritorio se vuelve un poco confuso el hacerlo al final, así que por eso no lo adjunto.
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>

struct nodo{
    int dato;
    struct nodo *sig;
};

// funcion para crear un nodo nuevo en la cola
struct nodo* crearNodo(int dato){
    struct nodo *p;
    p=(struct nodo*)malloc(sizeof (struct nodo));
    p->dato=dato;
    p->sig=NULL;
    return(p);
}

//funcion para insertar un dato en un nodo nuevo en la cola
struct nodo* insertar(struct nodo *inicio, int dato){
    struct nodo * p,* nuevo, *q;
    nuevo=crearNodo(dato);
    p=inicio;

    while(p!=NULL){
        q=p;
        p=p->sig;
    }
    q->sig=nuevo;
    return(inicio);
}

// Mostrar los elementos de la cola
void mostrar(struct nodo *inicio){

    struct nodo *aux;
    aux=inicio;
    do{
        printf("%d, ",aux->dato);
        aux=aux->sig;
        }while(aux);
}

//funcion para borrar un elemento de la cola
struct nodo* borrar(struct nodo *inicio){
    struct nodo *p;
    p=inicio;
    printf("Dato extraido: %d\n",p->dato);
    inicio=p->sig;
    free(p);
return inicio;
}

//Programa Principal donde se llaman a las funciones basicas
main()
{
    
     struct nodo *inicio=NULL;
    struct nodo *p=NULL;
    char op;
    int x;
    do{
        printf("\t\t\tMENU PRINCIPAL\n\n\n");
        printf("\t 1. Insertar\n");
        printf("\t 2. Mostrar\n");
        printf("\t 3. Eliminar\n");
        printf("\t 4. Salir\n");
        printf("\nOpcion: "); op=getch();

        switch(op){
            case '1': printf("Ingrese el numero a introducir: ");
            scanf("%d",&x);
            if(!inicio)
                inicio=crearNodo(x);
            else
                inicio=insertar(inicio,x);
            p=inicio;
            break;

            case '2':
            if(inicio){
                printf("La Cola es: [");mostrar(inicio);
                printf("]\n");
            }
            else
                printf("La cola esta vacia\a\n");
            getch();
            break;

            case '3':
            if(!inicio) 
                printf("Error. La cola esta vacia.\a\n");
            else
            inicio=borrar(inicio);

            getch();
            break;
        }
    }while(op!='4');
}
