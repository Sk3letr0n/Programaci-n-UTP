// Hecho por Steven Grisales Lopez.

// Librerías.
#include<stdio.h>
#include<stdlib.h>

typedef int TipoElemento; // Tipo de dato que se va a almacenar en el arbol.  

// Estructura de nodo.
struct nodo{
    TipoElemento dato; // Dato del nodo.
    int fe; // Factor de equilibrio.
    struct nodo *izdo, *dcho; // Punteros al hijo izquierdo y derecho.
};
typedef struct nodo Nodo; // Tipo de dato para definir un nodo.

// Estructura para crear los nodos del árbol.
Nodo* crearNodoAVL(int dato) { 
    Nodo* nuevoNodo = new Nodo; // Crear un nuevo nodo.
    nuevoNodo -> dato = dato; // Asignar el dato al nodo.
    nuevoNodo -> fe = 0;  // Asignar el factor de equilibrio al nodo.
    nuevoNodo -> izdo = NULL; // Asignar el hijo izquierdo del nodo.
    nuevoNodo -> dcho = NULL; // Asignar el hijo derecho del nodo.

    return nuevoNodo; // Retornar el nodo creado.
}

// Prototipos de funciones.
void insertarEquilibrado(Nodo** raiz, TipoElemento clave, int* h);
void rotacionII(Nodo** n, Nodo* n1);
void rotacionDD(Nodo** n, Nodo* n1);
void rotacionID(Nodo** n, Nodo* n1);
void rotacionDI(Nodo** n, Nodo* n1);
void eliminarNodoAVL(Nodo** raiz, TipoElemento clave, int* h);
void reemplazar(Nodo** actual, Nodo** reemplazo, int* h);
void balancearIzquierda(Nodo** n, int* h);
void balancearDerecha(Nodo** n, int* h);

// Rotación izquierda izquierda
void rotacionII(Nodo** n, Nodo* n1){
    (*n) -> izdo = n1 -> dcho; // El hijo izquierdo del nodo es igual al hijo derecho del nodo 1.
    n1 -> dcho = (*n); // El hijo derecho del nodo 1 es igual al nodo.   

    /* Actualización de los factores de equilibrio*/
    /* En la inserción siempre se cumple */
    if(n1 -> fe == -1){ // Si el factor de equilibrio del nodo 1 es igual a -1.  
        (*n) -> fe = 0; // El factor de equilibrio del nodo es igual a 0.
        n1 -> fe = 0; // El factor de equilibrio del nodo 1 es igual a 0.
    } else {
        (*n) -> fe = -1; // El factor de equilibrio del nodo es igual a -1.
        n1 -> fe = 1; // El factor de equilibrio del nodo 1 es igual a 1.
    }
    (*n) = n1; // El nodo es igual al nodo 1.
}

// Rotación derecha derecha
void rotacionDD(Nodo** n, Nodo* n1){
    (*n) -> dcho = n1 -> izdo; // El hijo derecho del nodo es igual al hijo izquierdo del nodo 1.
    n1 -> izdo = (*n); // El hijo izquierdo del nodo 1 es igual al nodo.

    /* Actualización de los factores de equilibrio*/
    /* En la inserción siempre se cumple */
    if(n1 -> fe == 1){ // Si el factor de equilibrio del nodo 1 es igual a 1.  
        (*n) -> fe = 0; // El factor de equilibrio del nodo es igual a 0.
        n1 -> fe = 0; // El factor de equilibrio del nodo 1 es igual a 0.
    } else{
        (*n) -> fe = 1; // El factor de equilibrio del nodo es igual a 1.
        n1 -> fe = -1; // El factor de equilibrio del nodo 1 es igual a -1.
    }
    (*n) = n1; // El nodo es igual al nodo 1.
}

// Rotación Izquierda Derecha
void rotacionID(Nodo** n, Nodo* n1){
    Nodo* n2; // Nodo 2.

    n2 = n1 -> dcho; // El nodo 2 es igual al hijo derecho del nodo 1.
    (*n) -> izdo = n2 -> dcho; // El hijo izquierdo del nodo es igual al hijo derecho del nodo 2.
    n2 -> dcho = *n; // El hijo derecho del nodo 2 es igual al nodo.
    n1 -> dcho = n2 -> izdo; // El hijo derecho del nodo 1 es igual al hijo izquierdo del nodo 2.
    n2 -> izdo = n1; // El hijo izquierdo del nodo 2 es igual al nodo 1.

    /* Actualización de los factores de equilibrio*/
    if(n2 -> fe == 1){ // Si el factor de equilibrio del nodo 2 es igual a 1.
        n1 -> fe = -1; // El factor de equilibrio del nodo 1 es igual a -1.
    } else {
        n1 -> fe = 0; // El factor de equilibrio del nodo 1 es igual a 0.
    }

    if(n2 -> fe == -1){ // Si el factor de equilibrio del nodo 2 es igual a -1.
        (*n) -> fe = 1; // El factor de equilibrio del nodo es igual a 1.
    } else {
        (*n) -> fe = 0; // El factor de equilibrio del nodo es igual a 0.
        n2 -> fe = 0; // El factor de equilibrio del nodo 2 es igual a 0.
        (*n) = n2; // El nodo es igual al nodo 2.
    }
}

// Rotación derecha izquierda
void rotacionDI(Nodo** n, Nodo* n1){
    Nodo* n2; // Nodo 2.

    n2 = n1 -> izdo; // El nodo 2 es igual al hijo izquierdo del nodo 1.
    (*n) -> dcho = n2 -> izdo; // El hijo derecho del nodo es igual al hijo izquierdo del nodo 2.
    n2 -> izdo = *n; // El hijo izquierdo del nodo 2 es igual al nodo.
    n1 -> izdo = n2 -> dcho; // El hijo izquierdo del nodo 1 es igual al hijo derecho del nodo 2.
    n2 -> dcho = n1; // El hijo derecho del nodo 2 es igual al nodo 1.

    /* Actualización de los factores de equilibrio*/
    if(n2 -> fe == 1){ // Si el factor de equilibrio del nodo 2 es igual a 1.
        (*n) -> fe = -1; // El factor de equilibrio del nodo es igual a -1.
    } else {
        (*n) -> fe = 0; // El factor de equilibrio del nodo es igual a 0.
    }

    if(n2 -> fe == -1){ // Si el factor de equilibrio del nodo 2 es igual a -1.
        n1 -> fe = 1; // El factor de equilibrio del nodo 1 es igual a 1.
    } else {
        n1 -> fe = 0; // El factor de equilibrio del nodo 1 es igual a 0.
        n2 -> fe = 0; // El factor de equilibrio del nodo 2 es igual a 0.
        (*n) = n2; // El nodo es igual al nodo 2.
    }
}

// Función para insertar un nodo en el árbol AVL.
void insertarEquilibrado(Nodo** raiz, TipoElemento clave, int* h){
    Nodo* n1; // Nodo 1.

    if(!(*raiz)){ // Si el nodo es nulo.
        *raiz = crearNodoAVL(clave); // Crear un nuevo nodo.
        *h = 1; // El árbol crece.
    }
    else if(clave < (*raiz) -> dato){ // Si la clave es menor al dato del nodo.
        insertarEquilibrado(&((*raiz) -> izdo), clave, h);

    /* Regreso por los nodos del camino*/
    if(*h){
    /* Reduce en 1 el fe al aumentar altura de rama izquierda*/
        switch((*raiz) -> fe){
            case 1: (*raiz) -> fe = 0; 
                    (*h) = 0; /* Se recupera el equilibrio*/
            break;

            case 0: (*raiz) -> fe = -1; /* Se recupera el equilibrio*/
            break;

            case -1: /* Viola el equilibrio, rotación izquierda*/
                n1 = (*raiz) -> izdo; // El nodo 1 es igual al hijo izquierdo del nodo.
                if(n1 -> fe == -1) // Si el factor de equilibrio del nodo 1 es igual a -1.
                    rotacionII(raiz, n1);
                else
                    rotacionID(raiz, n1);
                (*h) = 0; /* Se recupera el equilibrio*/
            break;
        }
    }

    } else if(clave > (*raiz) -> dato){ // Si la clave es mayor al dato del nodo.
        insertarEquilibrado(&((*raiz) -> dcho), clave, h);

        /* Regreso por los nodos del camino*/
        if(*h){
            /* Incrementa en 1 el fe al aumentar altura de rama derecha*/
            switch((*raiz) -> fe){
                case 1: /* Viola el equilibrio, rotación derecha*/
                    n1 = (*raiz) -> dcho; // El nodo 1 es igual al hijo derecho del nodo.

                    if(n1 -> fe == +1) // Si el factor de equilibrio del nodo 1 es igual a 1.
                        rotacionDD(raiz, n1);
                    else
                        rotacionDI(raiz, n1);
                        (*h) = 0; /* Se recupera el equilibrio*/
                break;

                case 0: (*raiz) -> fe = +1; /* Se recupera el equilibrio*/
                break;

                case -1:
                (*h) = 0; /* Se recupera el equilibrio*/
                break;
            }
        }
        } else {
            puts("En arboles de busqueda no puede haber claves repetidas.");
            (*h) = 0; // El árbol no crece.
        }
}

// Función para eliminar un nodo del árbol AVL.
void eliminarNodoAVL(Nodo** raiz, TipoElemento clave, int* h) {
    Nodo* aux; // Nodo auxiliar.

    if (*raiz == NULL) {
        printf("El elemento a eliminar no existe en el árbol." );
        *h = 0; // El árbol no crece.
        return;
    }

    if (clave < (*raiz) -> dato) { // Si la clave es menor al dato del nodo.
        eliminarNodoAVL(&((*raiz) -> izdo), clave, h);

        if (*h) { // Si el árbol crece.
            balancearIzquierda(raiz, h);
        }
    }
    else if (clave > (*raiz)->dato) { // Si la clave es mayor al dato del nodo.
        eliminarNodoAVL(&((*raiz) -> dcho), clave, h); 

        if (*h) { // Si el árbol crece.
            balancearDerecha(raiz, h); 
        }
    } else {
        aux = *raiz; // El auxiliar es igual al nodo.

        if (aux -> izdo == NULL) { // Si el hijo izquierdo del nodo es nulo.
            *raiz = aux -> dcho; // El nodo es igual al hijo derecho del nodo.    
            *h = 1; // El árbol crece.
            delete aux; // Eliminar el nodo.
        }
        else if (aux -> dcho == NULL) { // Si el hijo derecho del nodo es nulo.
            *raiz = aux -> izdo; // El nodo es igual al hijo izquierdo del nodo.
            *h = 1; // El árbol crece.
            delete aux; // Eliminar el nodo.
        } else {
            reemplazar(raiz, &(aux -> izdo), h); 
            if (*h) { // Si el árbol crece.
                balancearIzquierda(raiz, h); 
            }
        }
    }
}

// Función para reemplazar un nodo.
void reemplazar(Nodo** actual, Nodo** reemplazo, int* h) {
    if ((*reemplazo) -> dcho != NULL) { // Si el hijo derecho del reemplazo no es nulo.
        reemplazar(actual, &((*reemplazo) -> dcho), h); 
        if (*h) { // Si el árbol crece.
            balancearDerecha(reemplazo, h); 
        }
    } else {
        (*actual) -> dato = (*reemplazo) -> dato; // El dato del actual es igual al dato del reemplazo.
        *actual = *reemplazo; // El actual es igual al reemplazo.
        *reemplazo = (*reemplazo) -> izdo; // El reemplazo es igual al hijo izquierdo del reemplazo.
        *h = 1; // El árbol crece.
        delete *actual; // Eliminar el nodo.
    }
}

// Función para obtener la altura del árbol.
void balancearIzquierda(Nodo** n, int* h) {
    Nodo *n1, *n2; // Nodos.

    switch ((*n) -> fe) { // Según el factor de equilibrio del nodo.
        case -1:
            (*n) -> fe = 0; // El factor de equilibrio del nodo es igual a 0.
            break;
        case 0:
            (*n) -> fe = 1; // El factor de equilibrio del nodo es igual a 1.
            *h = 0; // El árbol no crece.
            break;
        case 1:
            n1 = (*n) -> dcho; // El nodo 1 es igual al hijo derecho del nodo.
            if (n1 -> fe >= 0) { // Si el factor de equilibrio del nodo 1 es mayor o igual a 0.
                if (n1 -> fe == 0) { // Si el factor de equilibrio del nodo 1 es igual a 0.
                    *h = 0; // El árbol no crece.
                }
                rotacionDI(n, n1); 
            } else {
                rotacionDD(n, n1); 
            }
            break;
    }
}

// Función para balancear el árbol a la derecha.
void balancearDerecha(Nodo** n, int* h) {
    Nodo *n1, *n2; // Nodos.

    switch ((*n) -> fe) { // Según el factor de equilibrio del nodo.
        case 1: 
            (*n) -> fe = 0; // El factor de equilibrio del nodo es igual a 0.
            break;
        case 0:
            (*n) -> fe = -1; // El factor de equilibrio del nodo es igual a -1.
            *h = 0; // El árbol no crece.
            break;
        case -1:
            n1 = (*n) -> izdo; // El nodo 1 es igual al hijo izquierdo del nodo.
            if (n1 -> fe <= 0) { // Si el factor de equilibrio del nodo 1 es menor o igual a 0.
                if (n1 -> fe == 0) { // Si el factor de equilibrio del nodo 1 es igual a 0.
                    *h = 0; // El árbol no crece.
                }
                rotacionID(n, n1); 
            }
            else {
                rotacionII(n, n1);  
            }
            break;
    }
}