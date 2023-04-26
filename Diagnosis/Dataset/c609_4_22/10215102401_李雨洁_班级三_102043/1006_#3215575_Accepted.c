#include <stdio.h>
#include<string.h>
int main()
{
   int T,r;
   scanf("%d",&T);
   int a[1000];//对s中的数进行编码
   char s[61];
   for(int i=0;i<T;i++)
   {
       scanf("%s",s);
       memset(a,-1,sizeof(a));//初始化a
       r=0;
       for(int j=0;j<strlen(s);j++)
       {
           int m=(int)s[j];
           if(a[m]==-1) a[m]=++r;
       }
       long long end=0;
       int j=0,t;
       while(j<strlen(s))
       {
           int m=(int)s[j];
           if(a[m]==1 && r!=1) t=2;
           else if(a[m]==2) t=1;
           else if(r==1)
           {
              t=2;r=2;
           }
           else t=a[m];
           end=end*r+t-1;
           j++;
       }
       printf("case #%d:\n",i);
       printf("%lld\n",end);
   }
   return 0;
}
