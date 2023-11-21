#include <stdio.h>
#include <string.h>


int main(){
	char pal[20] = "murcielago";
	FILE *a1, *a2;
	char car = 0;
	int i = 0;
	
	a1 = fopen("original.txt", "r");
	a2 = fopen("palabra.txt", "w");
	
	while(!feof (a1)){
		car = fgetc(a1);
	}
	for(i = 0; i <= strlen(pal); i = i + 1){
		if(car == pal[i]){
			fputc(i, a2);
			i = strlen(pal) + i;
		}
		if(i == strlen(pal) + 1)
			fputc(car, a2);
	}
	fclose(a1);
	fclose(a2);
	
	return 0;
}
