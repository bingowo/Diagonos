#include <stdio.h>
int main()
{
    long long int x=0,y=0;
    scanf("%lld %lld",&x,&y);
    long long int sum=0;
    while(x!=0 && y!=0)
    {
        long long int min= x>y? y:x;
        sum+=min*4;
        if(x>y) x=min-x;
        else y=min-y;
    }
    printf("%lld",sum);
    return 0;
}