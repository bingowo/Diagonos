#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
     int T;
     int x,y;
     scanf("%d",&T);
     for(int i=1;i<=T;i++)
     {
         scanf("%d %d",&x,&y);
         int ans=0;
         int n=x^y;
         while(n!=0)
         {
             ans+=n&1;
             n=n>>1;
         }
         printf("%d\n",ans);

     }
     return 0;
}
