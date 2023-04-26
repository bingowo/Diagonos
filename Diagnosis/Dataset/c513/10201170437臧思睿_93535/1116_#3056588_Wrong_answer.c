#include <stdio.h>
#include <math.h>
typedef long long int ll;

ll pow2(int b)
{
    ll r=1;
    for(int j=0;j<b;j++)
    {
        r*=2;
    }
    return r;
}
int pos(ll a)
{
    int d;
    d=(int)(log((double)a)/log(2));
    if(a==pow2(d)+1){return d+1;}
    else{return -1;}
}
int main()
{
    int i;
    ll x,y;
    scanf("%lld %lld",&x,&y);
    if(pos(x+y)>0){printf("%d",pos(x+y));}
    else if(pos(x-y)>0){printf("%d",pos(x-y));}
    else if(pos(-x+y)>0){printf("%d",pos(-x+y));}
    else if(pos(-x-y)>0){printf("%d",pos(-x-y));}
    else{printf("-1");}
}
