#include <stdio.h>
#include <string.h> // Include the string.h library for strlen function

int main() {
    char my_email[] = "yujin.zhu@student.manchester.ac.uk";

    int n; // Variable to store the user's input for index

    printf("Enter an integer: ");
    scanf("%d", &n);

    // Check if n is within valid range
    if (n < 0 || n >= strlen(my_email)) {
        printf("Error"); // If n is out of range, print error message
        return 1; // Return with error code
    }

    // Convert the character to lowercase for easier comparison
    char lowercase_char = tolower(my_email[n]);

    // Check if the character is a vowel
    switch (lowercase_char) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            printf("Vowel"); // If the character is a vowel, print "Vowel"
            break;
        default:
            printf("Not vowel"); // If the character is not a vowel, print "Not vowel"
    }

    return 0; // Return with success code
}
