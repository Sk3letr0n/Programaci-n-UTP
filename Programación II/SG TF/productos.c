#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct productos{
	int codigo;
	char nombre[104];
}est;
int main(){
	est producto;
	FILE *fp = fopen("productos", "rb");
	int i = 0;
	for(i = 0; i < 9; i = i + 1){
		fseek(fp, i*108, SEEK_SET);
		fread(&producto, 108, 1, fp);
		printf("%i  %s", producto.codigo, producto.nombre);
		printf("\n");
	}

	return 0;
}