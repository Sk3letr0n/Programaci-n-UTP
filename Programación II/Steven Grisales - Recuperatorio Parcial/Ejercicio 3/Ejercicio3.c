/*
Fecha de publicaci�n: 2/10/2022
Hora: 3:15 p.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 5.11
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Salvedad: Si separa los terminos del polinomio no se aseguran los resultados (ejemplo: 2x2 + 3x5 + 5), adem�s, se sabe que no puede tener un coeficiente 0
Descripcion: esta funcion descompene un polinomio en coeficientes y exponentes y los imprime.
*/

#include <stdio.h>

void poli(char[]);

//Esta funcion descompene un polinomio en coeficientes y exponentes y los imprime.
int main() {
	char polinomio[100]; 
    printf("Ingrese un polinomio:");
    scanf("%s", polinomio);
    printf("Coeficiente     Exponente\n");
    poli(polinomio);

    return 0;
}

void poli(char polinomio[100]) {
    int cont = 0,expo = 0,coe = 0,x = 0; //Posici�n del string, Exponente, Coeficiente, Valor de x
    
    while(polinomio[cont] != 00) {
    	
        if(polinomio[cont] =='X' || polinomio[cont] == 'x') {
        	
            if (polinomio[cont-1] == '-' || polinomio[cont-1] == '+') {
                coe = 1;
            }
            if(coe == 0) {
            	coe = 1;
            }
            x = 1;
        }
        else if(polinomio[cont] == '+') {
            
            if(x == 1 && expo == 0) {
                expo = 1;
                printf("%i\t\t   %i\n", coe, expo);
                coe = 0;expo = 0;x = 0;
            }
            else if(coe == 0);
            else {
                printf("%i\t\t   %i\n", coe, expo);
                coe = 0;expo = 0;x = 0;
			}
        }
        else if(polinomio[cont] == '-') {
            if(x == 1 && expo == 0) {
                expo = 1;
                printf("%i\t\t   %i\n-", coe, expo);
                coe = 0;expo = 0;x = 0;
            }
            else if(polinomio[cont-1] == '(') {
            	expo = 0;
            }
            else if(coe == 0) {
                printf("-");
            }
            else {
                printf("%i\t\t   %i\n-", coe, expo);
                coe = 0;expo = 0;x = 0;
            }
        }
        else if(polinomio[cont] == ')') {
        	printf("%i\t\t   -%i\n", coe, expo);
        	coe = 0;expo = 0;x = 0;
        }
        	
        else {
            if(x == 1) {
                expo = (expo*10) + (polinomio[cont]- 48);
            }
            else {
                coe = (coe*10) + (polinomio[cont]- 48);
            }
        }
    	if(polinomio[cont+1] == 00) {
        	if(expo == 0 && x == 1)
           		expo = 1;
        	if(polinomio[cont] != ')')
        		printf("%i\t\t   %i", coe, expo);
    	}
    cont = cont + 1;
    }
}
