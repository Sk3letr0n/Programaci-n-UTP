/*	ENUNCIADO: así: El juego consiste en que el jugador, debe adivinar una palabra oculta, 
    que irá construyendo  letra a letra, de tal forma que si la letra entrada no está dentro
	de la palabra a adivinar, el jugador irá siendo “ahorcado” mostrando su cuerpo parte por parte. 
	Para salvarlo es necesario adivinar una palabra, de la cual sólo se conoce su longitud. 
	El jugador debe ir eligiendo letra por letra, de modo de ir completando la palabra. Si el 
	jugador se equivoca en una letra, es decir, la letra seleccionada no pertenece a la palabra a 
	adivinar, el personaje pierde alguna parte de su cuerpo (un brazo, una pierna, el tronco, etc).
	 Se puede jugar hasta que el personaje pierda todo su cuerpo, el último resto de su trágica vida. 
	 
	 
	AUTOR: ING(C) AMIR EVELIO HURTADO MENA
	FECHA: 10/09/2022   
	
	*/
	 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int aleatorio = 0; //guarda el numero aleatorio
	char palabra[15]; //donde se va a guardar la palabra aleatoria
	int longv = 0; //guarda la longitud de la palabra escogida aleatoriamente
	char palabraescondida[] =  "----------------------"; //palabra que el usuario debe encontrar
	char letra = 32; //guarda la letra digitada por el usuario
	char band = 'F'; //sirve para saber si la letra digitada por el usuario se encuentra en la palabra
	char letrasjugadas[] = "               "; //guarda y muestra las letras digitadas por el usuario
	int j = 0; //sirve para saber en que posicion del string se va a guardar las letras digitadas por el usuarios
	char resultado = '?'; //sirve para saber si el usuario adivinó todas las letras de la palabra
    
		
	//palabras de las cuales el programa va a escoger una aleatoriamente
	char palabra1[] = "elefante"; 
	char palabra2[] = "pollito";
	char palabra3[] = "lapiz";
	char palabra4[] = "gaseosa";
	char palabra5[] = "barco";
	char palabra6[] = "hora";
	char palabra7[] = "comida";
	char palabra8[] = "universidad";
	char palabra9[] = "helado";
	char palabra10[] = "teclado";
	
	
	//Caracteres que van a ir apareciendo a medida que el usuario no digite una letra que este en la palabra
	char error1 = 32;
	char error2 = 32;
	char error3 = 32;
	char error4 = 32;
	char error5 = 32;
	char error6 = 32;
	char error7 = 32;
	
	
	
	srand(time(NULL));
	
	aleatorio = 1+ rand()% (10);
	
	
	switch(aleatorio){
		
		case 1: 
		        strcpy(palabra, palabra1);
		        break;
		        
		case 2: strcpy(palabra, palabra2);		       
		        break;
		        
	    case 3: strcpy(palabra, palabra3);
	            break;
	            
	    case 4: strcpy(palabra, palabra4);
	            break;
	            
	    case 5: strcpy(palabra, palabra5);
	            break;
	            
	    case 6: strcpy(palabra, palabra6);
	            break;
	    
	    case 7: strcpy(palabra, palabra7);
	            break;
	            
	    case 8: strcpy(palabra, palabra8);
	            break;
	    
	    case 9: strcpy(palabra, palabra9);
	            break;
	            
	    case 10: strcpy(palabra, palabra10);
	            break;
	}
	
	
	longv = strlen(palabra);
	palabraescondida[longv] = 0;
	
	
	//intentos fallidos sirve para saber saber cuantos intentos fallidos lleva el usuario
	for(int intentosfallidos = 0; (intentosfallidos < 7) && (resultado != 'G'); ){
		
		
	    printf ("\nJUEGO DE AHORCADO\n+----+ \n|    %c       %s \n|   %c%c%c\n|    %c       LETRAS JUGADAS:%s                 \n|   %c %c\n-----\nEntre una letra: ",error1, palabraescondida, error3, error2, error4, error5, letrasjugadas, error6, error7);
	    fflush(stdin);   
	    scanf("%c", &letra);
	    
	    letrasjugadas[j] = letra;
	    j = j+1;
	    
	    
	    //i recorre cada posicion de la palabra a encontrar y verifica si la letra digitada por el usuario se encuentra o no
	    for(int i = 0; i < longv; i = i+1){
	    	
	    	if(palabra[i] == letra){
	    	  palabraescondida[i] = palabra[i];
	    	  band = 'V';
			}
			
		}
		
		
		if(band == 'F'){
		    intentosfallidos = intentosfallidos+1;
			}
			
			
		switch(intentosfallidos){
			case 1: error1 = 48; break;
			case 2: error2 = 124; break;
			case 3: error3 = 47; break;
			case 4: error4 = 92; break;
			case 5: error5 = 124; break;
			case 6: error6 = 47; break;
			case 7: error7 = 92; break;
		}
			
		band = 'F';
		printf ("\n\n");	
		
		
		if(strcmp(palabra, palabraescondida) == 0){
			resultado = 'G';
		}
			
	}
    
    if(resultado == 'G'){
    	printf ("\nFELICIDADES USTED HA GANADO\n\n");
	}
	else{
		printf ("\nUsted ha PERDIDO\n\n");
	}
    
    
    system ("pause");
	return 0;
}