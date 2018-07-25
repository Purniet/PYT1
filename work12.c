/*Write a method to replace all spaces in a string with %20. The string is given in a characters array,
you can assume it has enough space for replacement and you are given the true length of the string.

You code should also return the new length of the string after replacement.

Example

Given "Mr John Smith", length = 13.

The string after replacement should be "Mr%20John%20Smith", you need to change the string in-place and return the new length 17.
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100

int main()
{
    char a[N];
    printf("Input your string please:\n");
    gets(a);
    int i, length;
    for(i = 0 ; a[i] != '\0' ; i++);
    length = i;
    printf("\nBefore the replacement:\nstring:");
    for(i = 0 ; i < length ; i++) printf("%c", a[i]);
    printf("\n");
    printf("length:%d\n", length);

    char b[N];
    int j, length2;
    for(i = 0, j = 0; i < length ; i++, j++)
    {
        if(a[i] == ' ')
            {
                b[j] = '%';
                b[++j] = '2';
                b[++j] = '0';
            }
        else b[j] = a[i];


    }
    length2 = j;
    printf("\nAfter the replacement:\nstring:");
    for(i = 0 ; i < length2 ; i++) printf("%c", b[i]);
    printf("\n");
    printf("length:%d\n\n", length2);

    return 0;
}
