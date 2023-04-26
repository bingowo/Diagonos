#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int main()
{
   long long a,b,ans=0,i,i0,j,f=1;
   scanf("%lld%lld",&a,&b);
   for(i=a;i<=b;i++)
   {
       if(i%9==0)continue;
       else
       {
           i0=i;
           while(i0)
           {
               j=i0%10;
               if(j==9){f=0;break;}
               i0/=10;
           }
           if(f)ans++;
           f=1;
       }
   }
   printf("%lld",ans);
   return(0);
}
