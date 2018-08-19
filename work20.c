/*在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
#include <stdio.h>
#include <stdlib.h>

int decide(int *p, int m, int n, int x);

int main()
{
    int m, n, x;
    printf("Input the number of lines in your dyadic array(example:3):\n");
    scanf("%d", &m);
    printf("\nInput the number of columns in your dyadic array(example:4):\n");
    scanf("%d", &n);
    printf("\nInput the elements of your dyadic array in turn(example:1 2 3 4 5 6 7 8 9 10 11 12):\n");
    int a[m][n], i, j;
    for(i = 0 ; i < m ; i++)
    {
        for(j = 0 ; j < n ; j++) scanf("%d", &a[i][j]);
    }
    printf("\nInput the integer(example:4):\n");
    scanf("%d", &x);
    int tag;
    tag = decide(a, m, n, x);
    if(tag == 1) printf("\nyes!");
    else printf("\nno!");
    return 0;
}

int decide(int *p, int m, int n, int x)
{
    int i, j;
    for(i = 0 ; i < m ; i++)
    {
        if(x >= *(p + i * n))
        {
            for(j = 0 ; j < n ; j++)
            {
                if(x == *(p + i * n + j)) return 1;
            }
        }
    }
    return 0;
}
