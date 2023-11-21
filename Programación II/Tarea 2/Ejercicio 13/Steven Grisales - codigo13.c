/*
Fecha de publicaci�n: 25/08/2022
Hora: 7:17 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa calcula la cantidad de calorias de una persona de 70kg enferma en dos estados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int t = 0; //Esta variable guardara el dato insertado por teclado, en este caso el tiempo.
	float cal = 0.0; //Esta variable guardara el dato insertado por teclado, en este caso las calorias.
	char act[20]; //Este vector guardara el dato insertado por teclado, en este caso la act.
	char d[] = {'d', 'o', 'r', 'm', 'i', 'r', '\0'}; //La usar� m�s tarde para definirla en el string como dormir
	char sr[] = {'r', 'e', 'p', 'o', 's', 'o', '\0'}; //La usar� m�s tarde para definirla en el string como sentarse en reposo
	
	printf("Este programa calcula la cantidad de calor%cas que quema una persona enferma de 70kg durante todo el tiempo que realice una misma actividad (dormido [1.08cal], sentado[1.66cal]).", 161);
	
	printf("\nSalvedad: Si ingresa unos datos diferentes a los especificados, no garantizamos el resultado.\n");
	
	printf("\nIngrese el tipo de actividad, [dormir] o [reposo]: ");
	
	scanf("%s", &act); //Lee el dato insertado a la variable.
	
	printf("Ingrese el tiempo total en el que realizo esta actividad [min]: ");
	
	scanf("%i", &t);
		
	if (strcmp (act, d) == 0) //Inicio de la sentencia if junto con su argumentador.
	{
		cal = 1.08 * t;
		printf("Ha quemado %0.1f calorias.\n\n", cal);
	}
	else //Inicio de la sentencia else en caso de if ser falso.
	if (strcmp (act, sr) == 0){
		cal = 1.66 * t;
		printf("Ha quemado %0.1f calorias.\n\n", cal); 
	}
	else
	{
		printf("");
	}	
	//Finalizaci�n del condicional.
	
	system("pause");	
	return 0;	
}
