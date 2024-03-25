#include <stdio.h>

int fibonacci_sum_even(int n) {
    int fib[100]; // Array to store Fibonacci sequence
    int i, even_sum = 0;

    // Initialize first two Fibonacci numbers
    fib[0] = 0;
    fib[1] = 1;

    // Generate Fibonacci sequence till n
    for (i = 2; fib[i - 1] <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Sum even Fibonacci numbers
    for (int j = 0; fib[j] <= n; j++) {
        if (fib[j] % 2 == 0) {
            even_sum += fib[j];
        }
    }

    return even_sum;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Calculate and print the result
    printf("The sum of even Fibonacci numbers till %d is: %d\n", n, fibonacci_sum_even(n));

    return 0;
}

