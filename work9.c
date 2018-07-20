/*You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order,
 such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

Example
Given 7->1->6 + 5->9->2. That is, 617 + 295.
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100

int main()
{
    int i, m, n, p = 0, q = 0; char c;
    int a[N], b[N] ,s[N];
    printf("Input your first linked list ending with \"\\n\"( example:7->1->6\"\\n\"):\n");
    for(i = 0 ; i < N ; i++ )
    {
        scanf("%d-" , &a[i] );
        if( (c = getchar()) == '\n') break;
    }
    m = i + 1;
    printf("Input your second linked list ending with \"\\n\"( example:5->9->2\"\\n\"):\n");
    for(i = 0 ; i < N ; i++ )
    {
        scanf("%d-" , &b[i] );
        if( (c = getchar()) == '\n') break;
    }
    n = i + 1;
    for(i = m - 1; i >= 0; i--)
    {
        p = p * 10 + a[i];
    }
    for(i = n - 1; i >= 0; i--)
    {
        q = q * 10 + b[i];
    }
    int sum = p + q;

    for(i = 0 ; ; i++)
    {
        s[i] = sum % 10;
        if(sum < 10) break;
        sum /= 10;
    }
    int j;
    for(j = i  ; j > 0 ; j-- ) printf( "%d->" , s[j] );
    printf( "%d" , s[j] );

    return 0;
}
