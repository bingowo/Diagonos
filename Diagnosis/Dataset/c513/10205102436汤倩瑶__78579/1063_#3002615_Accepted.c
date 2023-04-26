#include<stdio.h>
long long int f(long long int x,long long int y)
{
    long long int max=y>x?y:x;
    long long int min=y>x?x:y;
    if((max%min)==0)return(max/min)*4*min;
    return (max/min)*4*min+f(min,max%min);
    
    
    
    
}
int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld",f(x,y));
}