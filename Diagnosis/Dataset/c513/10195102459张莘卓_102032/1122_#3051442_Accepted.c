#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        long long n;
        scanf("%lld",&n);
        int i=0, num[20] = {0};
        do {
            num[i++] = n % 2333;
        }while(n /= 2333);
        for(i=i-1; i>=0; --i)
            printf("%d%s",num[i],i?" ":"\n");
    }
    return 0;
}