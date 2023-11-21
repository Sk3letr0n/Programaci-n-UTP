/*
Fecha de publicación: 2/10/2022
Hora: 3:30 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 5.11
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Descripcion: Esta programa reemplaza un string de 60x30 con . y o's y determina si tiene cuadrados entre las o's
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void imprimir_cuadros(int, int, int, int , char[]);
void imprimir_array(char[]);
void rellenar_array(char[]);
int cuadrados(int, int, char[]);
int localizar_cuadrado(int, int, char[]);

// Esta llama a las otras funciones.
int main() {
	srand(time(NULL));
    char cuadros [1801];
    rellenar_array(cuadros);
    imprimir_array(cuadros);
    printf("\n\n");
    cuadrados(0, 0, cuadros);

    return 0;
}

// Esta funcion rellena un string aleatoriamente con "." o "o"
void rellenar_array(char cuadros[]) {
    int alto = 29; //Filas del arreglo
    int ancho = 0; //Columnas del arreglo
    for(alto; alto >= 0; alto = alto - 1) {
        for(ancho = 59; ancho >= 0; ancho = ancho - 1) {
            cuadros[(alto * 60) + ancho] = 46;
            if(rand() % 30 == 0) {
                cuadros[(alto * 60) + ancho] = 111;
            }
            else {
                cuadros[(alto * 60) + ancho] = 46;
            }
        }
    }
    cuadros[1801] = 0; //Cierre de la cadena (no es necesario cerrarla)
    return;
}

// Esta funcion imprime un string en forma de 30x60.
void imprimir_array(char cuadros[]) {
    int alto = 0; //Filas del arreglo
    int ancho = 0; //Columnas del arreglo
    for(alto; alto <= 29; alto = alto + 1) {
        for(ancho = 0; ancho <= 59; ancho = ancho + 1) {
            printf("%c", cuadros[(alto * 60) + ancho]);
        }
        printf("\n");
    }
    return;
}

// Esta funcion detecta las "o"
int cuadrados(int alto, int ancho, char cuadros []) {
    int si = 0; //Comprueba si las o forman un cuadrado
    int n = 0; 
    int minimo = 100000; 
    
    for(alto; alto <= 29; alto = alto + 1) {
        for(ancho = 0; ancho <= 59; ancho = ancho + 1) {
            if(cuadros[(alto * 60) + ancho] == 111) {
                si = localizar_cuadrado(ancho, alto + 1, cuadros);
                if(si != 0) {
                    n = n + 1;
                    if(minimo > si)
                        minimo = si;
                } 
            }
        }
    }
    if(n == 0)
        minimo = 0;
    imprimir_array(cuadros);
    if(n == 0)
        printf("No se encontraron cuadrados");
    else
    	printf("Para este ejemplo, tenemos %i. El area del mas pequeno es: %i", n, minimo);
}

// Esta funcion comprueba si las "o" forman un cuadrado, sde arreglo en que los cuadrados se generaban fuera de cuadrado y se arreglo la devolucion del area.
int localizar_cuadrado(int ancho, int alto, char cuadro[]) {
    int ancho_0 = ancho; //Columnas del cuadrado
    int alto_0 = alto; //Filas del cuadrado
    for(alto; cuadro[(alto * 60) + ancho] != 111 && alto <= 30; alto = alto + 1);
        ancho = ancho + 1;
        for(ancho; cuadro[(alto * 60) + ancho] != 111 && ancho < 60; ancho = ancho + 1);
        	if(cuadro[((alto_0 - 1) * 60) + ancho] == 111 && ancho != 60)
        	{
                imprimir_cuadros(ancho_0, alto_0, ancho, alto, cuadro);
                return (alto - alto_0 + 2) * (ancho - ancho_0 + 1);
        	}
    return 0;
}

// Esta funcion reemplaza los caracteres * por X.
void imprimir_cuadros(int x, int y, int maximo_x, int maximo_y, char cuadro []){
    int y_0 = y - 1;
    for(x; x < maximo_x + 1 && x < 60; x = x + 1){
        for(y = y_0; y < maximo_y + 1 && y < 30; y = y + 1){
            if(cuadro[(y * 60) + x] != 111)
                cuadro[(y * 60) + x] = 88;
        }
	}
    return;
}
