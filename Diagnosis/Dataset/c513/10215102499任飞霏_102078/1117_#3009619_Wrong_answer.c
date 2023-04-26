#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long Che(long long x0,long long y0,long long x,long long y)
{
    long long int ansx=0,ansy=0;
    ansx=llabs(x0-x);
    ansy=llabs(y0-y);
    if(ansx>=ansy)return ansx;
    else
        return ansy;
}

int main()
{
    long long x0,y0;
    int n;
    scanf("%lld%lld",&x0,&y0);
    scanf("%d",&n);
    long long min=2e15,ansx=0,ansy=0;
    for(int t=0;t<n;t++){
        long long x,y;
        scanf("%lld%lld",&x,&y);
        long long c=Che(x0,y0,x,y);
        if(c<=min){
            ansx=x;
            ansy=y;
            min=c;
        }

    }
    printf("%d\n%d %d",min,ansx,ansy);
    return 0;
}
