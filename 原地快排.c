#include <stdio.h>
#include <stdlib.h>
#define N 100

void Quicksort(int a[] , int left , int right);

int main()
{
    int i, n, a[N];
    char c;
    printf("Input your integer array ending with \"\\n\":(example:-3 1 1 -3 5\"\\n\")\n");
    for( i=0 ; i<N && scanf("%d" , &a[i]) && (c = getchar()) != '\n' ; i++) ;
    n = i + 1;
    Quicksort(a , 0 ,n - 1);
    for(i = 0 ; i < n ; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

void Quicksort(int a[] , int left , int right)
{
    if(left >= right) return;

    int i = left, j = right;
    int key = a[i];
    for(;i<j;)
    {
        for(;;j--)
        {
            if(i == j) break;
            if(key > a[j])
            {
                int t;
                t = a[i];
                a[i] = a[j];
                a[j] = t;
                break;
            }

        }
         for(;;i++)
        {
            if(i == j) break;
            if(key < a[i])
            {
                int t;
                t = a[i];
                a[i] = a[j];
                a[j] = t;
                break;
            }
        }

    }
    a[i] = key;
    Quicksort(a, left ,i - 1);
    Quicksort(a, i + 1 ,right);
}
