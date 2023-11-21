#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct clientes{
	int codigo;
	char nombre[52];
}est;
int main(){
	FILE *fp = NULL;
	est cliente;
	int i = 0;
	fp = fopen("clientes", "rb");
	
	for(i; i < 5; i = i + 1){
		fread(&cliente.codigo, 4, 1, fp);
		fread(&cliente.nombre, 52, 1, fp);
		
		printf("%i ", cliente.codigo);
		printf("%s", cliente.nombre);
		printf("\n");
	}
	return 0;
}