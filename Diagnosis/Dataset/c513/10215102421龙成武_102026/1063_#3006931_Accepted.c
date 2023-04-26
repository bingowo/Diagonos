#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
long long int calit(long long int x,long long int y)
{
    if(x>=y)
    {
        if(x%y==0)
            return 4*y*(x/y);
        else
            return 4*y+calit(x-y,y);
    }
    else
    {
        if(y%x==0)
            return 4*x*(y/x);
        else
            return 4*x+calit(x,y-x);
    }
}
int main()
{
    long long int x,y,temp,ans;
    scanf("%lld%lld",&x,&y);
    ans=calit(x,y);
    printf("%lld",ans);
    return 0;
}
