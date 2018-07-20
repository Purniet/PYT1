/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
#include <stdio.h>
#include <stdlib.h>
#define N 50

int main()
{
     int i, j, x, n; char c;
    int a[N] ;
    printf("Input your linked list ending with \"\\n\"( example:\"\\n\"):\n");
    for(i = 0 ; i < N ; i++ )
    {
        scanf("%d-" , &a[i] );
        if( (c = getchar()) == '\n') break;
    }
    n = i + 1;
    printf("Input your value x:\n");
    scanf("%d", &x);
    int b[n];
    for(i = 0, j = 0 ; i < n ;i++)
    {
        if(a[i] < x)
        {
            b[j] = a[i];
            j++;
        }
    }
    for(i = n - 1 , j = n - 1 ; i >= 0 ;i--)
    {
        if(a[i] >= x)
        {
            b[j] = a[i];
            j--;
        }
    }
    for(i = 0 ; i < n-1 ; i++ ) printf( "%d->" , b[i] );
    printf( "%d" , b[i] );
    return 0;
}
