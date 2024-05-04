// Includes
#include <stdio.h>
#include <string.h>
#include "domains.h" // Include the header file containing the country_codes array

// Main function 
int main(void) {
    
    // Read user input
    #define LEN 4 // Define the length of user_input array
    char user_input[LEN]; // Declare an array to store user input
    printf("Enter a domain including the . (e.g. .uk): ");
    fgets(user_input, LEN, stdin); // Read user input from standard input
    
    // Enter your code under here

    // Check if the first character entered by the user is '.'
    if (user_input[0] != '.') {
        printf("Error! The first character entered should be a .");
        return 1; // Exit the program with an error code
    }

    // Compare user input with each domain in the country_codes array
    int total_domains = sizeof(country_codes) / sizeof(country_codes[0]); // Calculate the total number of domains
    int found = 0;  // Flag to indicate if a match was found
    for (int i = 0; i < total_domains; i++) {
        // Compare user input with the domain at index i
        if (strcmp(user_input, country_codes[i].domain) == 0) {
            printf("This is the domain for: %s", country_codes[i].country); // Print the corresponding country
            found = 1; // Set the flag to indicate a match was found
            break; // Exit the loop since a match was found
        }
    }

    // If no match was found, print "Domain not found."
    if (!found) {
        printf("Domain not found.");
    }

    // Do not edit below here
    return 0; // Exit the program with success code
}
