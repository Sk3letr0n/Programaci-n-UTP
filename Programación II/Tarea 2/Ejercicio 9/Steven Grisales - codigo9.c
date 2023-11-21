/*
Fecha de publicaci�n: 25/08/2022
Hora: 5:22 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa lee el inter�s y el capital inicial del usuario e indica si debe invertir
o no seg�n si los intereses exceden $7000.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	float i = 0; //Esta variable guardara el dato insertado por teclado, en este caso los intereses.
	float ci = 0; //Esta variable guardara el dato insertado por teclado, en este caso el capital inicial.
	float s = 0; //Esta variable guardara el dato insertado por teclado, en este caso el saldo a invertir.
	
	printf("Este programa lee dos valores. Inter%cs(%) y Capital. Si el dinero recibido por intereses es mayor que $7000, se le indicara al inversionista que invierta, de lo contrario se le indicara que no debe invertir\n", 130);
	
	printf("\nEntre el Inter%cs en %: ", 130);
	
	scanf("%f", &i); //Lee el dato insertado a la variable.
	
	printf("Entre el Capital a invertir $: ");
	
	scanf("%f", &ci); //Lee el dato insertado a la variable.
	
	i = ci * (i / 100.0);
	s = ci + i;
		
	if (s > 7000) //Inicio de la sentencia if junto con su argumentador.
	{
		printf("INVIERTA, SU SALDO SER%c: %0.0f\n\n", 181, s);
	}
	else //Inicio de la sentencia else en caso de if ser falso.
	{
		printf("NO INVIERTA\n\n"); 
	}	
	//Finalizaci�n del condicional.
	
	system("pause");	
	return 0;	
}
