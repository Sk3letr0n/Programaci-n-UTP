// Hecho por Steven Grisales López.
// Tanto el ejercicio de Realloc y Malloc estan modificados para mi entendimiento pero cumplen la misma función.

#include <stdio.h>
#include <conio.h> 
#include <stdlib.h>

int main(){
	int opcion;
	
	printf("Ingrese su opcion: ");
	scanf("%i", &opcion);
	
	switch(opcion){
		// Malloc
		case 1:{
			float *ptr;
			int elementos;
			printf("Numero de valores: "); 
			scanf("%i", &elementos);
	
			ptr = (float *) malloc(elementos *sizeof(float));
	
			if(ptr == NULL){
				printf("No hay suficiente memoria.\n");
				exit(-1);
			}
			int i;
			for(i = 0; i < elementos; i++){
				printf("Valor %i >> ", i + 1);
				scanf("%f", (ptr + i));
			}
			for(i = 0; i < elementos; i++){
				printf("%0.2f ", *(ptr + i));
			}
			free(ptr);
		break;
		}
		case 2:{
			// Realloc
			float *p = NULL;
			char c = 0;
			int nElem = 0;
			
			do{
				p = (float *) realloc((float *)p, (nElem + 1) * sizeof(float));
				
				printf("Elemento %i: ", nElem + 1);
				scanf("%f", (p + nElem));
				printf("\nDesea ingresar otro valor?: (S/N): ");
				c = getch();
				nElem++;
				printf("\n");
			} while(c == 's' || c == 'S');
			
			int i;
			for(i = 0; i < nElem; i++){
				printf("%0.2f ", p[i]);
			}
			
			free(p);
		break;
		}
	}
	
	return 0;
}

