/*输入一个由英文字母和空格组成的句子，可能会出现一个或多个空格，不区分大小写

（1）输出该句子中字母的个数
（2）输出该句子中单词的个数
（3）输出该句子中出现次数最多的字母和次数
例如：输入：This   Is my love
输出：字母个数：12，单词个数：4，出现次数最多的字母：i s，出现次数：2
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
   printf("字母个数 %d，单词个数：%d ",zimu,danci);
   printf("出现次数最多的字母：");
   for(i=0;i<26;i++)
   {
       if(max==A[i]) printf("%c ",'a'+i);
   }
   printf("出现次数：%d",max);
    return 0;
}
