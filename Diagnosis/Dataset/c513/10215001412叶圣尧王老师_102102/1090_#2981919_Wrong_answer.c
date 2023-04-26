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
        int k=t;
        printf("%.0lf\n",pow(10,t-k));
    }
}