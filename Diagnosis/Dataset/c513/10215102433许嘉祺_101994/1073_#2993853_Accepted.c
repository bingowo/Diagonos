#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long check(long long k){
    return (k<9)?k:check(k/10)*9+k%10;
}
long long f(long long x){
    long long d0=x%10;
    int count=0;
    for (long long i=x-x%10;i<=x;i++)
        if (i%9!=0) count++;
    return count+8*check(x-d0)/9;
}
int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld",f(b)-f(a)+1);
    return 0;
}
