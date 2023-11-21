/*
Fecha de publicaci�n: 11/09/2022
Hora: 2:35 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa lee desde el teclado un n�mero entero y lo imprime al rev�s.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int n = 0; //Esta variable guardara el dato ingresado por el usuario
	
    printf("Este programa lee desde el teclado un n%cmero entero y lo imprime al rev%cs.", 163, 130);
    
    printf("\nEntre un n%cmero: ", 163);
    
    scanf("%i", &n);
                    
	for(; n >= 10;){ 
        printf("%i", n % 10); 
        n = (n - n % 10) /10;  
	}
    printf("%i", n);
	
    printf("\n\n");
    system("pause");
    return 0;
}
