#include <stdio.h>
#include <stdlib.h>


long long mod[100000];

int main()
{
   int i,n;
   scanf("%d",&n);
   memset(mod,0,sizeof(mod));
   for (i=1;i<100000;i++)
   {
       mod[i]=mod[i/2]*10+i%2;
       if (mod[i]%n==0 && mod[i]/n>1)
       {
           printf("%lld\n",mod[i]);
           break;
       }
   }
   if (i==100000)
    printf("-1\n");


    return 0;
}
