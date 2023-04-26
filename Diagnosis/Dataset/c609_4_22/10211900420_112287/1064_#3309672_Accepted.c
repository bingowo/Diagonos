#include<stdio.h>
#include<stdlib.h>
#include<string.h>
unsigned long long f(unsigned long long x,unsigned long long y)
{
    if(x==0 || y==0) return 0;
    if(x==y) return 4*x;
    if(x>y) return 4*y*(x/y)+f(x%y,y);
    if(x<y) return 4*x*(y/x)+f(x,y%x);
}
int main()
{
    unsigned long long sum,x,y;
    scanf("%llu %llu",&x,&y);
    sum=f(x,y);
    printf("%llu",sum);
    return 0;
}
