#include <stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
ll a,b;
double n;
ll gcd(ll a,ll b)
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