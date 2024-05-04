#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    #define BUFFER_SIZE 256
    char inputBuffer[BUFFER_SIZE + 1];
    char character;
    int index = 0; // Counter for the number of characters read
    
    printf("Enter a file name: .txt");
    
    // Read characters until newline character is encountered or buffer is full
    while ((character = getchar()) != '\n' && index < BUFFER_SIZE) {
        inputBuffer[index++] = character;
    }

    // If the input exceeds buffer size, display error message and exit
    if (index == BUFFER_SIZE) {
        printf("Error!");
        return EXIT_FAILURE;
    }

    // Fill the remaining buffer with null characters
    for (; index < BUFFER_SIZE + 1; index++) {
        inputBuffer[index] = '\0';
    }

    // Find the file extension
    char *extension = strrchr(inputBuffer, '.');
    if (extension != NULL && *(extension + 1) != '\0') {
        printf("File extension: %s", extension);
    } else {
        printf("Error: No valid file extension found.");
    }

    return EXIT_SUCCESS;
}
