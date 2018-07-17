/*Write a removeDuplicates() function which takes a list and deletes
any duplicate nodes from the list. The list is not sorted.

For example if the linked list is 12->11->12->21->41->43->21,
then removeDuplicates() should convert the list to 12->11->21->41->43.

Challenge
O(n) time*/

#include <stdio.h>
#include <stdlib.h>
#define N 100

int main()
{
    int i, j, t, n; char c;
    int jishu[N] = {0} , a[N] , b[N];
    printf("Input your linked list ending with \"\\n\"( example:12->11->12->21->41->43->21\"\\n\"):\n");
    for(i = 0 ; i < N ; i++ )
    {
        scanf("%d-" , &a[i] );
        if( (c = getchar()) == '\n') break;
    }
    n = i+1;

    for(i = 0 , j = 0 ; i < n ; i++ )
    {
        t = a[i];
        jishu[t]++;
        if( jishu[t] > 1 ) continue;
        b[j] = a[i];
        j++;
    }
    for(i = 0 ; i < j-1 ; i++ ) printf( "%d->" , b[i] );
    printf( "%d" , b[i] );
    return 0;
}
