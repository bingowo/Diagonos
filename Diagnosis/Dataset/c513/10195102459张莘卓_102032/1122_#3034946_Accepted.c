#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int a[100]={0}, cnt=0;
        long long n;
        scanf("%lld",&n);
        do {
            a[cnt++] = n % 2333;
            n /= 2333;
        }while(n);
        for(int i=cnt-1; i>=0; --i)
            printf("%d%s",a[i],i?" ":"\n");
    }
    return 0;
}
