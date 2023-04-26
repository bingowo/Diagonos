#include<stdio.h>
typedef long long ll;
int main()
{
    ll x,y,d,t=1;
    scanf("%lld %lld",&x,&y);
    d=(x>0?x:-x)+(y>0?y:-y);
    if(!d){printf("0");return 0;}
    if(!(d%2)){printf("-1");return 0;}
    d++;
    int cnt=0;
    while(d>t){cnt++;t<<=1;}
    printf("%d",cnt);
    return 0;
}
