/*Given n items with size A_i, an integer m denotes the size of a backpack. How full you can fill this backpack?

Example
If we have 4 items with size [2, 3, 5, 7], the backpack size is 11, we can select [2, 3, 5], so that the max size we can fill this backpack is 10. If the backpack size is 12. we can select [2, 3, 7] so that we can fulfill the backpack.

You function should return the max size we can fill in the given backpack.
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100
static int n, m, max, item[N];
void BackTrack(int i, int w);

int main()
{
    printf("Input the size of the backpack ending with \\n:\n");
    scanf("%d", &m);
    getchar();
    printf("Input the size of your items ending with \\n (example:[2,3,5]\\n):\n");
    char a[N];
    getchar();
    gets(a);
    int i, j = 0;
    for(i = 0 ; i < N ; i++)
    {
        for( ; j < N ; j++)
        {
            if(a[j] != ',' && a[j] != ']') item[i] = item[i]*10 + a[j] - '0';
            else {j++; break;}
        }
        if(a[j] == '\0') break;
    }
    n = i + 1;

    BackTrack(0, 0);

    printf("%d", max);
    return 0;
}

void BackTrack(int i, int w)
{
    if(i >= n)
    {
        if(w > max) max = w;
        return;
    }
    if(item[i] <= m - w)
    {
        BackTrack(i + 1, w + item[i]);
    }
    BackTrack(i + 1, w);
}
