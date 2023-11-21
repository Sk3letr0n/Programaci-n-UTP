#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vendedores{
	int codigo;
	char nombre[52];
}est;
int main(){
	FILE *fp = NULL;
	est vendedor;
	int i = 0;
	fp = fopen("vendedores", "rb");
	
	for(i; i < 4; i = i + 1){
		fread(&vendedor.codigo, 4, 1, fp);
		fread(&vendedor.nombre, 52, 1, fp);
		
		printf("%i ", vendedor.codigo);
		printf("%s", vendedor.nombre);
		printf("\n");
	}
	return 0;
}

