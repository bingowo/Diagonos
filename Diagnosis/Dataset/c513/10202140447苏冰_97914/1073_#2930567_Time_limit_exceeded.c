#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int x[100];
int main()
{
     long long a,b,m;
     scanf("%lld%lld",&a,&b);
     long long cnt=0;int k=0;
     for(long long i=a+1;i<b;i++)
     {
         k=0;
         if(i%9==0) cnt++;
         else
         {
             m=i;
             do
             {
                 x[k]=m%10;k++;m/=10;
                 if(x[k-1]==9)
                 {
                    cnt++;break;
                 }
             }while(m!=0);
         }
     }
     printf("%lld",b-a+1-cnt);
     return 0;
}
