#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>



int main()
{
    long long n;
    while(scanf("%lld",&n)!=EOF)
    {
        double t=n*log10(n);
        long long k=t;
        double f=pow(10,t-k);
        printf("%.0lf\n",f);
    }
}