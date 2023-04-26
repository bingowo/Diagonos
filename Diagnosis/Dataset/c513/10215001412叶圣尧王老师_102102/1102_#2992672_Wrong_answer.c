#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    long long n;scanf("%lld",&n);
    long k,d1,d2,d3,d4;
    if(n>4*100000000*100000000)k=100000001;
    else k=1;
    for(;;k++)
    {
        d1=4*k*k-6*k+2;
        d2=4*k*k-4*k+1;
        d3=4*k*k-2*k;
        d4=4*k*k;
        if(d1>=n){printf("(%lld,%lld)",k-1-d1+n,1-k);break;}
        if(d2>=n){printf("(%lld,%lld)",k-1,k-d2+n);break;}
        if(d3>=n){printf("(%lld,%lld)",-k+d3-n,k);break;}
        if(d4>=n){printf("(%lld,%lld)",-k,-k+d4-n);break;}
    }
}