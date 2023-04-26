#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 1000

long long llabs(long long a){return a>0?a:-a;}

long long solve(long long n)
{
    if(n==0)return 0;
    if(!n%2)return -1;
    int cnt=0;
    while(n){
        cnt++;
        n>>=1;
    }
    return cnt;
}

int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    long long t=llabs(x)+llabs(y);
    printf("%lld",solve(t));
    return 0;
}
