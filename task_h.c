#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    #define BUFFER_SIZE 256
    char inputBuffer[BUFFER_SIZE + 1], *fileName = inputBuffer;
    char character;
    int index = 0; // Counter for the number of characters read
    
    printf("Please enter a file name: ");
    
    // Read characters until newline character is encountered
    while ((character = getchar()) != '\n') {
        fileName[index++] = character;
    }

    // Fill the remaining buffer with null characters
    for (; index < BUFFER_SIZE + 1; index++) {
        fileName[index] = '\0';
    }

    // Find the file extension
    char *extension = strrchr(fileName, '.');
    if (extension != NULL && *(extension + 1) != '\0') {
        printf("File extension: %s\n", extension);
    } else {
        printf("Error: No valid file extension found.\n");
    }

    return EXIT_SUCCESS;
}
