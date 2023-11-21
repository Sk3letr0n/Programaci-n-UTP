/* 
Hecho por Steven Grisales López - 1034289634.
Fecha: 1/03/2023.
Punto 2. Casos de sumas secuenciales de complejidad computacional.
*/ 

// Salvedad:El caso 3 solo funciona con valores a los cuales se les pueda aplicar notación cientifica.
#include <stdio.h>

int main() {
	int op; // Esta variable es la opción del switch el cual solo lo usamos para estética y organizar cada caso.

	printf("1) CASO 1.\n2) CASO 2.\n3) CASO 3.\nEliga una opcion: ");
	scanf("%i", &op);

	switch (op){

        /* 1. Dados dos numeros naturales x y y. 
        2. Tomar x y sumarlo a sı mismo y − 1 veces.
        3. Retornar el numero obtenido. */
		case 1:{
			int i, x, y, r = 0; // i es un iterador que cuenta las veces que se suma un valor, x es el num1, y es el num2, r es el resultado de la operación de x sumado y - 1 veces.

			printf("Ingrese el primer numero: ");
			scanf("%i", &x);
            printf("Ingrese el segundo numero: ");
			scanf("%i", &y);

			for(i = 0; i < y; i++) {
				r = r + x;
			}
			printf("\nEl resultado de %i * %i es igual a: %i", x, y, r);
			break;
		}

        /* 1. Dados dos numeros naturales x y y.
        2. Reconocer cual de los dos numeros es mayor.
        3. Tomar el numero mayor y sumarlo a sı mismo un numero de veces igual al numero menor menos una unidad.
        4. Retornar el numero obtenido. */
		case 2:{
			int i, x, y, temp, r = 0; // i es un iterador que cuenta las veces que se suma un valor, x es el num1, y es el num2, r es el resultado de la operación y
            // temp es un valor que ayuda a saber que numero es mayor y cual es menor.

			printf("Ingrese el primer numero: ");
			scanf("%i", &x);
            printf("Ingrese el segundo numero: ");
			scanf("%i", &y); 

			if(x < y){
				temp = x;
				x = y;
				y = temp;
			}
			for(i = 0; i < y; i++){
				r = r + x;
			}
			printf("\nEl resultado de %i * %i es igual a: %i", x, y, r);
			break;
		}

        /* 1. Dados dos numeros naturales x y y expresados de la manera: x = A × 10B y y = C × 10D donde al menos A y C son numeros naturales.
        2. Reconocer cual de los dos numeros A o C es mayor.
        3. Tomar el numero mayor y sumarlo a sı mismo un numero de veces igual al numero menor menos una unidad. A este nuevo numero lo llamaremos S.
        4. Sumar los numeros B y D, a este nuevo numero lo llamaremos E.
        5. Retornar el numero S × 10E */
		case 3:{
			int i, e1 = 0, e2 = 0, e, x, y, temp1, temp2, temp, s = 0; 
            /* i es un iterador que cuenta las veces que se suma un valor
            x es el num1
            y es el num2
            e1 es el exponente de x(B) 
            e2 es el exponente de y(D) 
            e es el valor del exponente final(E)
            temp1 es el valor de x que cambia(A)
            temp2 es el valor de y que cambia(C)
            temp es un valor temporal que permite modificar momentaneamente a temp1 y temp2
            s es el valor final expresado antes del x10 (S) */

			printf("Ingrese el primer numero: ");
			scanf("%i", &x);
            printf("Ingrese el segundo numero: ");
			scanf("%i", &y); 

			temp1 = x;
			temp2 = y;
			for(i = 0; temp1 >= 10; i++){
				if(temp1 % 10 == 0){
					temp1 = temp1 / 10;
				}
			}
			e1 = i;

			for(i = 0; temp2 >= 10; i++) {
				if(temp2 % 10 == 0) {
					temp2 = temp2 / 10;
				}
			}
			e2 = i;

			if(temp1 < temp2) {
				temp = temp1;
				temp1 = temp2;
				temp2 = temp;
			}

			printf("\nNumero 1: %i x10^ %i", temp1, e1);
			printf("\nNumero 2: %i x10^ %i", temp2, e2);

			for(i = 0; i < temp2; i++) {
				s = s + temp1;
			};
			e = e1 + e2;

			printf("\nEl resultado es: %d x 10^%d", s, e);
			break;
		}
		default:{
			printf("\nEsta opcion no existe");
			break;
		}	
	}
}