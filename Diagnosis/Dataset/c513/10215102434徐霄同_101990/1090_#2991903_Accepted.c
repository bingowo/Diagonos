#include <stdio.h>
#include <math.h>

int main()
{
    long long n,ans;
    double x;
    scanf("%lld",&n);
    while(n!=0){
        x=n*log10(n)-(long long)(n*log10(n));
        ans=(long long)pow(10,x);
        printf("%lld\n",ans);
        scanf("%lld",&n);
    }
    return 0;
}
