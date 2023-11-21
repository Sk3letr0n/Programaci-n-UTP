/*
Fecha de publicación: 26/08/2022
Hora: 8:20 a.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa calcula el IMC del usuario y le da un diagnóstico dependiendo del resultado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (){
	float p = 0.0; //Esta variable guardara el dato insertado por teclado, en este caso el peso en kg.
	float a = 0.0; //Esta variable guardara el dato insertado por teclado, en este caso la altura en m.
	float IMC = 0.0; //Esta variable guardara el IMC.
	
	printf("Este programa lee la altura y peso del usuario y calcula el IMC del usuario para darle un diagn%cstico. La tabla para dar el diagn%cstico es: ", 162, 162);
	
	printf("\n< 16: Criterio de ingreso en hospital.\n >= 16 && < 17: infrapeso.\n >= 17 && < 18: bajo peso.\n >= 18 && < 25: peso normal (saludable).\n >= 25 && < 30: sobrepeso(obesidad grado I).\n >= 30 && < 35: sobrepeso cr%cnico(obesidad grado II).\n >= 35 && < 40: obesidad prem%crbida(obesidad grado III).\n >= 40: obesidad m%crbida(obesidad grado IV).", 162, 162, 162);
	
	printf("\n\nIngrese su peso en kg: ");
	
	scanf("%f", &p); //Lee el dato insertado a la variable.
	
	printf("Ingrese su altura en m: ");
	
	scanf("%f", &a); //Lee el dato insertado a la variable.
	
	IMC = p / (pow(a, 2));
	
	if(IMC < 16){ //Inicio de la sentencia if junto con su argumentador.
		printf("Criterio de ingreso en hospital.\n\n");
	} else { //Inicio de la sentencia else en caso de if ser falso.
		if(IMC >= 16 && IMC < 17){
			printf("Infrapeso.\n\n");
		} else {
			if(IMC >= 17 && IMC < 18){
				printf("Bajo peso.\n\n");
			} else {
				if(IMC >= 18 && IMC < 25){
					printf("Peso normal (saludable).\n\n");
				} else {
					if(IMC >= 25 && IMC < 30){
						printf("Sobrepeso (obesidad de grado I).\n\n");
					} else {
						if(IMC >= 30 && IMC < 35){
							printf("Sobrepeso cr%cnico(obesidad de grado II).\n\n", 162);
						} else {
							if(IMC >= 35 && IMC < 40){
								printf("Obesidad prem%crbida (obesidad de grado III).\n\n", 162);
							} else {
								if(IMC >= 40){
									printf("Obesidad m%crbida (obesidad de grado IV).\n\n", 162);
								} else {
									printf("\n");
								}
							}	
						}
					}
				}
			}
		}
	}
	//Finalización del condicional.
		
	system("pause");
	return 0;
}
