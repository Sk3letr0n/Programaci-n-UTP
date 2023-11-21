#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

/* Declaraciones globales */
typedef struct datos {
    int clave, contador;
    struct datos *izqdo, *dcho;
} nodo;
nodo *raiz = NULL;

/* funciones prototipo */
void creararbol(void);
nodo *anadir(int num, nodo *r);
void preorden(nodo *r);
void inorden(nodo *r);
void postorden(nodo *r);
void borrararbol(nodo *r);

/* Programa principal */
int main() {
    creararbol();
    printf("\n\nRecorrido en PREORDEN:\n"); 
    preorden(raiz);
    printf("\n\nRecorrido en INORDEN:\n"); 
    inorden(raiz);
    printf("\n\nRecorrido en POSTORDEN:\n"); 
    postorden(raiz);
    borrararbol(raiz);
    return 0;
}

void creararbol(void) {
    char entrada[100];
    int c;
    double num;
    system("cls");
    while (1) {
        printf("Ingrese numero u operacion (+, -, *, /): "); 
        c = scanf("%s", entrada);
        if (c == EOF) {
            break;
        }
        if (sscanf(entrada, "%lf", &num) == 1) {
            raiz = anadir((int)num, raiz);
        } else {
            if (entrada[0] == '+') {
                double num1, num2;
                if (sscanf(entrada + 1, "%lf+%lf", &num1, &num2) == 2) {
                    raiz = anadir((int)(num1 + num2), raiz);
                } else {
                    printf("Entrada no valida\n");
                }
            } else if (entrada[0] == '-') {
                double num1, num2;
                if (sscanf(entrada + 1, "%lf-%lf", &num1, &num2) == 2) {
                    raiz = anadir((int)(num1 - num2), raiz);
                } else {
                    printf("Entrada no valida\n");
                }
            } else if (entrada[0] == '*') {
                double num1, num2;
                if (sscanf(entrada + 1, "%lf*%lf", &num1, &num2) == 2) {
                    raiz = anadir((int)(num1 * num2), raiz);
                } else {
                    printf("Entrada no valida\n");
                }
            } else if (entrada[0] == '/') {
                double num1, num2;
                if (sscanf(entrada + 1, "%lf/%lf", &num1, &num2) == 2) {
                    raiz = anadir((int)(num1 / num2), raiz);
                } else {
                    printf("Entrada no valida\n");
                }
            } else {
                printf("Entrada no valida\n");
            }
        }
    }
}




nodo *anadir(int num, nodo *r) //funci�n recursiva para a�adir nodos al arbol
{ 
if (r==NULL)
{ 
	r = (nodo *)malloc(sizeof(nodo)); //se crea nuevo nodo y se carga de datos
	if (r==NULL) { printf ("Falta Memoria."); 
		getch(); }
else
{ 
	r->clave = num; r->contador = 1; r->izqdo = r->dcho = NULL; }
}
else
{ if (num < r->clave) //si el n�mero es menor que la clave del nodo actual
	r->izqdo = anadir(num, r->izqdo);
else if (num > r->clave) //si el n�mero es mayor que la clave del nodo actual
	r->dcho = anadir(num, r->dcho);
else //si el n�mero es igual que la clave del nodo actual
r->contador++;
}
return r;
}

void preorden(nodo *r) //funci�n recursiva
{ if (r!=NULL)
{ 	
	printf("%d ",r->clave); 
	preorden(r->izqdo); 
	preorden(r->dcho); }
}

void inorden(nodo *r) //funci�n recursiva
{ if (r!=NULL)
{ inorden(r->izqdo);
printf("El # %d se ha introducido %d veces\n",r->clave,r->contador);
inorden (r->dcho);
}
}
void postorden(nodo *r) //funci�n recursiva
{ if (r!=NULL)
{ postorden(r->izqdo); 
  postorden(r->dcho); 
  printf("%d ",r->clave); }
}
void borrararbol(nodo *r) //funci�n recursiva, recorrido en PostOrden
{ if (r!=NULL)
{ borrararbol(r->izqdo); 
  borrararbol(r->dcho); 
free(r); }
}


