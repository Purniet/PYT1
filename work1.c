/*����һ��������������ַ�������������������У��������ģ������ѭ��С����Ҫ�����ű�ʶѭ���塣
���磺
���룺8/5  �����1.6��������1.6000...��
���룺1/3   �����.(3)(������0.333...)
���룺11/13 �����.(846153)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
static int A=0;
static int B=0;
static int xs[N]={0},R[N];
static int t,r;

void chaifen(char a[]){
    int len=strlen(a);
    int i;
    for (i=0; i<=len; i++) {
        if (a[i]=='/') {break;}
        A=A*10+a[i]-'0';}
    for (i=i+1; i<len; i++) {
        B=B*10+a[i]-'0';
    }

}

void ans(int a,int b)
{
    int i,j;
    for(i=0;i<N;i++) R[i]=-1;
    r=b%a;
    for(t=0;r!=0&&R[r]==-1;t++)
    {
        R[r]=t;
        r=10*r;
        xs[t+1]=r/B;
        r=r%B;
    }


}

int main()
{
    char a[N];
   gets(a);
    chaifen(a);
    ans(B,A);
    int zheng,i;
    zheng=A/B;
    if(zheng>0) printf("%d",zheng);
    printf(".");
    if(r==0)
    {
        for(i=1;i<=t;i++) printf("%d",xs[i]);
    }
    else{
        for(i=1;i<=R[r];i++) printf("%d",xs[i]);
        printf("(");
        for(i=R[r]+1;i<=t;i++) printf("%d",xs[i]);
        printf(")");

    }


}
