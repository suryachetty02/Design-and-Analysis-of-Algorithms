#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
bool found = false;

void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}
void sumOfSubsets(int set[], int subset[], int n, int subsetSize, int sum, int target, int index) {
    if (sum == target) {
        printSubset(subset, subsetSize);
        found = true;
        return;
    }

    for (int i = index; i < n; i++) {
        if (found || sum + set[i] > target)
            continue;
        subset[subsetSize] = set[i];
        sumOfSubsets(set, subset, n, subsetSize + 1, sum + set[i], target, i + 1);
    }
}

int main() {
    int set[MAX_SIZE];
    int n, target;
    printf("Enter number of elements in the set: ");
    scanf("%d", &n);
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &target);
    int subset[MAX_SIZE];
    sumOfSubsets(set, subset, n, 0, 0, target, 0);
    if (!found) {
        printf("No subset with sum equal to target found.\n");
    }
    return 0;
}
