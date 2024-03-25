#include <stdio.h>

// Function to find the largest element of an array
int findLargest(int arr[], int size) {
    int largest = arr[0]; // Assume the first element is the largest
    
    // Iterate through the array to find the largest element
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    
    return largest;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    // Declare an array of the specified size
    int arr[size];
    
    // Input elements of the array from the user
    printf("Enter %d elements of the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    // Call the function to find the largest element
    int largest = findLargest(arr, size);
    
    printf("The largest element of the array is: %d\n", largest);
    
    return 0;
}

