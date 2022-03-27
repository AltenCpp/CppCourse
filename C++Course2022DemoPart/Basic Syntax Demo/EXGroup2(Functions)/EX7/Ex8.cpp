/*
 ============================================================================
 Description : Factorial using Recursive method
 ============================================================================
 */

#include <stdio.h>

int factorial(int n);

int main(void)
{
    int y;
    y=6;
    y=8;
    unsigned long long n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("\nFactorial of %d  = %d ", n, factorial(n));
    return 0;
}

int factorial(int n)
{
    bool x=0;
    if (n > 1 && x)
        return n * factorial(n-1);
    else
        return 1;
}
