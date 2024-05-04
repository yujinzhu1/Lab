#include <stdio.h>
int main(void){
    
	double num;
	FILE *fptr;
	fptr = fopen("number.txt", "r");//open the file
	if(fptr == NULL) { // display error if can't open file
        printf("Error. Not able to open the file.");
		return 1;
        }
	fscanf(fptr, "%lf", &num);
	fclose(fptr);
	

	// Your code below here
	printf("{\n");
    printf("  \"name\": \"yujin zhu\",  \n");
    printf("  \"email\": \"yujin.zhu@student.manchester.ac.uk\",     \n");
    printf("  \"number1\": %.2f, \n", num);  // Print num formatted to 2 decimal places
    printf("  \"number2\": %.3e\n", num);  // Print num in scientific notation with 3 digits after the decimal
    printf("}\n");
	
	
	// Do not edit below here
	return 0;
}