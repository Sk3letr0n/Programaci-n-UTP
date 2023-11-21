/*
Fecha de publicación: 16/09/2022
Hora: 5:17 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa lee desde el teclado un grupo de 75 números, de diferentes a cero(validar este requisito) y al final de leídos, imprima:
* Cantidad de números Mayores a 150
* Número mayor y número menor encontrado en el grupo
* Cantidad de Números negativos encontrados
* Promedio de los Positivos Encontrados.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int i = 1; //Es un iterador que utilizamos para saber cuando llegamos al ultimo número
    int n = 0; //Esta variable guadará el número insertado por el usuario
	int m150 = 0; //Esta variable guardará la cantidad de números mayores a 150
	int me = 1000000000; // Esta variable guardará el número menor de todos
	int ma = 0; //Esta variable guardará el número mayor de todos
	int cn = 0; //Esta variable guardará la cantidad de números negativos que se hayan encontrado
	float sp = 0; //Esta variable guardará la suma de los positivos que se hayan encontrado
	float cp = 0; //Esta variable guardará la cantidad de números positivos que se hayan encontrado
	
	printf ("Este programa lee desde el teclado un grupo de 75 numeros, \ndiferentes a cero y al final de leidos, imprima:");
	printf (" \n\n* Cantidad de numeros Mayores a 150\n");
    printf ("* Numero mayor y numero menor encontrado en el grupo\n");
    printf ("* Cantidad de Numeros negativos encontrados\n");
    printf ("* Promedio de los Positivos Encontrados. \n\n");
    
    while(i <= 75){  
    	
    	printf ("\nPor favor digite el numero %i: ", i); 
    	scanf ("%i", &n);
    	
    	if(n == 0){
    		printf ("Por favor digite un numero diferente a 0\n");
    		i = i - 1;  
		} else {
    		if(n > 150){
				m150 = m150 + 1;
			}	
			if(n < me){ 
				me = n; 
			}	
			if(n > ma){ 
				ma = n;
			}
			if(n < 0){
				cn = cn + 1;
			}
			if(n > 0){
				sp = sp + n;
				cp = cp + 1;
			}	
	    }
		i = i + 1;
	} //Fin del while	
	printf ("\nNumeros mayores a 150: %i", m150);
	printf ("\nNumero menor: %i", me);
	printf ("\nNumero mayor: %i", ma);
	printf  ("\nCantidad de numeros negativos: %i", cn);
	printf ("\nPromedio de los numeros positivos: %0.2f", sp/cp);
		
	printf("\n\n");
	system("pause");
	return 0;
}
