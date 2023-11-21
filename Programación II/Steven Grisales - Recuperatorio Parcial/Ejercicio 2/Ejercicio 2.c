/*
Fecha de publicación: 2/10/2022
Hora: 3:00 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 5.11
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Una empresa marca todos sus productos con un código QR como el de la figura, que es un arreglo de
30x30 píxeles negros y blancos. Es posible detectar un producto falsificado comprobando una serie de características en el código QR.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void rellenar_Qr(char qr[]);
void imprimir_Qr(char qr[]);
int comprobar(char qr[]);
void imprimir(char qr[]);

//Descripcion: funcion rellena el qr
void rellenar_Qr(char qr[]) {
	int ancho = 0; //Ancho del qr
	int alto = 0; //Alto del qr
	for(ancho; ancho <= 29; ancho = ancho + 1) {
		for(alto = 0; alto <= 29; alto = alto + 1) {
			if(ancho == 0 || ancho == 29 || alto == 0 || alto == 29) {
				qr[(ancho * 30) + alto] = 0; //bordes blancos
			}
            else {
				if(rand()%3 == 0) //33.3% probabilidad
            	{
					qr[(ancho * 30) + alto] = 1;
				}
                else
                {
					qr[(ancho * 30) + alto] = 0;
				}
			}
		}
	}
	return;
}// Fin funcion

//Descripcion: esta funcion imprime el array.
void imprimir_Qr(char qr[]) {
	int alto = 0; //Alto del qr
	int ancho = 0; //Ancho del qr
	printf("               1         2         \n");
	printf("     012345678901234567890123456789\n");
	printf("    +------------------------------+\n");
	for(alto; alto <= 29; alto = alto + 1) {
		if(alto < 10){
			printf("%i   |", alto);
		}
	    else{
			printf("%i  |", alto);
		}
		for(ancho = 0; ancho <= 29; ancho = ancho + 1) {
			if(qr[(alto * 30) + ancho] == 1)
				printf("%c", 219);
			else
				printf("%c", 32);
		}
		printf("|  %i\n", alto);
	}
	printf("    +------------------------------+\n");
	printf("     012345678901234567890123456789\n\n");

	return;
}//fin funcion


// Descripcion: esta funcion comprueba las condiciones del ejercicio.
int comprobar(char qr[]) {
	int v1 = 1, v2 = 1, ancho = 0, alto = 0, Contar = 0, errores = 0; //izquierda y derecha, arriba y abajo, ancho del qr, alto del qr, contador de los 25 pixeles de arriba derecha, los errores del qr
	
	for(ancho; ancho <= 29; ancho = ancho + 1) {
		if(qr[ancho * 30] == 1 || qr[(ancho * 30) + 29] == 1)
			v1 = 0;
	}
	for(alto; alto <= 29; alto = alto + 1) {
		if(qr[alto] == 1 || qr[(29 * 30) + alto] == 1)
			v2 = 0;
	}
	for(ancho = 22; ancho <= 28; ancho = ancho + 1) {
		for(alto = 1; alto <= 7; alto = alto + 1) {
			if(qr[(alto * 30) + ancho] == 1)
				Contar = Contar + 1;
		}
	}
	if(v1 && v2)
		printf("Condicion a: Se cumple.\n");
	else
	{
		printf("Condicion a: NO se cumple.\n");
		errores = errores + 1;
	}
	
	if(Contar >= 25)
		printf("Condicion b: Se cumple. Numeros de pixeles negros = %i\n", Contar);
	else
    {
		printf("Condicion b: NO se cumple. Numeros de pixeles negros = %i\n", Contar);
		errores = errores + 1;
	}
	if(qr[212] == 0 || qr[214] == 0 || qr[235] == 0) {
		errores = errores + 1;
		printf("Condicion c: NO se cumple.\n");
		printf("Errores: %i\n", errores);	
	}
	else
	{
		printf("Condicion c: Se cumple.\n");
		printf("Errores: %i\n", errores);
	}
	
	if(errores == 0 && v1 && v2 && Contar >= 25)
		printf("Es original");
	else
		printf("NO es original");

	return 0;
}

//Esta función imprime el qr ya organizado
void imprimir(char qr[]) {
	int alto = 0; //Alto del qr
	printf("                         1                   2         \n");
	printf("     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9\n");
	printf("    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
	218,196,194,196,194,196,194,196,194,196,194,
	196,194,196,194,196,194,196,194,196,194,196,194,196,194,196,194,196,194,196,194,196,194,196,194,196,194,196,194,196,194,
	196,194,196,194,196,194,196,194,196,194,196,194,196,194,196,194,196,194,196,191);
	
	for(alto; alto <= 29; alto = alto + 1) {
		if(alto < 10) {
			printf("%i   ", alto);
		}
        else {
			printf("%i  ", alto);
		}
		
		int ancho = 0; //Ancho del qr
		while(ancho <= 29) { 
			if(qr[(alto * 30) + ancho] == 1)
				printf("%c%c", 179, 219);
			else
				printf("%c ", 179);
			ancho = ancho + 1;
		}
		printf("%c %i\n", 179, alto);
		if (alto < 29)
		printf("    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", //61
		195,196,197,196,197,196,197,196,197,196,197,
		196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,197,
		196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,180);
	}
	printf("    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
	192,196,193,196,193,196,193,196,193,196,193,
	196,193,196,193,196,193,196,193,196,193,196,193,196,193,196,193,196,193,196,193,196,193,196,193,196,193,196,193,196,193,
	196,193,196,193,196,193,196,193,196,193,196,193,196,193,196,193,196,193,196,217);
	printf("     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9\n");
	
	return;
}

//Funcion main
int main() {
	srand(time(NULL));
	char qr [900];
	rellenar_Qr(qr);
	imprimir_Qr(qr);
	imprimir(qr);
	printf("Requisitos:\na) Los pixeles de la periferia estan siempre en blanco.\nb) El codigo tiene reservados un cuadrado 7x7 pixeles encajado en la parte mas externa superior derecha, que\ndebe estar formado por al menos 25 pixeles negros, con cualquier disposicion.\n");
	printf("c) En la septima fila, las columnas 2, 4 y 25 del arreglo son pixeles de color negro.\nCualquier producto que no cumpla los tres requisitos anteriores se consideran falsificado. El numero de errores se\ncalculara teniendo en cuenta solo el ultimo requisito (c),");
	printf("asignado un punto por cada pixel de los citados que no\nsea negro.\n");
	comprobar(qr);
}
