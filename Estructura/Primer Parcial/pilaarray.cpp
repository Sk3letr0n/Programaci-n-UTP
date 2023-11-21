// Hecho por Steven Grisales López.

#include "pilaarray.h"	
#include <stdio.h>
#include <stdlib.h>
//crearPila inicializa una pila sin elementos, vacï¿½a, pone el ï¿½ndice cima a -1.

void crearPila (Pila* pila)
{
pila -> cima = -1;
}


void insertar (Pila* pila, TipoDato elemento)
{
/* si la pila estï¿½ llena, termina el programa */
	if (pilaLlena (*pila) )
	{
		puts ("Desbordamiento pila");
		exit (1);
	}
pila -> cima++;
pila -> listaPila[pila->cima] = elemento;
}

/* Quitar un elemento de la pila */
TipoDato quitar (Pila* pila)
{
	TipoDato tem;
	/* si la pila estï¿½ vacï¿½a, termina el programa */
	if (pilaVacia (*pila) )
	{
	puts (" Se intenta sacar un elemento en pila vacï¿½a");
	exit (1);
	}
tem = pila -> listaPila[pila->cima];
pila -> cima--;
return tem;
}

//La operaciï¿½n cima devuelve el elemento que se encuentra en la cima de la pila, no se modifica la pila.
TipoDato cima (Pila pila)
{
if (pilaVacia (pila) )
{
puts (" Error de ejecuciï¿½n, pila vacï¿½a");
exit (1);
}
return pila.listaPila[pila.cima];
}

/*La funciï¿½n pilaVacia comprueba si la pila no tiene elementos; para que eso ocurra, la cima de
la pila debe ser -1.*/
int pilaVacia (Pila pila)
{
return pila.cima == -1;
}

/*La funciï¿½n pilaLlena comprueba si la pila estï¿½ llena, segï¿½n el tamaï¿½o del arreglo donde se
guardan sus elementos.*/
int pilaLlena (Pila pila)
{
return pila.cima == TAMPILA - 1;
}

/*Por ultimo, la operacion limpiarPila vacia ï¿½ntegramente la pila, para lo que pone cima al valor
que se corresponde con pila vacï¿½a (-1)*/
void limpiarPila (Pila* pila)
{
pila -> cima = -1;
}
