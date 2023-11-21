#include <math.h>
#include <stdio.h>
int main(int argc, char argv[])
{
    int r = 0;
    int n = 0;
    printf("Ingrese el valor fibonacci: ");
    scanf("%i", &n);
    r = ((pow((1 + sqrt(5)), n))-(pow(1-sqrt(5),n)))/(pow(2,n) sqrt(5));
    printf("El valor de su fibonacci es: %i", r);
    return 0;
}