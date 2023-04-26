#include<stdio.h>
#include<stdlib.h>
#include<string.h>
unsigned long long f(unsigned long long x,unsigned long long y)
{
    if(x==y) return 4*x;
    if(x>y) return 4*y+f(x-y,y);
    if(x<y) return 4*x+f(x,y-x);
}
int main()
{
    unsigned long long sum,x,y;
    scanf("%llu %llu",&x,&y);
    sum=f(x,y);
    printf("%llu",sum);
    return 0;
}
