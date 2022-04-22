#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n == 0 || n == 1):
        return n;
    return fib(n-2) + fib(n-1);
}

void main() {
    int a = 0;
    int b = 7;

    a = fibonacci(b);
    printf("a");
}