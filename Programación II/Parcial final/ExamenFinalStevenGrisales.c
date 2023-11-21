#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

// Prototipos
void rellenartabla(char[]);
void portafolio();
void comprobante();
void factura();
void hora();

// Estructura del registro del diagnosticentro
typedef struct registro{
    int codigo; 
    char valor[17]; 
    char producto[30];
} est;

typedef struct comprobante{
    int codigo; 
    char cantidad[8];
} est1;

int main() {
    int opcion = 4; // Esta variable la usaré para las opciones del switch
    //char menu[];
    //rellenartabla(char menu[]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 
    201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
    205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
    205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    while(opcion != 0){
        printf("\nDIAGNOSTICENTRO EL PROGRESO \t\t NIT 903.103.888-2\n");
        printf("\t\t    MENU PRINCIPAL\n\n");
        printf("   0. Salir del Aplicativo\n");
        printf("   1. A%cadir nuevos productos al portafolio\n", 164);
        printf("   2. Llenar %cComprobante de servicio%c a un cliente\n", 34, 34);
        printf("   3. Generar e imprimir factura\n\n");
        printf("   Seleccione su opci%cn: ", 162);
        scanf("%i", &opcion);
        switch(opcion) {
            case 0:
                printf("Gracias por utilizar el aplicativo.\n");
                system("pause");
                break;
            case 1: 
                portafolio();
                break;
            case 2: 
                //comprobante();
                break;
            case 3:
                //factura();
                break;
            default:
                printf("Opci%cn no valida\n", 162);    
                system("pause");
        }
    
    }
    return 0;
}

void portafolio() {
    FILE *fp = NULL;
    est portafolio;

    system("cls");
    fp = fopen("portafolio.txt", "a+");
    if(fp == NULL){
        portafolio.codigo = 49;
        fp = fopen("portafolio.txt", "w+");

        fwrite("0", 1, 1, fp);
        fwrite(&portafolio.codigo, 4, 1, fp);

        printf("Ingrese el nombre del producto: ");
        scanf("%s", portafolio.producto);
        fwrite(&portafolio.producto, sizeof(portafolio.producto), 1, fp);

        printf("Ingrese el valor del producto: ");
        scanf("%s", &portafolio.valor);
        fwrite(&portafolio.valor, sizeof(portafolio.valor), 1, fp);
    } else {
        fp = fopen("portafolio.txt", "a+");
        fseek(fp, 4, SEEK_END);
        fread(&portafolio.codigo, 4, 1, fp);
        portafolio.codigo = (ftell(fp) / 52) + 1;

        if(portafolio.codigo <= 9){

            fseek(fp, 4, SEEK_END);
            fread(&portafolio.codigo, 4, 1, fp);
            portafolio.codigo = (ftell(fp) / 52) + 49;
            fwrite("0", 1, 1, fp);
            fwrite(&portafolio.codigo, 4, 1, fp);

            printf("Ingrese el nombre del producto: ");
            scanf("%s", portafolio.producto);
            fwrite(&portafolio.producto, sizeof(portafolio.producto), 1, fp);

            printf("Ingrese el valor del producto: ");
            scanf("%s", &portafolio.valor);
            fwrite(&portafolio.valor, sizeof(portafolio.valor), 1, fp);
            fclose(fp);
        } else {
            fp = fopen("portafolio.txt", "a+");
            int op = (portafolio.codigo / 10) + 48;
            int up = (portafolio.codigo % 10) + 49;

            fseek(fp, 4, SEEK_END);
            fread(&portafolio.codigo, 4, 1, fp);
            portafolio.codigo = (ftell(fp) / 52) + 49;
            fwrite(&op, 1, 1, fp);
            fwrite(&up, 4, 1, fp);

            printf("Ingrese el nombre del producto: ");
            scanf("%s", portafolio.producto);
            fwrite(&portafolio.producto, sizeof(portafolio.producto), 1, fp);

            printf("Ingrese el valor del producto: ");
            scanf("%s", &portafolio.valor);
            fwrite(&portafolio.valor, sizeof(portafolio.valor), 1, fp);
        }
    }
    return;
}

// Función que realiza la fecha
void hora() {
    int horas, minutos, segundos, dia, mes, anio;
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    horas = local->tm_hour;
    minutos = local -> tm_min;
    segundos = local -> tm_sec;
    dia = local -> tm_mday;
    mes = local -> tm_mon + 1;
    anio = local -> tm_year + 1900; 
    
    // Impresion de la hora
    if (horas<12){	// Si antes de medio dia
    Sleep(500);
    printf("|Hora: %02d:%02d:%02d am                                                                                                      \n",horas,minutos,segundos);
    } else {	// Si es despues de medio dia
    Sleep(500);
    printf("|Hora: %02d:%02d:%02d pm                                                                                                      \n", horas-12,minutos,segundos);
    }
    // Fecha
    Sleep(500);
    printf("|Fecha: %02d/%02d/%d                                                                                                      \n",dia,mes,anio);    
}

/* while(verificarcod(producto.codigo)==1 || strlen(producto.codigo)!=3){
printf("\n\nEl codigo ingresado ya esta en uso o no tiene el n�mero de caracteres pedido\n\nPor favor vuelva a ingresar el codigo (3 caracteres):");
gets(producto.codigo);	
fflush(stdin);	
}

//funcion que verifica que el codigo de un nuevo art�culo no este en uso.
int verificarcod(char codigo[3]){
rewind(p2);
while(fread(&producto2,sizeof(producto2),1,p2)){
if(strcmp(producto2.codigo,codigo)==0)return 1;		
}	
return 0;	

}
*/
