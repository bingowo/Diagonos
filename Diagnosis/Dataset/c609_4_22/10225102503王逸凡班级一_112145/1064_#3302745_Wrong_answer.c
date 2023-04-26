#include <stdio.h>
#include <stdlib.h>
long long int solve(long long int x,long long int y)
{
    if (x<y) //保证x比y大
    {
        int m;
        m=y;
        y=x;
        x=m;
    }
    long long int t =0;
    if (y==0){
        return 0;
    }
    if (x%y==0)
    {
        return x*y*4;
    }
    x -= y;
    t += y*4;
    return t+solve(x,y);
}
int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    long long int result = solve(x,y);
    printf("%lld",result);
    return 0;
}
