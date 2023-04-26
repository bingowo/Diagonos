#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>






int main()

{

    int t;
    scanf("%d",&t);
    for(int i =0;i<t;i++)

    {
        long long int a,b,n,res;
   scanf("%lld%lld%lld",&a,&b,&n);
   res = 1;
   long long int base =1;
   for(int i=0;i<n;i++)base*=10;
   for(int k=0; k<b;k++)
   {
       res*=a;
       if(res>=base)res%=base;
   }
   int n1 =1;
   long long a_ = res;
   while(a_)
   {
       n1++;
        a_/=10;
   }
    printf("case #%d:\n",i);
   for(n1;n1<n;n1++)
    {
        printf("0");
    }
    printf("%lld",res);
    if(i!=t-1)printf("\n");
    }
    return 0;
}
