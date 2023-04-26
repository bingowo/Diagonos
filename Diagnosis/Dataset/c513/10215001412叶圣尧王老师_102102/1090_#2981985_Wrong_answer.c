#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>



int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF)
    {
        double t=n*log10(n);
        int k=t;
        int f=pow(10,t-k);
        printf("%d\n",f);
    }
}