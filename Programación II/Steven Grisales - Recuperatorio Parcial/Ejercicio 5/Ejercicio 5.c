/*
Fecha de publicaci�n: 2/10/2022
Hora: 3:45 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 5.11
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Usted debe crear la funci�n rush tomando dos(2) valores enteros positivos como argumentos, denominados respectivamente x e y.
Su funci�n rush debe mostrar (en pantalla del ordenador) un rect�ngulo de x caracteres para el ancho, y de y caracteres para la longitud.
El profesor podr� modificar los valores de los argumentos durante la defensa, para comprobar si ha manejado todo como se supone que debe.
*/

#include<stdio.h>

//Descripcion: imprime x veces un caracter c.
void imprimir_linea(int x, int c)
{
	if(x > 0)
    {
		printf("%c", c);
		imprimir_linea(x - 1, c);
	}
	return;
}

//Descripcion: imprime la parte superior de rush.
void parte_superior(int x)
{
	if(x > 0)
    {
		if(x > 1)
        {
			imprimir_linea(x - 1, 42);
		}
		printf("%c", 92);
	}
	return;
}

//Descripcion: imprime la parte media de rush.
void parte_media(int x,int y)
{
	if(y > 0)
    {
		printf("*");
		if(x > 1)
        {
			imprimir_linea(x - 2, 32);
			printf("*");
		}
		printf("\n");
		parte_media(x, y - 1);
	}
	return;
}

//Descripcion: imprime la parte infeior de rush.
void parte_inferior(int x)
{
	if(x > 0)
    {
		if(x > 1)
        {
			imprimir_linea(x - 1, 42);
		}
		printf("%c", 47);
	}
	return;
}

//Descripcion: imprime rush juntando todas sus partes.
void rush(int x, int y)
{
	if(x > 0 && y > 0)
    {
		printf("/");
		parte_superior(x - 1);
		if(y > 1)
        {
			printf("\n");
			parte_media(x,y - 2);
			printf("%c", 92);
			parte_inferior(x - 1);
		}
	}
    return;
}

int main()
{
	int ancho=0,alto=0;
	printf("Ingrese el ancho: ");
	scanf("%i",&ancho);
	printf("\nIngrese el alto: ");
	scanf("%i",&alto);
	rush(ancho,alto);
}
