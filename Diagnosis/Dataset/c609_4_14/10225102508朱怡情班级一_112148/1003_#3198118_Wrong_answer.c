#include <stdio.h>
#include <math.h>

void f(int n)
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
        if(n)f(n);
        else printf("0");
        printf("\n");
    }
    return 0;
}