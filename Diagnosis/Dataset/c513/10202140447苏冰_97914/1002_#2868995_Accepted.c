#include <stdio.h>
#include<string.h>
int main()
{
   int T,r;
   scanf("%d",&T);
   int a[130];
   char s[65];
   for(int i=1;i<=T;i++)
   {
       scanf("%s",s);
       memset(a,-1,sizeof(a));
       r=0;
       for(int j=0;j<strlen(s);j++)
       {
           int m=(int)s[j];
           if(a[m]==-1)
           {
               a[m]=++r;
           }
       }
       long long ans=0;
       int j=0;
       while(j<strlen(s))
       {
           int m=(int)s[j];
           int t;
           if(a[m]==1 && r!=1)
           {t=2;}
           else if(a[m]==2)
           {t=1;}
           else if(r==1)
          {
              t=2;
              r=2;
          }
           else
           {
               t=a[m];
           }
           ans=ans*r+t-1;
           j++;
       }
       printf("case #%d:\n",i-1);
       printf("%lld\n",ans);

   }
   return 0;

}
