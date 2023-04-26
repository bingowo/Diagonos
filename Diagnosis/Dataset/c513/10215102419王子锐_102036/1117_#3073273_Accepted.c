#include<stdio.h>

#include<limits.h>
long long max(long long a,long long b)
{
    if(a<b)return b;
    else return a;
}
long long abss(long long x)
{
    if(x>0)return x;
    else return -x;
}
int main()
{
    long long x0,y0;
    scanf("%lld%lld",&x0,&y0);
    int n,cnt=0;
    scanf("%d",&n);
    long long tempdistance,distance=LLONG_MAX;
    long long x,y,xprintf,yprintf;
    while((scanf("%lld",&x))!=-1)
    {
        scanf("%lld",&y);
        if(cnt==0){
            xprintf=x;
            yprintf=y;
            cnt++;
        }
        tempdistance=max(abss(x-x0),abss(y-y0));
        if(tempdistance<distance){distance=tempdistance,xprintf=x,yprintf=y;}
        else if(tempdistance==distance){
            if(x<xprintf){xprintf=x,yprintf=y;}
            else if(x==xprintf&&y<yprintf)yprintf=y;}
    }
    printf("%lld\n%lld %lld\n",distance,xprintf,yprintf);
    return 0;
}