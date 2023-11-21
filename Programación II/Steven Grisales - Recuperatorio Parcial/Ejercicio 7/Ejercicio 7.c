/*
Fecha de publicación: 2/10/2022
Hora: 4:15 p.m.
Versión del código: 1.0
Autor: Ing(c) Steven Grisales López. 
Lenguaje C (ISO/IEC)
Versión del lenguaje: 5.11
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnológica de Pereira
Programa de Ingeniería de Sistemas y Computación
Asignatura IS284 Programación II

Este programa simula el juego del triky
*/

#include <stdio.h>
#include <stdlib.h>

void triki_most(char[]);
void ju1(char[]);
void ju2(char[]);
int ganar_X(char[]);
int ganar_O(char[]);
int evaluar(int, char[]);
void turno (char[]);

void triki_most (char triky[] ){
	int fila=0;
	while(fila<=2)
	{
		if(fila<2)
		{
			int colum=0;
			while(colum<=2)
			{
				if(colum<2)
					printf(" %c %c", triky[(fila*3)+colum], 179);
				else
					printf(" %c ", triky[(fila*3)+colum]);
				colum=colum+1;
			}
			printf("\n");
			printf("%c%c%c%c%c%c%c%c%c%c%c", 45, 45, 45, 43, 45, 45, 45, 43, 45, 45, 45);
			printf("\n");
		}
		else
		{
			int colum=0;
			while(colum<=2)
			{
				if(colum<2)
					printf(" %c %c", triky[(fila*3)+colum], 179);
				else
					printf(" %c ", triky[(fila*3)+colum]);
				colum=colum+1;
			}
			printf("\n");
		}
		fila=fila+1;
	}
	return;
}

int evaluar(int n, char triky[])
{
	int v=0;
	if(triky[n-1]=='X' || triky[n-1]=='O')
	{
		v=0;
	}
	else{
		v=1;
	}
	return v;
}

int ganar_X(char triky[])
{
	int v=0;
	if(triky[0]=='X' && triky[1]=='X' && triky[2]=='X')
	{
		v=1;
	}
	else if(triky[3]=='X' && triky[4]=='X' && triky[5]=='X')
		{
			v=1;
		}
		else if(triky[6]=='X' && triky[7]=='X' && triky[8]=='X')
			{
				v=1;
			}
			else if(triky[0]=='X' && triky[3]=='X' && triky[6]=='X')
				{
					v=1;
				}
				else if(triky[1]=='X' && triky[4]=='X' && triky[7]=='X')
					{
						v=1;
					}
					else if(triky[2]=='X' && triky[5]=='X' && triky[8]=='X')
						{
							v=1;
						}
						else if(triky[0]=='X' && triky[4]=='X' && triky[8]=='X')
							{
								v=1;
							}
							else if(triky[2]=='X' && triky[4]=='X' && triky[6]=='X')
								{
									v=1;
								}
								else{
									v=0;
								}
	return v;
}

int ganar_O(char triky[])
{
	int v=0;
	if(triky[0]=='O' && triky[1]=='O' && triky[2]=='O')
	{
		v=1;
	}
	else if(triky[3]=='O' && triky[4]=='O' && triky[5]=='O')
		{
			v=1;
		}
		else if(triky[6]=='O' && triky[7]=='O' && triky[8]=='O')
			{
				v=1;
			}
			else if(triky[0]=='O' && triky[3]=='O' && triky[6]=='O')
				{
					v=1;
				}
				else if(triky[1]=='O' && triky[4]=='O' && triky[7]=='O')
					{
						v=1;
					}
					else if(triky[2]=='O' && triky[5]=='O' && triky[8]=='O')
						{
							v=1;
						}
						else if(triky[0]=='O' && triky[4]=='O' && triky[8]=='O')
							{
								v=1;
							}
							else if(triky[2]=='O' && triky[4]=='O' && triky[6]=='O')
								{
									v=1;
								}
								else{
									v=0;
								}
	return v;
}

void ju1(char triky[])
{	
	char cond='f';
	while(cond='f')
	{
		int n=0;
		printf("Jugador 1: Entre n%cmero casilla: ", 163);
		scanf("%i", &n);
		
		if(evaluar(n, triky))
		{
			triky[n-1]='X';
			cond='t';
			printf("\n");
			return;
		}
		else{
			printf("esa casilla ya est%c ocupada, ingrese una nuevamente", 160);
			printf("\n");
		}
	}
	
}

void ju2(char triky[])
{	
	char cond='f';
	while(cond='f')
	{
		int n=0;
		printf("Jugador 2: Entre n%cmero casilla: ", 163);
		scanf("%i", &n);
		
		if(evaluar(n, triky))
		{
			triky[n-1]='O';
			cond='t';
			printf("\n");
			return;
		}
		else{
			printf("esa casilla ya est%c ocupada, ingrese una nuevamente", 160);
			printf("\n");
		}
	}
	
}

void turno (char triky[])
{
	int n=0;
	for(n=0; n<=8; n=n+1)
	{
		if(n%2==0)
		{
			ju1(triky);
			if(ganar_X(triky))
			{
				printf("GANA EL JUGADOR 1");
				printf("\n");
				triki_most(triky);
				return;
			}
			triki_most(triky);
		}
		if(n%2!=0)
		{
			ju2(triky);
			if(ganar_O(triky))
			{
				printf("GANA EL JUGADOR 2");
				printf("\n");
				triki_most(triky);
				return;
			}
			triki_most(triky);
		}
	}
	printf("El juego qued%c en empate", 162);
	printf("\n");
	return;
}

int main(){
	char triky[9]="123456789";
	triki_most(triky);
	turno(triky);
	system("pause");
	return 0;
}
