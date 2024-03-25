#include <stdio.h>
#include <time.h>

#define MAX_SIZE 100

// Function to perform matrix multiplication
void multiplyMatrix(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int m, int p, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int m, p, n;
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];

    printf("Enter the number of rows and columns for first matrix (m x p): ");
    scanf("%d%d", &m, &p);

    printf("Enter the number of columns for second matrix (p x n): ");
    scanf("%d", &n);

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    clock_t start_time = clock();
    multiplyMatrix(A, B, C, m, p, n);
    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Time taken for matrix multiplication: %f seconds\n", time_taken);

    return 0;
}

