#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(void) {
char email[] = "yujin.zhu@student.manchester.ac.uk";
 FILE *fptr = fopen("certificate.txt", "w");
if (fptr == NULL) { //To open the file
 printf("Error. Not able to open the file.");
 return EXIT_FAILURE;
 }

 time_t t = time(NULL); // Get current time and format it
 struct tm *tm = localtime(&t);
 char dateStr[20]; // Ensure the buffer is large enough
strftime(dateStr, sizeof(dateStr), "%b %d %Y", tm); // Format date as "Apr 15 2021"

 
 fprintf(fptr, "Hello. My email address is:\n");
 fprintf(fptr, "%s\n", email);
fprintf(fptr, "I completed the course on %s", dateStr); //To show the outputs

 fclose(fptr); // Close and clean up
 fptr = NULL;
 return EXIT_SUCCESS;
}