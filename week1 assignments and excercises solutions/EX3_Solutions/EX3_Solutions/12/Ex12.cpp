
 
#include <stdio.h>

int string_length(char str[])
{
	int i;
	/* count the string start from element 0 until the element before the NULL terminator */
	for(i = 0; str[i] != '\0'; ++i);
	return i;
}

int main()
{
    char s[1000], length;

    printf("Enter a string: ");
   scanf("%s", s);

	length = string_length(s);
	
    printf("Length of string: %d", length);
    return 0;
}
