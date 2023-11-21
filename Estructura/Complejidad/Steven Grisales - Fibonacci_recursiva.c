#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    printf("Ingrese la posicion del numero de Fibonacci que desea calcular: ");
    scanf("%d", &n);
    printf("El numero de Fibonacci en la posicion %d es %d\n", n, fibonacci(n));
    return 0;
}



