#include <stdio.h>

// Function to calculate factorial using recursion
unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int num;
    unsigned long long fact;

    // Input number from user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate factorial using recursive function
    fact = factorial(num);

    // Display the factorial
    printf("Factorial of %d = %llu\n", num, fact);

    return 0;
}

