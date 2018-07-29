/*Given three strings: s1, s2, s3,
determine whether s3 is formed by the interleaving of s1 and s2.

Example
For s1 = "aabcc", s2 = "dbbca"

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100

static char s1[N], s2[N], s3[N];
static int tag;

void put(int k1, int k2, int k3);

int main()
{

    printf("Input s1:\n");
    gets(s1);
    printf("\n");
    printf("Input s2:\n");
    gets(s2);
    printf("\n");
    printf("Input s3:\n");
    gets(s3);
    printf("\n");

    put(0, 0, 0);

    if(tag == 1) printf("\nture");
    else printf("\nflase");

    return 0;
}

void put(int k1, int k2, int k3)
{
    if(s3[k3] == '\0')
    {
        if(s1[k1] == '\0' && s2[k2] == '\0') tag = 1;
        return;
    }
    if(s3[k3] == s1[k1]) put(k1 + 1, k2, k3 + 1);
    if(s3[k3] == s2[k2]) put(k1, k2 + 1, k3 + 1);

}
