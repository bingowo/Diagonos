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
   char s[100];
   char *p;
   int a[128];  for (i=0;i<128;i++) a[i]=-1;
   for(int i=0;i<T;i++)
   {
       scanf("%s",&s);
       p=s;
       a[*p]=1;
       while(*(++p)!=0)
       {
           if(a[*p]==-1)
           {
               a[*p]=d;
               d=d?d+1:2;
               num++;
           }
       }
    if(num<2) num=2;
    p=s;
   while(*p!=0)
   {
       ans=ans*num+a[*(p++)];
   }
    printf("%lld",ans);
   }
}
