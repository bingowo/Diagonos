#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
   int T,i;
   int d=0;
   long long int ans=0;
   int num=1;
   scanf("%d",&T);
   char s[61];
   for(int k=0;k<T;k++)
   {
        int a[128];  for (i=0;i<128;i++) a[i]=-1;
       scanf("%s",&s);
       char *p=s;
       a[*p]=1;
       while(*++p)
       {
           if(a[*p]==-1)
           {
               a[*p]=d;
               num++;
               if(d==0) d=2;
               else d++;
           }
       }
    if(num<2) num=2;
    p=s;
   while(*p!=0)
   {
       ans=ans*num+a[*(p++)];
   }
    printf("case #%d:\n%lld\n",k,ans);
    ans=0;
    d=0;
    num=1;
   }
}
