/*Given an nonnegative integer array, find a subarray where the sum of numbers is k. Your code should return the index of the first number and the index of the last number.
Given [1, 4, 20, 3, 10, 5], sum k = 33, return [2, 4].
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100

int main()
{
    int i, j = 0, n, a[N] = {0}, targetsum;
    char b[N];

    printf("Input your candidate numbers (example:[1,4,20,3,10,5]\\n):\n");
    getchar();
    gets(b);
    for(i = 0 ; i < N ; i++)
    {
        for( ; j < N ; j++)
        {
            if(b[j] != ',' && b[j] != ']') a[i] = a[i]*10 + b[j] - '0';
            else {j++; break;}
        }
        if(b[j] == '\0') break;
    }
    n = i + 1;

    printf("\nInput your sum:\n");
    scanf("%d", &targetsum);

    int first = 0, sum = 0;
    for(i = first ; i < n && sum < targetsum; i++)
    {
        sum += a[i];
        while(sum > targetsum)
        {
            sum -= a[first];
            first++;
        }
    }

    printf("\n[%d,%d]", first, i - 1);


    return 0;
}
