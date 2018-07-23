/*Ugly number is a number that only have factors 3, 5 and 7.

Design an algorithm to find the Kth ugly number.
The first 5 ugly numbers are 3, 5, 7, 9, 15 бн

Example
If K=4, return 9.
Challenge
O(K log K) or O(K) time.
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100
static int a[N];
static int x3, x5, x7, k;
void UglyNumber(int i);
int main()
{
    printf("Input K:\n");
    scanf("%d", &k);
    a[0] = 1;
    UglyNumber(0);
    printf("%d", a[k]);
    return 0;
}

void UglyNumber(int i)
{
    if(i >= k) return;


    int y3, y5, y7, min = 9999;
    y3 = a[x3] * 3;
    y5 = a[x5] * 5;
    y7 = a[x7] * 7;
    min = (y3 < y5)?y3:y5;
    if(y7 < min)
    {
        min = y7;
        x7++;
    }
    if(min == y3)
    {
        x3++;
    }
    if(min == y5)
    {
        x5++;
    }
    if(min == a[i]) i--;
    a[++i] = min;

    UglyNumber(i);
}
