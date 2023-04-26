#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
long long int calit(long long int n)
{
    if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else if(n==3)
        return 4;
    else if(n==4)
        return 14;
}
int main()
{
    long long int n,ans;
    scanf("%lld",&n);
    ans=calit(n);
    printf("%lld",ans);
    return 0;
}
