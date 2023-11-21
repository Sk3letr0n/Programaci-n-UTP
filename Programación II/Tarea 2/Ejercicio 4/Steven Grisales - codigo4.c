/*
Fecha de publicaci�n: 24/08/2022
Hora: 12:15 a.m.
Versi�n del c�digo: 1.0
Autor: Ing(c) Steven Grisales L�pez. 
Lenguaje C (ISO/IEC)
Versi�n del lenguaje: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Este programa lee un n�mero e imprime el mes del a�o al que corresponde ese n�mero.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int n = 0; //Esta variable guardara el dato insertado por teclado, en este caso el n�mero.
	
	printf("Este programa, lee un n%cmero entre [1 y 12] e imprime el mes que le corresponde en el a%co.\nReferencia: 1=Enero. 12=Diciembre", 163, 164);
	
	printf("\nSalvedad: Para valores fuera de este rango (1, 12), no garantizamos el resultado del mes.");
	
	printf("\n\nEntre un n%cmero: ", 163);
	
	scanf("%i", &n); //Lee el dato insertado a la variable.
	
	if (n == 1) //Inicio de la sentencia if junto con su argumentador.
	{
		printf("El mes es Enero \n\n");
	}
	else //Inicio de la sentencia else en caso de if ser falso.
	{
		if (n == 2)
		{
			printf("El mes es Febrero\n\n"); 
		}
		else
		{
			if (n == 3)
			{
				printf("El mes es Marzo\n\n"); 
			}
			else
			{
				if (n == 4)
				{
				printf("El mes es Abril\n\n");	
				}
				else
				{
					if (n == 5)
					{
						printf("El mes es Mayo\n\n");
					}
					else
					{
						if (n == 6)
						{
							printf("El mes es Junio\n\n", 160);
						}
						else
						{
							if (n == 7)
							{
								printf("El mes es Julio\n\n");
							}
							else
							{	
								if (n == 8)
								{
									printf("El mes es Agosto\n\n");
								}
								else
								{
									if (n == 9)
									{	
										printf("El mes es Septiembre\n\n");
									}
									else
									{	
										if (n == 10)
										{
											printf("El mes es Octubre\n\n");
										}
										else
										{	
											if (n == 11)
											{
												printf("El mes es Noviembre\n\n");
											}
											else
											{			
												if (n == 12)
												{	
													printf("El mes es Diciembre\n\n");
												}
												else
												{
													printf("Se sale del rango especificado\n\n");
												}
											}
										}
									}	
								}
							}
						}
					}
				}
			}	
		}
	}		
	//Finalizaci�n del condicional.
	system("pause");	
	return 0;	
}
