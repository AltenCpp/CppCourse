
#include <stdio.h>

int main()
{
    int sum=0;
    int i;
    for(i=0;i<100;i++)
    {
        sum += i;
    }
    printf("sum of the first 100 integer numbers equals : %d\n",sum);
	
	/* Check if the sum of the 100 number is correct */
    if(sum == 4950)
    {
        printf("sum of the first 100 integer numbers is correct\n");
    }
    else
    {
        printf("sum of the first 100 integer numbers is not correct\n");
    }
	
    return 0;
}
