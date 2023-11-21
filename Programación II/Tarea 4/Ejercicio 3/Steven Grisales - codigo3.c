/*
Fecha de publicación: 11/09/2022
Hora: 2:35 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa lee desde el teclado un número entero y lo imprime al revés.
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
