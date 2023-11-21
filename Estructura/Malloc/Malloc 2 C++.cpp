#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main(){
	int op;
	cout << "Ingrese la opcion que desea ver ";
	cin >> op;
	switch (op){//****************************************************************************
		case 1:{
			float *V, *ptr;
			int N, i;
			cout << "Numero de valores: ";
			cin >> N;
			if (( V = (float *) malloc( N*sizeof( float )) ) == NULL ){
				cout << "No hay suficiente memoria. \n";
			} else {
				for(i = 0, ptr = V; i < N; i++, ptr++){
					cout << "Valor >> ";
					scanf("%f",ptr);
				}
			}
			for(i = 0, ptr = V; i < N; i++, ptr++){
				printf("\nValor %d >> %f", i, *ptr);
				free(V);
			}
			return 0;
			break;
		}//****************************************************************************
		case 2:{
			float *V = NULL;
			int N = 0, i;
			char c;
			do{
				V = (float *)realloc((float *)V, (N+1)*sizeof(float));
				printf("\nDame valor >> ");
				scanf("%f", &V[N]);
				printf("Quieres introducir otro valor? (S/N) >> ");
				c = getch();
				N++;
			} while (c =='s' || c == 'S');
			for(i = 0; i < N; i++){
				printf("\nValor %d >> %f\n", i, V[i]);				
			}
			free(V);
			return 0;
			break;
		}
	}
	
}
