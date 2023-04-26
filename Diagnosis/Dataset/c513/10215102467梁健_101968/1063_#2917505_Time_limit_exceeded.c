#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
long long solve(long long a,long long b)
{
    long long m=a,n=b;
    if(m==n)return 4*a;
    else{
        if(m>n)return solve(n,n)+solve(m-n,n);
        if(m<n){
            m=b;n=a;
            return solve(n,n)+solve(m-n,n);
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
