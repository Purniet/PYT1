/*Given an unsorted array of integers, find the length of longest increasing subsequence.
For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4
Challenge ： O（nlogn）
*/
#include <stdio.h>
#include <stdlib.h>
#define N 999
void pick(int x, int length);

static int a[N], n, maxlength, tag[N][N];

int main()
{
    int i, j = 0;
    char b[N];

    printf("Input your unsorted array of integers (example:[10,9,2,5,3,7,101,18]\\n):\n");
    getchar();
    gets(b);
    for(i = 0 ; i < N ; i++)
    {
        for( ; j < N ; j++)
        {
            if(b[j] != ',' && b[j] != ']') a[i] = a[i]*10 + b[j] - '0';
            else {j++; break;}
        }
        printf("%d ",a[i]);
        if(b[j] == '\0') break;

    }
    n = i + 1;

    for(i = 0 ; i < n ; i++)
    {
        if(tag[i] == 0) pick(i, 0);
    }

    printf("\n%d",maxlength);
    return 0;
}

void pick(int x, int length)
{
    int i;
    length++;
    for(i = x + 1; i < n ;i++)
    {
        if(a[i] > a[x])
        {
            tag[i] = 1;
            pick(i, length);
        }
    }
    if(length > maxlength) maxlength = length;
}
