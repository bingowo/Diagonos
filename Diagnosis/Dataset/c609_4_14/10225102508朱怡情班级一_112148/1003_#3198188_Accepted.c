#include <stdio.h>
#include <math.h>

void f(long long n)
{
    if(n>0){
        f(n/2333);
        printf("%d ",n%2333);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        long long n;
        scanf("%lld",&n);
        if(n==0)printf("0");
        else f(n);
        printf("\n");
    }
    return 0;
}