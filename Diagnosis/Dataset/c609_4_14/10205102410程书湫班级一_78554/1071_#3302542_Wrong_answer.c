#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    unsigned long long sum=abs(x)+abs(y);
    if(x==0&&y==0)
    {
        printf("0");
    }
    else if(sum%2==0)
    {
        printf("-1");
    }
    else
    {
        unsigned long long r=(unsigned long long)(log(sum)/log(2))+1;
        printf("%llu",r);
    }
    return 0;
}
