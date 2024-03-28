#include <stdio.h>
void print_pattern(int n, int row) {
    if (row > n)
        return;
    for (int i = 1; i <= row; i++)
        printf("%d ", i);
    printf("\n");
    print_pattern(n, row + 1);
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    print_pattern(n, 1);
    return 0;
}
