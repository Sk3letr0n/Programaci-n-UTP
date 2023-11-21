/*
Fecha de publicación: 2/10/2022
Hora: 2:45 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 5.11
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa imprime un laberinto
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//prototipado de funciones
void rellenar_Laberinto(char[]);
void imprimir_Laberinto(char[]);

int main() {
	srand(time(NULL));
	char laberinto [900];
	rellenar_Laberinto(laberinto);
	imprimir_Laberinto(laberinto);
}//fin definicion main

// Descripcion: esta funcion crea aleatoriamente un laberinto de 30x30.
void rellenar_Laberinto(char laberinto[]){
	int alto = 0; //El alto del laberinto
	int ancho = 0; //El ancho del laberinto
	for(alto; alto <= 29; alto = alto + 1) {
		for(ancho = 0; ancho <= 29; ancho = ancho + 1) {
			if(alto == 29 || alto == 0 || ancho == 29 || ancho == 0)
				laberinto[(alto * 30) + ancho] = 219; //bordes
			else if(rand() % 4 == 0) //25% de probabilidad 
				laberinto[(alto * 30) + ancho] = 219; //muro
			else
				laberinto[(alto * 30) + ancho] = 32; //espacio
		}
	}
	
	laberinto[0] = 32;   //definir
	laberinto[1] = 32;   //entrada
	laberinto[30] = 32;  //en blanco
	laberinto[31] = 32;  //en blanco
	laberinto[((rand() % 28 + 1) * 30) + 29] = 32; //salida 

	return;
}//fin definicion rellenar_array

// Descripcion: esta funcion imprime un string en forma de 30X30.
void imprimir_Laberinto(char laberinto[]) {
	int alto = 0; //El alto del laberinto
	int ancho = 0; //El ancho del laberinto
	printf("                         1         2         \n");
	printf("               012345678901234567890123456789\n");
	for(alto; alto <= 29; alto = alto + 1) {
		if(alto == 0){
			printf("Entrada => %i   ", alto);
		}
   		else if (alto < 10){
			printf("           %i   ", alto);
		}
    	else{
			printf("           %i  ", alto);
		}
		for(ancho = 0; ancho <= 29; ancho = ancho + 1) {
			printf("%c", laberinto[(alto * 30) + ancho]); //imprimir el laberinto
			if(laberinto[(alto * 30) + ancho] == 32 && ancho == 29)
			printf("=> Salida");
		}
		printf("\n");
	}
	return;
}//fin definicion imprimir_array
