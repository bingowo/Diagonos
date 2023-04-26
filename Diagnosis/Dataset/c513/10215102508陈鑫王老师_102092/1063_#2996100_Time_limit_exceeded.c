#include<stdio.h>
#include<stdlib.h>
long long int solve(long long int x,long long int y)
{
    long long int ret;
    if(x==y)
        ret=4*y;
    else
    {

        if(y>(x-y))
        {
           ret=4*y+solve(y,x-y);
        }
        else
        {
            ret=4*y+solve(x-y,y);
        }
    }
    return ret;
}
int main()
{
    long long int x,y,ret;
    scanf("%lld %lld",&x,&y);
    ret=solve(x,y);
    printf("%lld",ret);
    return 0;

}
