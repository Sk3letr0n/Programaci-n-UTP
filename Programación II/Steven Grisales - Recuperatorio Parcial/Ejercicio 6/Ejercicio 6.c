/*
Fecha de publicación: 2/10/2022
Hora: 4:00 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 5.11
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Salvedad: Lo solicitado por el cliente, no es una regla gramatical para todas las palabras del idioma ingles.
Definir la función “plural”, que toma una cadena de caracteres y devuelve otra cadena. Si la cadena dada termina en
“y” ó “Y”, el resultado debe ser la misma cadena entrada, pero con la “y” ó “Y” sustituido por “ies” ó “IES”. De
lo contrario, el resultado debe ser la misma cadena entrada con una “s” al final.
*/

#include <stdio.h>
#include <string.h>

char fcomprobarl(int, char[]);
int fcomprobarc(int, char[]);
void plural(int, char, char[], char[], char[], char[], char[]);

int main(){
	int longv = 0; //Guarda la longitud de la cadena
	int caso = 0; //Guarda el caso que se va a utilizar para modificar la cadena
	char palabra[50]; //Guarda la palabra digitada por el usuario
	char letra = '?'; //Nos sirve para saber si la palabra en mayuscula o minuscula
	char c1m[4] = "ies"; //Lo que se va a imprimir al final si la palabra termina en 'y'
	char c1M[4] = "IES"; //Lo que se va a imprimir al final si la palabra termina en 'Y'
	char c2m[2] = "s"; //Lo que se va a imprimir al final si la palabra no termina en 'y' y es minuscula
	char c2M[2] = "S"; //Lo que se va a imprimir al final si la palabra no termina en 'Y' y es mayuscula
	
	printf("Por favor digite una palabra: ");
	scanf("%s", palabra);
	
	longv = strlen(palabra);
	
	letra = fcomprobarl(longv, palabra);
	caso = fcomprobarc(longv, palabra);
	plural(caso, letra, palabra, c1m, c1M, c2m, c2M);
	
	printf("\n%s", palabra);
	
	return 0;
}

char fcomprobarl(int longv, char palabra[]){
	char letra = '?'; //Nos sirve para saber si la palabra en mayuscula o minuscula
	char i = 0; //Es un iterador que va desde el codigo ASCII de a hasta el de z
	
	for(i = 97; i <= 122; i = i + 1){
		if(palabra[longv - 1] == i){
			letra = 'm';
		}
	}
	//i es un iterador que va desde el codigo ASCII de A hasta el de Z
	for(i = 65; i <= 90; i = i + 1){
		if(palabra[longv - 1] == i){
			letra = 'M';
		}
	}
	return letra;
}

int fcomprobarc(int longv, char palabra[]){
	int caso = 0; //Guarda el caso que se va a utilizar para modificar la cadena
	
	if(palabra[longv - 1] == 'y' || palabra[longv - 1] == 'Y'){
		caso = 1;
		palabra[longv - 1] = 0;
	} else {
		caso = 2;
	}
	return caso;
}

void plural(int caso, char letra, char palabra[], char c1m[], char c1M[], char c2m[], char c2M[]){
	if(caso == 1 && letra == 'm'){
		strcat(palabra, c1m);
	}
	if(caso == 1 && letra == 'M'){
		strcat(palabra, c1M);
	}
	if(caso == 2 && letra == 'm'){
		strcat(palabra, c2m);
	}
	if(caso == 2 && letra == 'M'){
		strcat(palabra, c2M);
	}
	return;
}
