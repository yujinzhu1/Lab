#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 201    // Maximum number of rows in the data array
#define MAX_COLS 3      // Maximum number of columns in the data array
#define MAX_BUFFER_SIZE 100 // Maximum size of the buffer for reading lines from file

int main(void) {
    double data[MAX_ROWS][MAX_COLS];   
    char buffer[MAX_BUFFER_SIZE];      
    int rowIndex = 0;                   
    int colIndex = 0;                   
    char *ptr;                          

    char fileName[] = "data.csv";      // File name to be read
    FILE *filePointer;                  // Pointer to file to be read
    filePointer = fopen(fileName, "r"); // Open file for reading

    if (filePointer == NULL) {
        printf("Error: Failed to open the file."); // Print error message if file opening fails
        return EXIT_FAILURE;
    }

    // Read lines from the file
    while (fgets(buffer, MAX_BUFFER_SIZE, filePointer)) {
        colIndex = 0; // Reset column index for each new row
        rowIndex++;   // Increment row index for each new row

        // Skip the header row
        if (rowIndex == 1) {
            continue;
        }

        // Tokenize the line and convert tokens to double, storing them in the data array
        char* value = strtok(buffer, ", ");
        while (value) { 
            data[rowIndex - 2][colIndex] = strtod(value, &ptr);
            value = strtok(NULL, ", ");
            colIndex++; // Move to the next column
        }
    }

    fclose(filePointer); // Close the file after reading

    double median[MAX_COLS]; // Array to store median values for each column

    // Calculate median for each column
    for (int col = 0; col < MAX_COLS; col++) {
        // Sort the column in ascending order
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int k = i + 1; k < MAX_ROWS; k++) {
                if (data[i][col] > data[k][col]) {
                    double temp = data[i][col];
                    data[i][col] = data[k][col];
                    data[k][col] = temp;
                }
            }
        } 

        // Calculate median for the current column
        median[col] = data[MAX_ROWS / 2][col];
    }

    // Print the median values for each column
    printf("%.2f,%.2f,%.2f", median[0], median[1], median[2]);

    return EXIT_SUCCESS;
}
