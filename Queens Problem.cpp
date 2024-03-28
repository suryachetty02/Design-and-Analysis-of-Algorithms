#include <stdbool.h>
#include <stdio.h>
#define N_MAX 10

int N;
int board[N_MAX][N_MAX];
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(int row, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        
        if (isSafe(i, col)) {
            
            board[i][col] = 1;
            if (solveNQUtil(col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}
bool solveNQ() {
    printf("Enter the board size (N <= %d): ", N_MAX);
    scanf("%d", &N);

    if (N <= 0 || N > N_MAX) {
        printf("Invalid board size\n");
        return false;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (solveNQUtil(0) == false) {
        printf("Solution does not exist");
        return false;
    }
    printf("Solution:\n");
    printSolution();
    return true;
}
int main() {
    solveNQ();
    return 0;
}
