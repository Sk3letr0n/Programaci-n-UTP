#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp = fopen("seguridad.gra","w");
	char pclave[21]="MmUuRrCcIiEeLlAaGgOo";
	fputc('26', fp);
	fwrite(&pclave, 21, 1, fp);
	rewind(fp);
	fclose(fp);

	return 0;
}