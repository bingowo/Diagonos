#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
     int T;
     scanf("%d",&T);
     int n;
     for(int i=1;i<=T;i++)
     {
         scanf("%d",&n);
         int ans=1;
         int max=1;
         while(n!=0)
         {
             int a=n&1;
             n=n>>1;
             if(n==0) break;
             int b=n&1;
             if(a!=b) ans++;
             if(ans>max) max=ans;
             if(a==b) ans=1;
         }
         printf("case #%d:\n",i-1);
         printf("%d\n",max);
     }
     return 0;
}
