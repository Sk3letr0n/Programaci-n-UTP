/*
Autor: Ing(c) Steven Grisales L�pez.
Fecha de publicaci�n: 19/11/2022
Versi�n del c�digo: 1.0 
Compilador gcc (tdm64-1)
Versi�n del compilador: 4.9.2
Presentado a: Doctor Ricardo Moreno Laverde
Universidad Tecnol�gica de Pereira
Programa de Ingenier�a de Sistemas y Computaci�n
Asignatura IS284 Programaci�n II

Se pide hacer un aplicativo en lenguaje C, tal que administre un programa que permita primero acceso con un modulo de usuarios con
�username� y �password� para cada usuario, registrando el �log� de acceso a todos los usuarios y luego permita manejar un modulo que
permita graficar una funci�n polin�mica del tipo f(x).

Salvedad: Si separa los terminos del polinomio no se aseguran los resultados (ejemplo: 2x2 + 3x5 + 5), ademas, se sabe que no puede tener un coeficiente 0.
Si lo hace, no se garantizan los resultados del aplicativo.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void poli(char[]);
void crearPriv(char[], char[], char[]);
void inicio1();
void inicio2();
void menu();

//estctura para guardar usuario y contrase�a
typedef struct priva{
	char nombre[20];
	char password[20];
}est;

//Esta funcion descompene un polinomio en coeficientes y exponentes y los imprime.
int main() {
	FILE *clav=NULL;
	clav = fopen("Infor", "r");
	est usuario;
	
	//verificar primera ejecucion
	if(clav==NULL){
		clav = fopen("Infor", "w");
		usuario.nombre="root";
		fwrite(usuario.nombre ,4,1, clav);
		
		inicio1();
		return;
	}
	else{ //siguientes ejecuciones
		inicio2();
		return 0;
	}
	

    return 0;
}
//La función que mira en la cadena si hay una x para ir determinando que hay en cada posición y luego separarlo en coeficientes y exponentes
void poli(char polinomio[100]) {
    int cont = 0,expo = 0,coe = 0,x = 0; //Posici�n del string, Exponente, Coeficiente, Valor de x
    
    while(polinomio[cont] != 00) {
    	
        if(polinomio[cont] =='X' || polinomio[cont] == 'x') {
        	
            if (polinomio[cont-1] == '-' || polinomio[cont-1] == '+') {
                coe = 1;
            }
            if(coe == 0) {
            	coe = 1;
            }
            x = 1;
        }
        else if(polinomio[cont] == '+') {
            
            if(x == 1 && expo == 0) {
                expo = 1;
                printf("%i\t\t   %i\n", coe, expo);
                coe = 0;expo = 0;x = 0;
            }
            else if(coe == 0);
            else {
                printf("%i\t\t   %i\n", coe, expo);
                coe = 0;expo = 0;x = 0;
			}
        }
        else if(polinomio[cont] == '-') {
            if(x == 1 && expo == 0) {
                expo = 1;
                printf("%i\t\t   %i\n-", coe, expo);
                coe = 0;expo = 0;x = 0;
            }
            else if(polinomio[cont-1] == '(') {
            	expo = 0;
            }
            else if(coe == 0) {
                printf("-");
            }
            else {
                printf("%i\t\t   %i\n-", coe, expo);
                coe = 0;expo = 0;x = 0;
            }
        }
        else if(polinomio[cont] == ')') {
        	printf("%i\t\t   -%i\n", coe, expo);
        	coe = 0;expo = 0;x = 0;
        }
        	
        else {
            if(x == 1) {
                expo = (expo*10) + (polinomio[cont]- 48);
            }
            else {
                coe = (coe*10) + (polinomio[cont]- 48);
            }
        }
    	if(polinomio[cont+1] == 00) {
        	if(expo == 0 && x == 1)
           		expo = 1;
        	if(polinomio[cont] != ')')
        		printf("%i\t\t   %i", coe, expo);
    	}
    cont = cont + 1;
    }
}

//esta funcion se ejecuta en la primera ejecucion del programa guardando la coontrase�a para root
void inicio1 (){
	FILE *clav=NULL;
	est usuario;
	clav=foper("Infor", "a");
	char pal[4]=fread(pal,4,1,clav);
	printf("Aplicativo - Graficador - UTP");
	printf("Username: ");
	scanf("%s", usuario.nombre);
	
	if (usuario.nombre == pal ){ //si el nombre es root
		printf("Password: ");
		scanf("%s", usuario.password );
		if(strlen(usuario.password )>= 4){
			fwrite(usuario.password,strlen(usuario.password ),1, clav);
			crearPriv(usuario.password , clave, palabraclave); //clave y palabra clave deben ser leidos de seguridad.gar
			system("cls");
		} else {
			return;
		}
		}else{
			return;
		}

}

//esta funcion busca si el usuario y contrase�a son correctos (maximo 3 errores) y si son correctos abre el menu
void inicio2(){
	int error=0;
	while(error<=3){
		if(){
			
		}else{
			error=error+1;
		}
	}
}

//menu principal de la aplicacion
void menu (char nombre[]);{
	int n=0 //variable para el switch
	if (nombre == "root" ){//para el administrador
		printf("Aplicativo - Gaficador - UTP\n");
		printf("Men%c principal para el usuario: %s\n\n", 164,nombre);
		printf("0.Salir del aplicativo\n");
		printf("1.Crear nuevo usuario\n");
		printf("2.Borrar usuario\n");
		printf("3.Lista de accesos por usuario\n");
		printf("4.Lista de accesos todos los usuarios\n");
		printf("5.Imprimir grafico por referencia\n");
		printf("6.Cambiar password del usuario root\n");
		printf("7.Cambiar password de un usuario\n");
		scanf("%i", &n);
		system("cls");
		switch(n){
			case 0: return; break;
			case 1: break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 5: break;
			case 6: break;
			case 7: break;
			default return;
		}
	}else{//para un usuario normal
		printf("Aplicativo - Gaficador - UTP\n");
		printf("Men%c principal para el usuario: %s\n\n", 164,nombre);
		printf("0.Salir del aplicativo\n");
		printf("1.Crear un nuevo grafico\n");
		printf("2.Borrar un grafico existente\n");
		printf("3.Listar accesos\n");
		printf("4.Imprimir grafico por referencia(si es suyo)\n");
		printf("5.Cambiar password del usuario %s\n", nombre);
		scanf("%i", &n);
		system("cls");
		switch(n){//para un usuario normal
			case 0: return; break;
			case 1: char polinomio[100]; 
				    printf("Ingrese un polinomio:");
				    scanf("%s", polinomio);
				    printf("Coeficiente     Exponente\n");
				    poli(polinomio); break; //arreglar caso ya es es la graficadora
			case 2: break;
			case 3: break;
			case 4: break;
			case 5: break;
			default return;
		}
		
	}
	
}

//A�ade el archivo Privacity (El que guarda el usuario y contrase�a)
void crearPriv(char usuario[], char clave[], char palabraclave[]){
    	FILE *fp1 = NULL; // Puntero de archivo 
    char band = 'F'; // La usar� para la encriptaci�n de palabra clave

    //Modificar el archivo Privacity
    fp1 = fopen("privacity", "a"); // "a" A�ade el archivo

    fputs(usuario, fp1); //Colocamos el usuario en el archivo
    fputc('*', fp1); //Colocamos un asterisco para indicar donde inicia la contrase�a

    for(int i = 0; i <= strlen(clave) - 1; i++){
        for(int j = 0; j <= strlen(palabraclave) - 1; j++){//Encriptaci�n de la contrase�a con palabra clave
            if(palabraclave[j] == clave[i]){
                fputc(j + 142, fp1); //Encriptaci�n con desplazamiento +142
                band = 'V';
            }
        }
        if(band == 'F'){ //Si no tiene alg�n elemento de la palabra clave solo se desplaza
            fputc(clave[i] + 142, fp1);
        }
        band = 'F';
    }
    fputc('*', fp1); //Indica el final de la contrase�a
    fputc(10, fp1); //Una nueva l�nea para la siguiente contrase�a

    rewind(fp1);
    fclose(fp1);

    return;
}
