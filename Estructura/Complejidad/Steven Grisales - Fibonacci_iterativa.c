#include <stdio.h>

int fibonacci(int n) {
    int fib1 = 0;
    int fib2 = 1;
    int result = 0;

    if (n == 0) {
        return fib1;
    } else if (n == 1) {
        return fib2;
    }

    for (int i = 2; i <= n; i++) {
        result = fib1 + fib2;
        fib1 = fib2;
        fib2 = result;
    }

    return result;
}

int main() {
    int n = 0; 
    printf("Escriba la posicion de fibonacci que desea conocer: ");
    scanf("%i", &n);

    int fib = fibonacci(n);
    printf("\nEl %d numero de Fibonacci es: %d\n", n, fib);
    return 0;
}