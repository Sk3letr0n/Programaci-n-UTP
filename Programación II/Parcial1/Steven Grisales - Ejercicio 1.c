/*
Fecha de publicación: 6/10/2022
Hora: 9:15 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 5.11
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

1.- Genere un arreglo de tipo float bidimensional de 8 x 8 - con números aleatorios entre 0.0 y 15.0 con un decimal
e imprimirlo en pantalla de forma ordenada.
2.- Moda: El valor que más se repite en el arreglo e indique cuantas veces esta.
3.- El promedio(a un decimal) de cada fila y de cada columna.
4.- La (suma de la diagonal superior menos (-) la suma de la inferior) / promedio(a un decimal) del arreglo.
e.- Calcule e imprima en forma ordenada, un arreglo que contenga los factoriales de la parte entera de todos los
valores generados en el enciso a.
5.- Indique cuantas veces se encuentra el promedio.
6.- El promedio de los valores más altos de cada fila y cada columna.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rellenar_char(float cuadro[][8]);
void imprimir_char(float cuadro[][8]);
void evaluar_char(float cuadro[][8]);
void moda(float cuadro[][8]);
void mitades(float cuadro[][8]);
void promedio(float cuadro[][8]);
void vprom(float cuadro[][8]);
int existe(float numero[64][2], float num);
void valtprom(float cuadro[][8]);

int main() {
	srand(time(NULL));
	float cuadro[8][8];
	rellenar_char(cuadro);
	imprimir_char(cuadro);
	moda(cuadro);
	promedio(cuadro);
	mitades(cuadro);
	vprom(cuadro);
	valtprom(cuadro);
	
	return 0;
}

// Esta función rellena el arreglo
void rellenar_char(float cuadro[][8]) {
	int fl = 0; // Es las filas del arreglo
	int cl = 0; // Es las columnas del arreglo
	for(fl = 0; fl <= 7; fl = fl + 1) {
		for(cl = 0; cl <= 7; cl = cl + 1) {
			cuadro[fl][cl] = ((rand() % 151) / 10.0); // 150 / 10 = 15.0
		}
	}
	
	return;
}

// Esta función imprime el arreglo
void imprimir_char(float cuadro[][8]) {
	int fl = 0; // Esta variable va a ser las filas del arreglo
	int cl = 0; // Esta variable va a ser las columnas del arreglo
	for(fl = 0; fl <= 7; fl = fl + 1) {
		for(cl = 0; cl <= 7; cl = cl + 1) {
			printf(" %0.1f\t ", cuadro[fl][cl]);
		}
		printf("\n");
	}
	
	return;
}

// Esta función determina las modas del arreglo
void moda(float cuadro[][8]){
	printf("\n");
	int fl = 0; // Es las filas del arreglo
	int cl = 0; // Es las columnas del arreglo
	float mod1 = 0; // Guarda la moda mayor
	float numero[64][2]; // Guarda la moda de cada numero
	int posicion = 0, pc2 = 0; // Aumenta con cada numero diferente
	
	/*
	* Estos for recorren la matrix preguntan si el numero ya esta en el arreglo "numero"
	* Si se encuentra en el arreglo, le suma una unidad
	* si no lo encuentra, reserva un espacio para el numero nuevo
	*/
	for(fl = 0; fl <= 7; fl = fl + 1) {	
		for(cl = 0; cl <= 7; cl = cl + 1) {
			int salida = existe(numero, cuadro[cl][fl]);
			if(salida != 100) {
				numero[salida][1] = numero[salida][1] + 1;
			}else{
				numero[posicion][0] = cuadro[cl][fl];
				numero[posicion][1] = 1;
				posicion = posicion + 1;
			} 
		}
	}
	
	// Este For me ayuda a identificar cual es la moda mas grande 
	fl = 0;
	for(fl = 0; fl <= 64; fl = fl + 1) {
		if(numero[fl][1] > mod1){
			mod1 = numero[fl][1];
		}
	}
	
	// Este for imprime Los numero que tengan la moda mas alta
	fl = 0;
	for(fl = 0; fl <= 64; fl = fl + 1) {
		if(numero[fl][1] == mod1){
			printf("Moda (%0.1f) esta %0.0f veces. ", numero[fl][0], mod1);
			mod1 = numero[fl][1];
		}
	}
	printf("\n\n");
	return;
}

// Esta función determina el promedio de cada una de las filas y columnas por separado
void promedio(float cuadro[][8]) {
    int fl = 0; // Es las filas del arreglo
    int cl = 0; // Es las columnas del arreglo
    float x = 0; // Guarda el promedio de las filas y columnas por separado
    for(fl = 0; fl <= 7; fl = fl + 1) {
        for(cl = 0; cl <= 7; cl = cl + 1)
            x = x + cuadro[fl][cl]; 
        printf("El promedio de la fila %i es: %0.1f\n", fl + 1, x / 8);
        x = 0;
    }
    printf("\n");

    for(cl = 0; cl <= 7; cl = cl + 1) {
        for(fl = 0; fl <= 7; fl = fl + 1)
            x = x + cuadro[fl][cl]; 
        printf("El promedio de la columna %i es: %0.1f\n", cl + 1, x / 8);
        x = 0;
    }
    
    printf("\n");
    return;
}

/*
* Método recibe el arreglo [64][2] y un "num" a verificar
* Si el num se encuentra dentro del arreglo, devuelve la posicion donde esta
* Si no lo encuentra, devuelve un 100
*/
int existe(float numero[64][2], float num){
	int fl = 0;
	for(fl = 0; fl <= 64; fl = fl + 1) {	
		if(numero[fl][0] == num){
			return fl;
		}
	}
	return 100;
}

// Esta función realiza la resta de las dos diagonales del arreglo y luego las divide por el promedio
void mitades(float cuadro[][8]) {
    int fl = 0; // Es las filas del arreglo
    int cl = 0; // Es columnas del arreglo
    float total = 0; // Es el resultado final de la operación
    float su1 = 0, su2=0; // Guarda la suma de la mitad superior y su2 la mitad inferior
    float x = 0; // Guarda la suma del promedio de las filas y columnas
    for(fl = 0; fl <= 7; fl = fl + 1) {
        for(cl = 0; cl <= 7; cl = cl + 1) {
            x = x + cuadro[fl][cl];
        }
    }
    x = x / 64;

    for(fl = 0; fl <= 7; fl = fl + 1) {
        for(cl = fl; cl <= 7; cl = cl + 1) {
            su1 = su1 + cuadro[fl][cl];
        }
    }
    for(fl = 0; fl <= 7; fl = fl + 1) {
        for(cl = fl; cl <= 7; cl = cl + 1) {
            su2 = su2 + cuadro[cl][fl];
        }
    }
    total = (su1 - su2) / x;

    printf("La suma de la diagonal superior (%0.1f) menos(-) la suma de la diagonal inferior (%0.1f) / el promedio del arreglo (%0.1f) es: %0.1f", su1, su2, x, total);
    
    return;
}

// Esta función determina si el promedio del arreglo se encuentra x veces en el mismo arreglo
void vprom(float cuadro[][8]) {
	int fl = 0; // Es las filas del arreglo
	int cl = 0; // Es las columnas del arreglo
	float x = 0; // Guarda la el promedio de las filas y columnas
	float cont = 0; // Guarda la cantidad de veces que aparece x en el arreglo
	for(fl = 0; fl <= 7; fl = fl + 1) {
		for(cl = 0; cl <= 7; cl = cl + 1) {
			x = x + cuadro[fl][cl];
		}
	}
	x = x / 64;
	for(fl = 0; fl <= 7; fl = fl + 1) {
		for(cl = 0; cl <= 7; cl = cl + 1) {
			if(x == cuadro[fl][cl]){
				cont = cont + 1;
			}
		}
	}
	if(cont > 0){
        printf("\nEl valor promedio de todos los datos que es: %0.1f, se encuentra %i veces en el arreglo", x, cont);
    } else {
        printf("\nEl valor promedio de todos los datos que es: %0.1f, no se encuentra en el arreglo", x);
	}
	return;
}

// Esta función determina el promedio de los valores máximos de cada fila y el promedio de los valores máximos de cada columna
void valtprom(float cuadro[][8]){
	int fl = 0; // Es las filas del arreglo
    int cl = 0; // Es las columnas del arreglo
    float x = 0; // Guarda el promedio del valor más alto de cada fila y columna por separado
    float maf = 1; // Guarda el valor más alto de cada fila
    float mac = 1; // Guarda el valor más alto de cada columna
    for(fl = 0; fl <= 7; fl = fl + 1) {
        for(cl = 0; cl <= 7; cl = cl + 1){
        	if(maf > cuadro[fl][cl]){
        		maf = cuadro[fl][cl];
        		maf = maf + cuadro[fl][cl];
			}
            x = maf + cuadro[fl][cl]; 
		}
    }
    printf("\nEl promedio de los valores mas altos de las filas es: %0.1f", x / 8);
    x = 0;
  
    for(cl = 0; cl <= 7; cl = cl + 1) {
        for(fl = 0; fl <= 7; fl = fl + 1){
			if(mac < cuadro[fl][cl]){
				mac = cuadro[fl][cl];
				mac = mac + cuadro[fl][cl];
			}
            x = mac + cuadro[fl][cl];
		} 
    }
    printf("\nEl promedio de los valores mas altos de las columnas es: %0.1f", x / 8);
    x = 0;
    
    return;
}
