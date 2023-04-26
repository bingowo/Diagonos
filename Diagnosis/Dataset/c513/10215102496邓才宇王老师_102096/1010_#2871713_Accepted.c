#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
   char s[500];
   scanf("%s",s);
   printf("%d%d%d%d",0,0,0,1);
   int m=strlen(s);
   int a[10];
    for(int i=0;i<10;i++) a[i]=0;
    int b=9;
    while(m/2)
    {
        a[b--]=m%2;
        m=m/2;
    }
    a[b]=m;
    for(int q=0;q<10;q++) printf("%d",a[q]);
   char *p=s;
   int num=0;
   int ans=0;
   while(*p)
   {
       ans=ans*10+*p-'0';
       num++;
       if(num==3)
       {
           num=0;
           int s1[10];
           for(int i=0;i<10;i++) s1[i]=0;
           int j=9;
           while(ans/2)
           {
               s1[j--]=ans%2;
               ans=ans/2;
           }
           s1[j]=ans;
           for(int q=0;q<10;q++) printf("%d",s1[q]);
           ans=0;
       }
       p++;
   }
   if(num==2)
   {
        int s2[7];
           for(int i=0;i<7;i++) s2[i]=0;
           int j=6;
           while(ans/2)
           {
               s2[j--]=ans%2;
               ans=ans/2;
           }
           s2[j]=ans;
            for(int q=0;q<7;q++) printf("%d",s2[q]);
   }
   if(num==1)
   {
        int s3[4];
           for(int i=0;i<4;i++) s3[i]=0;
           int j=3;
           while(ans/2)
           {
               s3[j--]=ans%2;
               ans=ans/2;
           }
           s3[j]=ans;
            for(int q=0;q<4;q++) printf("%d",s3[q]);
   }
}
