#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *p1,const void *p2)
{
    char* a=p1;
    char* b=p2;
    return *a-*b;
}
int main()
{
   int T;
   scanf("%d",&T);
   getchar();
   for(int i=0;i<T;i++)
   {
       char s[201];
       gets(s);
       char s1[201]="\0";
       char s2[201]="\0";
       int m=0;
       int n=0;
       for(int j=0;j<strlen(s);j++)
       {
           if(s[j]>=65&&s[j]<=90)
           {
               s1[m++]=s[j];
           }
           else s2[n++]=s[j];
       }
       qsort(s1,strlen(s1),sizeof(char),cmp);
       int num1=0;
       int num2=0;
       printf("case #%d:\n",i);
       for(int k=0;k<strlen(s);k++)
       {
           if(s[k]>=65&&s[k]<=90) printf("%c",s1[num1++]);
           else printf("%c",s2[num2++]);
       }
       printf("\n");
   }
}
