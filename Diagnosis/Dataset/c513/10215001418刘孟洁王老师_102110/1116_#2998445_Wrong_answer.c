#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long x,y,r,sum;
    scanf("%lld%lld",&x,&y);
    sum = abs(x)+abs(y);
    if(sum%2 == 0)printf("-1");
    else
    {
        for(r = 1; r < 42; r++)
        {
            if(pow(2,r-1)<=sum&&pow(2,r)>=sum)break;
        }
        //r = (log10(sum))/(log10(2))+1;
        printf("%lld",r);
    }
    return 0;
}