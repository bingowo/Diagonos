#include<stdio.h>
typedef long long ll;
int main()
{
    ll x,y,d;
    scanf("%lld %lld",&x,&y);
    d=x>0?x:-x+y>0?y:-y;
    if(!d){printf("1");return 0;}
    if(!(d%2)){printf("-1");return 0;}
    d++;
    int cnt=1;
    while(d/2){cnt++;d/=2;}
    printf("%d",cnt);
    return 0;
}