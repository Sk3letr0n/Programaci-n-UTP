#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct detallesVentas{
	int codigo;
	char nombre[52];
}est;
int main(){
	FILE *fp = NULL;
	est dv;
	int i = 0;
	fp = fopen("detalleVentas", "rb");
	
	for(i; i < 5; i = i + 1){
		fread(&dv.codigo, 4, 1, fp);
		fread(&dv.nombre, 52, 1, fp);
		
		printf("%i ", dv.codigo);
		printf("%s", dv.nombre);
		printf("\n");
	}
	return 0;
}
