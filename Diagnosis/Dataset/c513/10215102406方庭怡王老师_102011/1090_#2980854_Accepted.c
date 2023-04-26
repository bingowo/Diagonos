#include <stdio.h>
#include <math.h>

long long int a,b;
double n;
long long int gcd(long long int a,long long int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
double fun(double n)
{
    double in,fr,t;
    fr=modf(n*log10(n),&in);
    t=pow(10,fr);
    modf(t,&in);
    return in;
}
int main()
{
    while(scanf("%lf",&n)!=EOF){
        if(n-0<1e-10)
        {
            return 0;
        }
        printf("%.0lf\n",fun(n));
    }
    return 0;
}