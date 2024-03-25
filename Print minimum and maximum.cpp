#include <stdio.h>

void printMinMaxSequence(int arr[], int n) {
    int i, j, min, max;

    for (i = 0; i < n; i++) {
        
        min = arr[i];
        max = arr[i];

        for (j = i; j < n; j++) {
            if (arr[j] < min)
                min = arr[j];
            if (arr[j] > max)
                max = arr[j];

            printf("For sequence from %d to %d, Minimum = %d, Maximum = %d\n", arr[i], arr[j], min, max);
        }
    }
}

int main() {
    int n, i;

    printf("Enter the size of the list: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printMinMaxSequence(arr, n);

    return 0;
}

