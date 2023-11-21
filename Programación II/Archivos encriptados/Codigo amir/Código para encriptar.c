#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void creaconfidencial(FILE *);
void palabraclave(FILE *, FILE *);
void desplazamiento(FILE *);


int main(){

    FILE *fp1 = NULL, *fp2 = NULL;

    creaconfidencial(fp1);
    palabraclave(fp1, fp2);
    desplazamiento(fp2);
    
    return 0;
}


//Crea el archivo y le colocamos un texto
void creaconfidencial(FILE *fp1){

    fp1 = fopen("Archivo.txt", "w");

    fputs("Llegó el final de la semana de receso escolar y del puente festivo que se inició el viernes 14 y se extendió hasta hoy 17 de octubre, por esa razón, las autoridades se preparan para la llegada masiva de bogotanos a la ciudad.\n\nSe estima que a la capital del país retornen cerca de 338.000 personas, que durante estos últimos cuatro días circularon por las carreteras del país y en especial por las del departamento de Cundinamarca. Los cálculos oficiales dicen que durante el fin de semana se pudieron mover cerca de 693.500 vehículos en la ciudad y estiman que 1’223.000 transitarán por las vías del departamento al cierre de la jornada.", fp1);

    rewind(fp1);
    fclose(fp1);

    return;
}


//Encriptar por palabra clave
void palabraclave(FILE *fp1, FILE *fp2){

    unsigned char car = 0;
    char band = 'F';
    char palabra[20] = "caroti";

    fp1 = fopen("Archivo.txt", "r");
    fp2 = fopen("Confidencial.txt", "w");

    while(!feof(fp1)){ 
        car = fgetc(fp1);

        for(int i = 0;i <= strlen(palabra)-1; i = i+1){

            if(car == palabra[i]){
                fputc(i, fp2);
                band = 'V';
            }
           
        }

        if(band == 'F'){
            fputc(car, fp2);
        }

        band = 'F';
    }

    rewind(fp1);
    rewind(fp2);
    fclose(fp1);
    fclose(fp2);

    return;
}


// Encriptar Por DESPLAZAMIENTO
void desplazamiento(FILE *fp2){

    FILE *fp3 = NULL;

    fp2 = fopen("Confidencial.txt", "r");
    fp3 = fopen("Confidencial1.txt", "w");

    while(!feof(fp2)){
        fputc(fgetc(fp2)+ 127, fp3);
    }

    fclose(fp2);
    fclose(fp3);
    
	return;
}
