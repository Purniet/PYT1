/*����һ����Ӣ����ĸ�Ϳո���ɵľ��ӣ����ܻ����һ�������ո񣬲����ִ�Сд

��1������þ�������ĸ�ĸ���
��2������þ����е��ʵĸ���
��3������þ����г��ִ���������ĸ�ʹ���
���磺���룺This   Is my love
�������ĸ������12�����ʸ�����4�����ִ���������ĸ��i s�����ִ�����2
*/

#include <stdio.h>
#include <stdlib.h>
#define N 50

int main()
{
   char a[N];
   gets(a);
   int zimu=0,danci=1;
   int A[26]={0};
   int i,k;
   if(a[0]==' ') danci=0;
   for(i=0;a[i]!='\0';i++)
   {
       if(a[i]>='a'&&a[i]<='z')
       {
           zimu++;
           k=a[i]-'a';
           A[k]++;
       }
       if(a[i]>='A'&&a[i]<='Z')
       {
           zimu++;
           k=a[i]-'A';
           A[k]++;
       }
       if(a[i]==' ')
       {
           for(;a[i+1]==' ';i++);
           danci++;
           if(a[i+1]=='\0') danci--;
       }
   }
   int max=0;
   for(i=0;i<26;i++)
   {
       if(max<A[i]) max=A[i];
   }
   printf("��ĸ���� %d�����ʸ�����%d ",zimu,danci);
   printf("���ִ���������ĸ��");
   for(i=0;i<26;i++)
   {
       if(max==A[i]) printf("%c ",'a'+i);
   }
   printf("���ִ�����%d",max);
    return 0;
}
