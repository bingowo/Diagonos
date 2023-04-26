#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    long long t,k,
    x,y,j;
    scanf("%lld",&t);
    k=(long long)sqrt(1.0*t);
    j=t-k*k;
    if(k%2){
            x=k/2;
            y=x+1;
            if(j&&j<=k) x-=j;
            if(j>k) {x-=k;y=y-j+k;}
            }
    else{
        x=(k/2)*(-1);
        y=(k/2)*(-1);
        if(j&&j<=k) x+=j;
        if(j>k)    {x+=k;y=y+j-k;}
    }
    printf("(%lld,%lld)",x,y);
}