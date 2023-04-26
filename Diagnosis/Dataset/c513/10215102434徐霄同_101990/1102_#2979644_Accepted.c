#include <stdio.h>
#include <math.h>

int main()
{
    long long n,n0,n1,x,y;
    scanf("%lld",&n);
    n0=(long long)sqrt(n);
    n1=n-n0*n0;
    if(n1<0){
        n0--;
        n1=n-n0*n0;
    }
    if(n0%2==0){
        x=-n0/2;
        y=-n0/2;
        if(n1<=n0)
            x=x+n1;
        else{
            x=x+n0;
            y=y+(n1-n0);
        }
    }
    else{
        x=(n0-1)/2;
        y=(n0+1)/2;
        if(n1<=n0)
            x=x-n1;
        else{
            x=x-n0;
            y=y-(n1-n0);
        }
    }
    printf("(%lld,%lld)\n",x,y);
    return 0;
}
