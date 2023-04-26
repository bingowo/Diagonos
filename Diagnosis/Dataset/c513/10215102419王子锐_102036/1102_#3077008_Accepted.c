#include<stdio.h>
#include<math.h>
typedef long long ll;

int main()
{
    ll p,n,basex,basey,mov,d=0,ansx,ansy;
    scanf("%lld",&p);
    n=(long long)sqrt(p);
    if(n*n>p)n-=1;
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