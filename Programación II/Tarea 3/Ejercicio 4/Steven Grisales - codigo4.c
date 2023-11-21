/*
Fecha de publicación: 31/08/2022
Hora: 7:40 p.m.
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
void f(int, int, int, int, int, float, float);

int main(){
    int con = 1; //Esta variable cuenta cuantos números se han digitado
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
    
	f(con, m150, me, ma, cn, sp, cn);
	
	printf("\n\n");
	
	system("pause");
	return 0;
}

void f(int con, int m150, int men, int ma, int cn, float sp, float cp){
	int n = 0; //esta variable guarda el numero digitado por el usuario

	if(con <= 75){
		printf ("Por favor digite un numero: ");
		scanf ("%i", &n);
		if(n == 0){
			printf ("Por favor digite un numero diferente a 0. \n\n");
			f(con, m150, men, ma, cn, sp, cp);
		}	
    	if(n > 150){
			m150 = m150+1;
		}	
		if(n < men){
			men = n;
		}
		if(n > ma){
			ma = n;
		}
		if(n < 0){
			cn = cn+1;
		}
		if(n > 0){
			sp = sp + n;
			cp = cp + 1;
		}
		f(con+1, m150, men, ma, cn, sp, cp);
	}
	else{
	    printf ("\nNumeros mayores a 150: %i", m150);
		printf ("\nNumero menor: %i", men);
		printf ("\nNumero mayor: %i", ma);
		printf  ("\nCantidad de numeros negativos: %i", cn);
		printf ("\nPromedio de los numeros positivos: %0.2f", sp/cp);
	}
	return;
}

