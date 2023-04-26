#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

double f(double n)
{
    double in,fr,t;
    fr=modf(n*log10(n),&in);
    t=pow(10,fr);
    modf(t,&in);
    return in;
}
int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF)
    {
       if(n-0<1e-10) return 0;
       printf("%.0f\n",f(n)); 
    }
    return 0;
}