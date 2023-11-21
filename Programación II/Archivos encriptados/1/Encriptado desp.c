#include <stdio.h>
// Desplazamiento +20

int main(){
	FILE *a1, *a2;
	
	a1 = fopen("desplazado.txt", "r");
	a2 = fopen("tomás.txt", "w");
	
	while(!feof (a1)){
		fputc(fgetc(a1)-11, a2);
	}
	fclose(a1);
	fclose(a2);
	
	return 0;
}
