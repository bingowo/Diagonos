#include <stdio.h>
#include <stdlib.h>

int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
       int n,r;
       scanf("%d%d",&n,&r);
       char s[100]={0};
       int sign=1;
       if(n<0)
       {
           sign=-1;
           n=-n;
       }
       int j=0;
       while(n)
       {
           int m=n%r;
           if(m<10) s[j++]=m+'0';
           if(m>10) s[j++]=m-10+'A';
           n/=r;
       }
       s[j]='\n';
       if(sign<0)printf("-");
       for(int k=j-1;k>=0;k--)
       {
           printf("%c",s[k]);
       }
       printf ("\n");
   }

}