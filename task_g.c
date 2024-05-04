#include <stdio.h>
#include <stdlib.h>
#include "task_g.h" // Include the header file for find_max_less_than_10 function

int main(void) {
    FILE *file = fopen("numbers.txt", "r"); // Open the file for reading
    if (!file) { // Check if the file opening was successful
        printf("Error!"); // Print error message if file opening fails
        return 1; // Return with error status
    }

    double numbers[20]; // Array to store numbers
    int count = 0; // Counter for the number of numbers read

    // Read 20 numbers from the file
    while (count < 20 && fscanf(file, "%lf", &numbers[count]) == 1) {
        count++; // Increment count after reading a number
    }
    fclose(file); // Close the file

    // Check if we read less than 20 numbers
    if (count < 20) {
        printf("Error!"); // Print error message if less than 20 numbers were read
        return 1; // Return with error status
    }

    double max; // Variable to store the maximum number less than 10
    find_max_less_than_10(numbers, count, &max); // Call the function to find the maximum number less than 10

    if (max == -1) {  // If no valid number was found
        printf("Error!"); // Print error message
    } else {
        printf("%.2f", max); // Print the maximum number less than 10 with 2 decimal places
    }

    return 0; // Return with success status
}
