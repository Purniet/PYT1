/*给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

#include <stdio.h>
#include <stdlib.h>
#define N 100

int n;
static int count[N][N] = {0},c[N][N] = {0}, k = 0 ,replicate[N]={0};
void pick(int a[],int t);
void dereplicate(int a[]);
int main()
{
    int i ,j = 0;
    char a[N];
    int b[N] = {0};
    printf("Input your integer array (example:[1,2,2]\\n):\n");
    getchar();
    gets(a);
    for(i = 0 ; i < N ; i++)
    {
        for( ; j < N ; j++)
        {
            if(a[j] != ',' && a[j] != ']') b[i] = b[i]*10 + a[j] - '0';
            else {j++; break;}
        }
        if(a[j] == '\0') break;
    }
    n = i + 1;
    pick(b, 0);

    dereplicate(b);
    for(i = 0 ; i < k ; i++)
    {
        if(replicate[i] == 1)
        {
            i++;
            continue;
        }
        printf("[");
        int q = 0;
        for(q = 0; q < n ; q++)
        {
            if(c[i][q]) {printf("%d",b[q]); break;}

        }
        for(j = q + 1; j < n ; j++)
        {
            if(c[i][j]) printf(",%d",b[j]);
        }

        printf("],\n");
    }
    return 0;
}

 void pick(int a[],int t)
{
    int i;
    if(t > n - 1)
    {
        k += 1;
        return;
    }
    pick(a, ++t);
    for(i=0;i<t;i++)
    {
        c[k][i]=c[k-1][i];
    }
    t--;
    c[k][t] = 1;
    pick(a, ++t);
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
