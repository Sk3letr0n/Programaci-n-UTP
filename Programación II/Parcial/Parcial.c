#include <stdio.h>
#include <stdlib.h>
#define CP_UTF8 65001

int main(){

    system("cls");

    unsigned char valor = 0;
    long int i = 0;
    char band = 'F';

    FILE *fp1 = NULL, *fp2 = NULL;

    fp1 = fopen("confidencial06", "rb");
    fp2 = fopen("Desencriptado06","wb");


    while(i <= 2980){

        valor = fgetc(fp1) - 69;
        printf(" %c / %i -> ", valor, valor);

        if(valor == 9){
            valor = 41;
        }
        if(valor == 12){
            band = 'V';
        }
        if(valor == 25){
            valor = 57;
        }
        if(valor == 26){
            valor = 10;
        }
        if(valor == 34){
            valor = 67;
  		}
        if(valor == 44){
            valor = 76;
        }
        if(valor == 55){
            valor = 87;
        }
        if(valor == 63){
            valor = 95;
        }
        if(valor == 103){ 
        	valor = 65;
            //valor = 181;
        }
        if(valor == 110){
            valor = 69;
        }
        if(valor == 114){
            valor = 73;
        }
        if(valor == 119){
            valor = 79;
        }
        if(valor == 124){
            valor = 85;
        }
        if(valor == 133){
            valor = 9;
        }
        if(valor == 135){ //�
            fputc(-95, fp2);
            band = 'V';
        }
        if(valor == 142){ //�
            fputc(-87, fp2);
            band = 'V';
        }
        if(valor == 143){
            valor = 67;
        }
        if(valor == 146){ //�
            fputc(-83, fp2);
            band = 'V';
        }
        if(valor == 150){ //�
            fputc(-79, fp2);
            band = 'V';
        }
        if(valor == 151){ //�
            fputc(-77, fp2);
            band = 'V';
        }
        if(valor == 156){ //�
            fputc(-70, fp2);
            band = 'V';
        }
        if(valor == 175){
            valor = 77;
		}
        if(valor == 178){
            valor = 34;
        }
        if(valor == 179){
            valor = 34;
        }
		if(valor == 183){
            valor = 32;
        }
        if(valor == 187){
            valor = 77;
        }
        //Val
        if(valor == 188){
            valor = 78;
        }
        if(valor == 189){
            valor = 79;
        }
		if(valor == 192){
			valor = 32;
		}
        if(valor == 193){
            valor = 40;
        }
        if(valor == 194){
            valor = 41;
        }
        if(valor == 195){
            valor = 48;
        }
        if(valor == 196){
            valor = 82;
        }
        if(valor == 197){
            valor = 83;
        }
        if(valor == 198){
            valor = 84;
        }
        if(valor == 199){
            valor = 85;
        }
        //Val
        if(valor == 200){
            valor = 86;
        }
        if(valor == 203){
            valor = 68;
        }
        if(valor == 205){
            valor = 80;
        }
        if(valor == 207){
            valor = 53;
        }
        if(valor == 208){ 
            valor = 65;
        }
        //Validar
        if(valor == 209){ 
            valor = 66;
        }
        if(valor == 210){ 
            valor = 67;
        }
        if(valor == 211){
            valor = 69;
        }
        if(valor == 212){
            valor = 70;
        }
        if(valor == 213){
            valor = 71;
        }
        if(valor == 214){
            valor = 72;
        }
        if(valor == 215){
            valor = 73;
        }
        if(valor == 216){
            valor = 32;
        }
        if(valor == 217){
            valor = 44;
        }
        if(valor == 225){ 
            valor = 45;
        }
        if(valor == 226){
            valor = 46;
        }
        if(valor == 227){
            valor = 47;
        }
        if(valor == 228){
            valor = 49;
        }
        if(valor == 229){
            valor = 50;
        }
        if(valor == 231){
            valor = 52;
        }
        if(valor == 233){
            valor = 45;
        }
        if(valor == 234){
            valor = 10;
        }
        if(valor == 241){
            valor = 40;
        }
        if(valor == 243){
            valor = 10;
        }
        
        
        if(band == 'F'){
           fputc(valor, fp2);
        }

        i = i + 1;
        band = 'F';
 		printf(" %c / %i \n", valor, valor);
    }
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}
