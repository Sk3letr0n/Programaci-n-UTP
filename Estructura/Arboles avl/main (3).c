#include <stdio.h>

int suma_lista(int vector[], int n);

int main() {
    int vector[10]={1,5,6,10,76,23,86,93,2,10};
    int r;
    r = suma_lista(vector, 10);
    
    printf("La suma del vector es: %d", r);
    return 0;
}

int suma_lista(int vector[], int n){
    int suma;
    
    for(int i = 0; i < n; i ++){
        suma = suma + vector[i];
    }
    return suma;
}