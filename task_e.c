#include <stdio.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 2) {
        printf("Error. Expected 1 filename."); // Print error message if incorrect usage
        return 1; // Return with error status
    }

    // Attempt to open the specified file
    FILE *fptr = fopen(argv[1], "r");
    
    // Check if the file opening was successful
    if (fptr == NULL) {
        printf("Error. Cannot open requested file."); // Print error message if file opening fails
        return 1; // Return with error status
    }
    
    // Read a number from the specified file
    double num;
    fscanf(fptr, "%lf", &num); // Read the number from the file
    fclose(fptr); // Close the file

    // Print JSON output
    printf("{\n");
    printf(" \"name\": \"Yujin Zhu\",\n"); // Print name
    printf(" \"email\": \"yujin.zhu@student.manchester.ac.uk\",\n"); // Print email
    printf(" \"number1\": %.2f,\n", num); // Print the number with 2 decimal places
    printf(" \"number2\": %.3e\n", num); // Print the number in scientific notation with 3 decimal places
    printf("}\n");

    return 0; // Return with success status
}
