#include <stdio.h>
#include <stdlib.h>
#define N 100
static int uniting[N];

void QuicksortOutinPlace(int a[] ,int m1, int m2);
void unite(int a[], int m11, int m12, int b[], int m21, int m22, int key, int k);
int main()
{
    int i, n, a[N];
    char c;
    printf("Input your integer array ending with \"\\n\":(example:-3 1 1 -3 5\"\\n\")\n");
    for( i=0 ; i<N && scanf("%d" , &a[i]) && (c = getchar()) != '\n' ; i++) ;
    n = i + 1;
    QuicksortOutinPlace(a , 0, n-1);
    for(i = 0 ; i < n ; i++)
    {
        printf("%d ",uniting[i]);
    }
    return 0;
}

void QuicksortOutinPlace(int a[] ,int m1, int m2)
{
    if(m2 <= m1) return;

    int left[N] = {0}, right[N] = {0};
    int key = a[m1];
    int i = m1, j = m2, t, k = 0;
    for(t = m1 ; t <= m2 ; t++)
    {
        if(a[t] < key)
        {
            left[i] = a[t];
            i++;
        }
        if(a[t] == key)
        {
            k++;
        }
         if(a[t] > key)
        {
            right[j] = a[t];
            j--;
        }
    }
    int p = i - m1;



    unite(left , m1, m1 + p - 1, right, m1 + p + k, m2, key, k);

    QuicksortOutinPlace(left , m1, m1 + p - 1);
    QuicksortOutinPlace(right ,m1 + p + k, m2 );

}

void unite(int a[], int m11, int m12, int b[], int m21, int m22, int key,int k)
{
    int t, j ;
   for(t = m11 ; t <= m12 && m12 >= m11; t++ )
   {
       uniting[t] = a[t];
   }

   for(t = m12 + 1; t <= m21 - 1; t++ )
   {
       uniting[t] = key;
   }
   for(t = m21 ; t <= m22 && m22 >= m21; t++)
   {
       uniting[t] = b[t];
   }
   return ;

}
