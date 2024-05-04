#include <stdio.h>

int main() {
    char my_email[] = "yujin.zhu@student.manchester.ac.uk";

    int n; 

    printf("Enter an integer: ");
    scanf("%d", &n);

  
    if (n < 0) {
        printf("Error");
        return 1; 
    }

    
    if (n >= sizeof(my_email) / sizeof(my_email[0]) - 1) {
        printf("Error");
        return 1; 
    }

    switch (my_email[n]) {
        case 'a': case 'e': case 'i': case 'o': case 'u':  
        case 'A': case 'E': case 'I': case 'O': case 'U':  
            printf("Vowel");
            break;
        default:
            printf("Not vowel");
    }

    return 0;
}