/*Given a list of numbers with duplicate number in it. Find all unique permutations.

Example
For numbers [1,2,2] the unique permutations are:

[

    [1,2,2],

    [2,1,2],

    [2,2,1]

]
不使用递归
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100
#define M 9999

void swap(int *a, int *b);
void reverse(int a[], int t, int n);

int main()
{
    int n, i, k, j = 0, a[N] = {0}, number[N] = {0};
    char c[N];

    printf("Input your list of numbers (example:[1,2,2]\\n):\n");
    getchar();
    gets(c);
    for(i = 0 ; i < N ; i++)
    {
        for( ; j < N ; j++)
        {
            if(c[j] != ',' && c[j] != ']') number[i] = number[i]*10 + c[j] - '0';
            else {j++; break;}
        }
        if(c[j] == '\0') break;
    }
    n = i + 1;
    for(i = 0 ; i < n ; i++)
    {
        a[i] = i;
    }

    int count = 0, q, tag = 0, b[M][n];

    for(;;)
    {

        for(k = 0 ; k < n ; k++)
        {
            b[count][k] = a[k];
        }

        for(i = n - 2 ; i >= 0 ; i--)
        {
            if(a[i] < a[i + 1]) break;
        }

        if(i < 0) i = 0;
        tag = 1;
        for(q = n - 2 ; q >= 0 ; q--)
        {
            if(a[i] < a[i + 1]) tag = 0;
        }
        if(tag == 1) break;

        int min = a[i + 1];
        for(j = i + 1 ; j < n ; j++)
        {
            if(a[j] > a[i] && a[j] < min ) min =a[j];
        }
        for(j = i + 1 ; j < n ; j++)
        {
            if(min == a[j]) break;
        }
        swap(&a[i], &a[j]);
        reverse(a, i + 1, n);
        count++;
    }


    int replicate[M] = {0};
    for(i = 0 ; i < count ; i++)
    {
        for(j = i + 1; j <= count ;j++)
        {
            int m = 0;
            for(k = 0; k < n ; k++)
            {
                if(number[b[i][k]] == number[b[j][k]]) m++;
            }
            if(m == n) replicate[i] = 1;
        }
    }

    printf("\nthe unique permutations are:\n");
    k = 0;
     for(i = 0 ; i <= count ; i++)
        {
            if(!replicate[i])
            {
                printf("%d: [",++k);
               printf("%d", number[b[i][0]]);
               for(j = 1 ; j < n ; j++)
                {
                    printf(",%d", number[b[i][j]]);
                }
                printf("]\n");

            }


        }



    return 0;
}


void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void reverse(int a[], int t, int n)
{
    int i, j;
    for(i = t, j = n - 1 ; i < j  ; i++, j--)
    {
        swap(&a[i], &a[j]);
    }
}
