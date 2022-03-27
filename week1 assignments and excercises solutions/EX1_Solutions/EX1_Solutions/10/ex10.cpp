
#include "stdio.h"

int main() {

    char operatorvar;
    float firstNumber,secondNumber;
    double result;

    printf("Enter an operator + or - or * or % ");
    scanf("%c", &operatorvar);

    printf("\nEnter two operands: ");
    scanf("%f %f",&firstNumber, &secondNumber);
	
	/* Swicth case to perfrom the required operations */
    switch(operatorvar)
    {
        case '+':
        	result = firstNumber + secondNumber;
            printf("\n%f + %f = %lf",firstNumber, secondNumber, result);
            break;

        case '-':
        	result = firstNumber - secondNumber;
            printf("\n%f - %f = %lf",firstNumber, secondNumber, result);
            break;

        case '*':
        	result = firstNumber * secondNumber;
            printf("\n%f * %f = %lf",firstNumber, secondNumber, result);
            break;

        case '/':
        	result = firstNumber / secondNumber;
            printf("\n%f / %f = %lf",firstNumber, secondNumber, result);
            break;

        /* operator doesn't match any case constant (+, -, *, /) */
        default:
            printf("Error! operator is not correct");
    }

    return 0;
}