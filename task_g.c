#include <stdio.h>
#include <stdlib.h>
#include "task_g.h"

int main(void) {
    // Open the file "number.txt" for reading
    FILE *inputFile = fopen("number.txt", "r");
    
    // Check if file opening failed
    if (!inputFile) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Array to store numbers from the file
    double numArray[20];
    int numCount = 0;

    // Read up to 20 numbers from the file
    while (numCount < 20 && fscanf(inputFile, "%lf", &numArray[numCount]) == 1) {
        numCount++;
    }
    
    // Close the file
    fclose(inputFile);

    // Check if fewer than 20 numbers were read
    if (numCount < 20) {
        printf("Error: Insufficient data.\n");
        return 1;
    }

    // Find the maximum number less than 10
    double maximum;
    find_max_less_than_10(numArray, numCount, &maximum);

    // Check if a valid number less than 10 was found
    if (maximum == -1) {
        printf("Error: No valid number found.\n");
    } else {
        printf("Maximum number less than 10: %.2f\n", maximum);
    }
    
    return 0;
}
