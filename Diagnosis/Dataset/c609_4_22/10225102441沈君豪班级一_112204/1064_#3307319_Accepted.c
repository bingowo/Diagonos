#include <stdio.h>
#include <stdlib.h>

long long int f(long long int m,long long int n)
{
    if(m==0||n==0){
        return 0;
    }else{
        if(m>n){
            return 4*n*(m/n)+f(n,m%n);
        }else{
            return 4*m*(n/m)+f(m,n%m);
        }
    }
}

int main()
{
    long long int x=0;
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    x=f(a,b);
    printf("%lld",x);
    return 0;
}
