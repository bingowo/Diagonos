#include <stdio.h>
#include <stdlib.h>
long long int solve(long long int x,long long int y)
{
    long long int t =0;
    if (x==0||y==0){
        return 0;
    }
    if (x==1||y==1){
        return x*y*4;
    }
    if (x>=y){
        x -= y;
        t += y*4;
    }
    else
    {
        y -= x;
        t += x*4;
    }
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
