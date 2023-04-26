#include <stdio.h>

void process(long long n, int R)
{ if  (n>0) process(n/R,R),printf("%d ", n%R );  }

int main()
{   int i,T;
     for(scanf("%d",&T),i=0;i<T;i++)
     {    long long n; int R=2333;
//           printf("case #%d:\n",i);
           scanf("%lld",&n);
           if (n==0) printf("0"); else process(n,R);printf("\n");
     }

    return 0;
}
