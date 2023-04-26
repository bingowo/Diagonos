#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int subpower(int x)
{
    int a=1,sum=0;
    for(int i=0;i<x;i++)
    {
        sum+=a;
        a=a*2;
    }
    return sum;
}

int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    if((llabs(x)+llabs(y))%2==0)
    {
        printf("-1");
        return 0;
    }
    for(int i=3;;i++)
    {
        long long int left=subpower(i-1),right=subpower(i);
        if(left<(llabs(x)+llabs(y)) && right>=((llabs(x)+llabs(y))))
                 {
                     printf("%d",i);
                     return 0;
                 }
        else if(left==(llabs(x)+llabs(y)))
        {
            printf("%d",i-1);
            return 0;
        }
    }
}