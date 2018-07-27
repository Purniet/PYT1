/*
Given a collection of candidate numbers (candidates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100
#define M 9999


static int c[M][N], target, n, a[N], k, d[M],replicate[M],count[M][N];

void pick(int t, int w);
void dereplicate(int a[]);

int main()
{
    int i, j = 0;
    char b[N];

    printf("Input your candidate numbers (example:[1,2,2]\\n):\n");
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

    printf("\nInput your target number:\n");
    scanf("%d", &target);
    pick(0, 0);
    dereplicate(a);


    for(i = 0 ; i < k ; i++)
    {
        if(d[i] == 0) continue;
        if(replicate[i] == 0)
      {



        printf("[");
        int q = 0;
        for(q = 0; q < n ; q++)
        {
            if(c[i][q]) {printf("%d",a[q]); break;}

        }
        for(j = q + 1; j < n ; j++)
        {
            if(c[i][j]) printf(",%d",a[j]);
        }

        printf("],\n");
      }
    }

    return 0;
}

void pick(int t, int w)
{
    int i;

    if(t > n - 1)
    {
        if(w == target) d[k] = 1;
        k += 1;
        return;
    }

    pick(t+1,w);

    if(w+a[t]<=target)
 {
     for(i=0;i<t;i++)
    {
        c[k][i]=c[k-1][i];
    }
    c[k][t] = 1;

    pick(1+t,w+a[t]);
 }

}

void dereplicate(int a[])
{
    int i, j, t, m;
    for(i = 0; i < k ; i++)
    {
        for(j = 0; j < n  ; j++)
        {
            if(c[i][j] == 1 )
            {
                m=a[j];
            count[i][m] += 1;
            }

        }

    }

     for(i = 0; i < k - 1 ; i++)
    {
        for(t = i+1; t < k  ; t++)
        {
            int p = 0;
            for(j = 0; j < N ; j++)
            {
                if(count[t][j] == count[i][j]) p++;
            }
            if(p == N) replicate[i] = 1;

        }

    }
    replicate[k-1] = 0;
}
