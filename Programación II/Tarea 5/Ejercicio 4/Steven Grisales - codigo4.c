/*
Fecha de publicaci�n: 16/09/2022
Hora: 5:17 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa lee desde el teclado un grupo de 75 n�meros, de diferentes a cero(validar este requisito) y al final de le�dos, imprima:
* Cantidad de n�meros Mayores a 150
* N�mero mayor y n�mero menor encontrado en el grupo
* Cantidad de N�meros negativos encontrados
* Promedio de los Positivos Encontrados.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int i = 1; //Es un iterador que utilizamos para saber cuando llegamos al ultimo n�mero
    int n = 0; //Esta variable guadar� el n�mero insertado por el usuario
	int m150 = 0; //Esta variable guardar� la cantidad de n�meros mayores a 150
	int me = 1000000000; // Esta variable guardar� el n�mero menor de todos
	int ma = 0; //Esta variable guardar� el n�mero mayor de todos
	int cn = 0; //Esta variable guardar� la cantidad de n�meros negativos que se hayan encontrado
	float sp = 0; //Esta variable guardar� la suma de los positivos que se hayan encontrado
	float cp = 0; //Esta variable guardar� la cantidad de n�meros positivos que se hayan encontrado
	
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
