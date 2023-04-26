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
int pos(ll a,ll x,ll y)
{
    int d;
    d=(int)(log((double)a)/log(2))+1;
    if(labs(x)>labs(a) || labs(y)>labs(a)){return -1;}
    else if(a==pow2(d)-1){return d;}
    else if(a==pow2(d-1)+1){return d;}
    else{return -1;}
}
int main()
{
    int i;
    ll x,y;
    scanf("%lld %lld",&x,&y);
    if(pos(x+y,x,y)>0){printf("%d",pos(x+y,x,y));}
    else if(pos(x-y,x,y)>0){printf("%d",pos(x-y,x,y));}
    else if(pos(-x+y,x,y)>0){printf("%d",pos(-x+y,x,y));}
    else if(pos(-x-y,x,y)>0){printf("%d",pos(-x-y,x,y));}
    else{printf("-1");}
}
