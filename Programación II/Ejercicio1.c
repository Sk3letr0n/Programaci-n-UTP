/*
Fecha: 01/05/2022
Hora: 7:00 pm.
Version: 1.2
Autor: CRISTIAN DAVID ARANGO TORRES
lenguaje: C(ISO/IEC).
Version lenguaje: 11
Presentado a: Doctor Ricardo Moreno Laverde.
Organizacion: Universidad tecnologica de pereira.
Programa: Ingenieria de sistemas y computacion.
Asignatura: IS284 Programacion 2.
Descripcion: Laberinto
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//prototipado de funciones
void rellenar_array(char[]);
void imprimir_array(char[]);

int main()
{
	srand(time(NULL));
	char laberinto [900];
	rellenar_array(laberinto);
	imprimir_array(laberinto);
}//fin definicion main

/*
Descripcion: esta funcion crea aleatoriamente un laberinto de 30x30.
*/
void rellenar_array(char laberinto[])
{
	int alto = 0;
	int ancho = 0;
	for(alto; alto <= 29; alto++)
  {
		for(ancho = 0; ancho <= 29; ancho++)
    {
			if(alto == 29 || alto == 0 || ancho == 29 || ancho == 0)
				laberinto[(alto * 30) + ancho] = 219; //bordes
			else if(rand()%4 == 0) //25% de probabilidad 
					laberinto[(alto * 30) + ancho] = 219; //muro
				else
					laberinto[(alto * 30) + ancho] = 32; //espacio
		}
	}
	laberinto[0] = 32;   //definir
	laberinto[1] = 32;   //entrada
	laberinto[30] = 32;  //en blanco
	laberinto[31] = 32;  //en blanco
	laberinto[((rand()%28 + 1) * 30) + 29] = 32; //salida 
	return;
}//fin definicion rellenar_array

/*
Descripcion: esta funcion imprime un string en forma de 30X30.
*/
void imprimir_array(char laberinto[])
{
	int alto = 0;
	int ancho = 0;
	printf("                         1         2         \n");
	printf("               012345678901234567890123456789\n");
	for(alto; alto <= 29; alto++)
  	{
		if(alto == 0)
    	{
			printf("Entrada => %i   ", alto);
		}
   		else if (alto < 10)
    	{
			printf("           %i   ", alto);
		}
    	else
    	{
			printf("           %i  ", alto);
		}
	for(ancho = 0; ancho <= 29; ancho++)
    {
		printf("%c", laberinto[(alto * 30) + ancho]); //imprimir el laberinto
		if(laberinto[(alto * 30) + ancho] == 32 && ancho == 29)
			printf("=> Salida");
	}
		printf("\n");
	}
	return;
}//fin definicion imprimir_array