#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct estudiantes{
    unsigned long int id; 
    char pNombre[30];
    char sNombre[30];
    char pApellido[30];
    char sApellido[30];
    float notaPrimerParcial;
} est;
    
int main() {
    est estudiante; //declaro una variable de tipo est
    
    estudiante.id = 1010153117;
    strcpy(estudiante.pNombre, "Steven");
    strcpy(estudiante.pApellido, "Grisales");
    strcpy(estudiante.sApellido, "Lopez");
    estudiante.notaPrimerParcial = 0.5;
    
    FILE *fp = fopen("curso.txt", "w");
    fwrite(&estudiante, sizeof(estudiante), 1, fp);
    
    estudiante.id = 10159812;
    strcpy(estudiante.pNombre, "Michael");
    strcpy(estudiante.pApellido, "Bustamante");
    estudiante.notaPrimerParcial = 0.5;
    fwrite(&estudiante, sizeof(estudiante), 1, fp);
    
    rewind(fp);
    fclose(fp);
    
    fp = fopen("curso.txt", "r");
    
    fread(&estudiante, sizeof(estudiante), 1, fp);
    
    printf("%li       %s      %s      %s    %s     %0.1f \n", estudiante.id, estudiante.pNombre, estudiante.sNombre, estudiante.pApellido, estudiante.sApellido, estudiante.notaPrimerParcial);
    
    fread(&estudiante, sizeof(estudiante), 1, fp);
    
    printf("%li       %s      %s      %s    %s     %0.1f \n", estudiante.id, estudiante.pNombre, estudiante.sNombre, estudiante.pApellido, estudiante.sApellido, estudiante.notaPrimerParcial);
    fclose(fp);
    return 0;
}