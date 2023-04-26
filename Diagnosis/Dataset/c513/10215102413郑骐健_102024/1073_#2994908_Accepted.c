#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long s[200];
long long good(long long a,long long b)
{
    if(b-a<=10)
    {
        int n =0;
        for(long long p = a;p<=b;p++)
        {
            if(p%9==0)continue;
            else n++;
        }
        return n;
    }
    int cnt =0 ;
    long long p = 0;
    long long a_ = a;
    long long b_1 = b;
    long long b_ = b;
    while(b_1!=0)
    {
        b_1/=10;
        cnt++;
        p*=10;
        if(p==0)p++;
    }
    long long num =0;

    for(int k = cnt;k>1;k--)
    {
        num+=(b_/p)*s[k-1];
        b_-=(b_/p*p) ;
        p/=10;
    }
    num +=good(b-b%10,b);
    return num;

}


int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long long k=0;

    s[1] = 8;
    for(int g=2;g<19;g++)
    {
        s[g] = s[g-1]*9;
    }

    k +=good(1,b);
    k=k-good(1,a)+1;
    printf("%lld",k);
    return 0;
}
