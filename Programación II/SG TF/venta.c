#include <stdio.h>
#include <stdlib.h>

typedef struct ventas{
	int numero;
	int price;
	char nombre[6];
	float n2;
}est;

int main(){
	FILE *fp = NULL;
	est venta;	
	int i = 0;
	fp = fopen("ventas", "rb");

	for(i = 0; i <= 6; i = i + 1){
		fread(&venta.numero, 4, 1, fp);
		fread(&venta.price, 4, 1, fp);
		fread(&venta.nombre, 6, 1, fp);
		fread(&venta.n2, 4, 1, fp);

		printf("%i ", venta.numero);
		printf("%i ", venta.price);
		printf("%s ", venta.nombre);
		printf("%0.2f ", venta.n2);
		printf("\n");
	}
	return 0;
}
