#include <stdio.h>
#include <string.h>

// Function to reverse a string using recursion
void reverseString(char *str) {
    // Base case: if the string is empty or contains only one character
    if (*str == '\0')
        return;

    // Recursive call to reverse the substring excluding the first character
    reverseString(str + 1);

    // Print the first character of the string (in reverse order)
    printf("%c", *str);
}

int main() {
    char str[100];

    // Ask the user to enter a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Print the original string
    printf("Original string: %s\n", str);

    // Print the reverse of the string using recursion
    printf("Reverse string: ");
    reverseString(str);
    printf("\n");

    return 0;
}

