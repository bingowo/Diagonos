#include<stdio.h>
typedef long long ll;
ll Newton(ll p)
{
    ll a=p/2+1;
    while(1)
    {
        a=(a+p/a)/2;
        if(a*a<=p&&(a+1)*(a+1)>p)return a;
    }
}
int main()
{
    ll p,n,basex,basey,mov,d=0,ansx,ansy;scanf("%lld",&p);n=Newton(p);
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