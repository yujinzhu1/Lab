#include <stdio.h>

int main() {
    char my_email[] = "yujin.zhu@student.manchester.ac.uk";

    int n; // Variable to store the user's input for index

    printf("Enter an integer: ");
    scanf("%d", &n);

    // Check if n is within valid range
    if (n < 0 || n >= strlen(my_email)) {
        printf("Error");
        return 1;
    }

    // Convert the character to lowercase for easier comparison
    char lowercase_char = tolower(my_email[n]);

    // Check if the character is a vowel
    switch (lowercase_char) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            printf("Vowel");
            break;
        default:
            printf("Not vowel");
    }

    return 0;
}