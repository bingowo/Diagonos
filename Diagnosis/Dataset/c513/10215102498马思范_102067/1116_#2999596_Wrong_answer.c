#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long long x,y;
    int result=0;
    scanf("%lld%lld",&x,&y);
    if((llabs(x)+ llabs(y))%2==0)
    {
        printf("%d",-1);
    }
    else
    {
        for(int k=1;k<42;k++)
        {
            if((llabs(x)+ llabs(y)+1)<=pow(2,k)&&(llabs(x)+ llabs(y)+1)> pow(2,k-1))
            {
                result=k;
                break;
            }
        }
        printf("%d",result);
    }
    return 0;
}
