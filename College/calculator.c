#include <stdio.h>
#include <stdlib.h>
#include<math.h>
 
int main()
{
    char c;
    float a, b;
    while (1) {
        printf("Enter (+, -,*,/,^=) operation you want to perform\nIf want to exit press X: ");
        scanf(" %c", &c);
        // to exit
        if (c == 'X')
            exit(0);
        printf("Enter two first and second number: ");
        scanf("%f %f",&a,&b);
        // Using switch case we will go to different operations to perform
        switch (c) {
       
        case '+':
            printf("Addition of %f and %f = %f\n", a, b, a + b);
            break;
            
            default:
            printf("Error! please write a valid operator\n");
        }
    }
    return 0;
}