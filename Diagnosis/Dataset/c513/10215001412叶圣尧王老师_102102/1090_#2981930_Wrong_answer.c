#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>



int main()
{
    double n;
    while(scanf("%lfd",&n)!=EOF)
    {
        double t=n*log10(n);
        long long k=t/1;
        double f=pow(10,t-k);
        printf("%.0lf\n",f);
    }
}