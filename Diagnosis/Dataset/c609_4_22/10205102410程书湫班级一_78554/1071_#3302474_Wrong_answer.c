#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    long long int sum=abs(x)+abs(y);
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
        long long int r=(long long int)(log(sum)/log(2))+1;
        printf("%lld",r);
    }
    return 0;
}
