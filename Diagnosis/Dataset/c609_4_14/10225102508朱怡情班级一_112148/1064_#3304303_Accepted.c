#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

long long r(long long m,long long n,long long sum)
{
    if(m!=0&&n!=0){
        long long a,b;
        a=n>m?n:m;
        b=n>m?m:n;
        long long cnt=a/b;
        sum+=4*b*cnt;
        r(a-cnt*b,b,sum);
    }
    else return sum;
}

int main()
{
    long long n,m;
    scanf("%lld%lld",&m,&n);
    printf("%lld",r(m,n,0));
    return 0;
}
