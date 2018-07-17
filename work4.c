/*Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".*/

#include <stdio.h>
#include <stdlib.h>
#define N 50
int main()
{
    char a[N][N],r[N][N],s[N];
    int i,n,j;
    gets(s);
    for(i=0,n=0;s[i]!='\0';i++,n++)
    {
        for(j=0;s[i+j]!=' '&&s[i+j]!='\0';j++)
        {
            a[n][j]=s[i+j];
        }
        a[n][j]='\0';
        i=i+j;
    }

    for(i=0;i<n;i++)
    {
       printf("%s ",a[n-i-1]);
    }

    return 0;
}
