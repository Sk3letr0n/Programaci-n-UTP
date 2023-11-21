void crearPriv(char[], char[], char[]);
crearPriv(usuario, clave, palabraclave);

//Añade el archivo Privacity (El que guarda el usuario y contraseña)
void crearPriv(char usuario[], char clave[], char palabraclave[]){
    FILE *fp1 = NULL; // Puntero de archivo 
    char band = 'F'; // La usaré para la encriptación de palabra clave

    //Modificar el archivo Privacity
    fp1 = fopen("privacity", "a"); // "a" Añade el archivo

    fputs(usuario, fp1); //Colocamos el usuario en el archivo
    fputc('*', fp1); //Colocamos un asterisco para indicar donde inicia la contraseña

    for(int i = 0; i <= strlen(clave) - 1; i++){
        for(int j = 0; j <= strlen(palabraclave) - 1; j++){//Encriptación de la contraseña con palabra clave
            if(palabraclave[j] == clave[i]){
                fputc(j + 142, fp1); //Encriptación con desplazamiento +142
                band = 'V';
            }
        }
        if(band == 'F'){ //Si no tiene algún elemento de la palabra clave solo se desplaza
            fputc(clave[i] + 142, fp1);
        }
        band = 'F';
    }
    fputc('*', fp1); //Indica el final de la contraseña
    fputc(10, fp1); //Una nueva línea para la siguiente contraseña

    rewind(fp1);
    fclose(fp1);

    return;
}