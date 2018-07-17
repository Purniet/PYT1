/*求最长公共子串，Given A = "ABCD", B = "CBCE", return 2*/

#include <stdio.h>
#include <stdlib.h>
#define N 20

int main()
{
    char a[N],b[N];
    gets(a);
    gets(b);
    int i,j,k[N][N]={0},max=0;
    for(i=0;a[i]!='\0';i++)
    {
        for(j=0;b[j]!=0;j++)
        {
            if(b[j]==a[i])
            {
                if(i>0&&j>0) k[i][j]=k[i-1][j-1]+1;
                else k[i][j]=1;
                if(max<k[i][j]) max=k[i][j];
            }
        }
    }

    printf("%d",max);
    return 0;
}
