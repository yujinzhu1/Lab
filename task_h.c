#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {

    // Get user input
    #define N 256
    char buffer[N+1], *filename = buffer; // Declare a buffer to store user input
    char ch;
    int i = 0; // counter for how many characters read
    printf("Enter a file name: ");
    while ((ch = getchar()) != '\n') { // get one character at a time
        
        // Enter your code under here
        if (i >= N) { // Check if the filename exceeds 256 characters
            printf("Error!"); // Print error message and exit if exceeded
            return EXIT_FAILURE;
        }
        filename[i++] = ch; // Store the character in the buffer
    }
    for (; i < N+1; i++) { // fill the rest of the array with null characters
        filename[i] = '\0';
    }

    // Enter your code under here
    char *ext = strrchr(filename, '.'); // Find the last occurrence of the dot character
    if (ext != NULL && *(ext + 1) != '\0') { // Check if a valid file extension is found
        printf("%s", ext); // Print the file extension
    } else {
        printf("Error!"); // Print error message if no valid file extension found
    }

    return EXIT_SUCCESS;
}
