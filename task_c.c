#include <stdio.h>

int main() {
    // Define the email address as a character array
    char my_email[] = "yujin.zhu@student.manchester.ac.uk";

    int n; // Variable to store the user's input for index

    // Prompt the user to enter an integer
    printf("Enter an integer: ");
    scanf("%d", &n); // Read the integer input from the user

    // Check if the entered index is negative or exceeds the length of the email address
    if (n < 0 || n >= sizeof(my_email) / sizeof(my_email[0]) - 1) {
        printf("Error"); // If the index is invalid, print an error message
        return 1; // Return with error code
    }

    // Check if the character at the specified index is a vowel
    switch (my_email[n]) {
        // If the character is a vowel (both uppercase and lowercase), print "Vowel"
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            printf("Vowel");
            break;
        // If the character is not a vowel, print "Not vowel"
        default:
            printf("Not vowel");
    }

    return 0; // Return with success code
}
