/*The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the _n_th sequence.
Note: The sequence of integers will be represented as a string
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100

int main()
{
    char a[N], b[N];
    int number[N], count[N];
    printf("Input your integer:\n");
    gets(a);

    int i, j = 0;
    for(i = 0 ; a[i] != '\0' ; i++, j++)
    {
        number[j] = a[i] - '0';
        count[j] = 1;
        while(a[i] == a[i + 1])
        {
            i++;
            count[j]++;
        }
    }
    int n = j;
    for(i = 0, j = 0; j < n ; j++)
    {
        b[i] = count[j] + '0';
        i++;
        b[i] = number[j] + '0';
        i++;
    }
    printf("\n");
    for(j = 0 ; j < i ; j++)
    {
        printf("%c", b[j]);
    }

    return 0;
}
