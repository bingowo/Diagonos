#include<stdio.h>
#include<math.h>
typedef long long ll;
ll Newton(ll p)
{
    if(p==0)return 0;
    if(p==1)return 1;
    ll a=p/2;
    while(1)
    {
        a=(a+p/a)/2;
        if(a*a<=p&&(a+1)*(a+1)>p)return a;
    }
}
int main()
{
    double p,n1;
    ll n,basex,basey,mov,d=0,ansx,ansy;scanf("%lf",&p);n1=sqrt(p);n=(ll)n1;
    if(n%2)
    {
        basey=(n+1)/2;
        basex=(n-1)/2;
        mov=p-n*n;
        while(mov)
        {
            basex-=1;
            d++;
            mov--;
            if(d==n){break;}
        }
        ansx=basex;
        while(mov)
        {
            basey-=1;
            mov--;
        }
        ansy=basey;
    }
    else
    {
        basey=-n/2;
        basex=-n/2;
        mov=p-n*n;
        while(mov)
        {
            basex+=1;
            d++;
            mov--;
            if(d==n){break;}
        }
        ansx=basex;
        while(mov)
        {
            basey+=1;
            mov--;
        }
        ansy=basey;
    }
    printf("(%lld,%lld)",ansx,ansy);
    return 0;
}