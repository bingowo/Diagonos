#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
long long solve(long long a,long long b)
{
    long long m=a,n=b;
    if(a==b)return 4*a;
    else{
        if(a>b)return solve(b,b)+solve(a-b,b);
        if(a<b){
            return solve(a,a)+solve(b-a,a);
        }
    }
}
int main()
{
    long long x,y;scanf("%lld %lld",&x,&y);
    long long res;
    res=solve(x,y);
    printf("%lld",res);
    return 0;
}
