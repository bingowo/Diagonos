#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long long mul(int a,int b)
{
    long long k=1;
    for(int i=0;i<b;i++)k=k*a;
    return k;
}

int main()
{
    int T;scanf("%d",&T);
  for(int j=0;j<T;j++)
  {
    long long n;scanf("%lld",&n);
    long long mul(int a,int b);
    int a=2,b,m=0;int ka[20],kb[20];
    for(b=2;a>1&&n!=1;b++)
    {
        a=(int)pow(n,1.0/b);
        if(mul(a,b)==n){ka[m]=a;kb[m]=b;m++;}
        else if(mul(a+1,b)==n){ka[m]=a+1;kb[m]=b;m++;}
    }
    if(m==0)printf("%lld is powerless.\n",n);
    else
    {
        printf("%lld",n);
        for(int i=0;i<m;i++)
        {
            printf("=%d^%d",ka[i],kb[i]) ;
        }
        printf("\n");
    }
   }
}