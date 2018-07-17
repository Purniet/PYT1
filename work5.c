/*Given an integer array, find a subarray with sum closest to zero.
Return the indexes of the first number and last number.

Example
Given [[-3, 1, 1, -3, 5],], return [0, 2], [1, 3], [1, 1], [2, 2] or [0, 4]

Challenge
O(nlogn) time
*/
#include <stdio.h>
#include <stdlib.h>
#define N 50
static int min = 999;


int main()
{
    int i, j, k, n, a[N], sum[N][N], absolute[N][N];
    char c;
    printf("Input your integer array ending with \"\\n\":(example:-3 1 1 -3 5\"\\n\")\n");
    for( i=0 ; i<N && scanf("%d" , &a[i]) && (c = getchar()) != '\n' ; i++) ;
    n = i + 1;
    for(i = 0 ; i < n ; i++)
    {
        for(j = i ; j < n ; j++)
        {
            for(k = i ; k <= j ; k++)
            {
                sum[i][j] += a[k];
            }
            if(sum[i][j] > 0) absolute[i][j] = sum[i][j];
            else absolute[i][j] = - sum[i][j];
            if(absolute[i][j] < min) min = absolute[i][j];

        }

    }
    for(i = 0 ; i < n ; i++)
    {
        for(j = i ; j < n ; j++)
        {
            if(min == absolute[i][j]) printf("[%d,%d] ",i,j);
        }

    }
    return 0;
}




