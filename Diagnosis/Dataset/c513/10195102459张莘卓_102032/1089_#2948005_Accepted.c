#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int A, B, N, mod = 1, ans = 1;
        scanf("%d %d %d",&A, &B, &N);
        for(int i=0; i<N; ++i) mod *= 10;
        long long mult = A;
        while(B > 0) {
            if(B % 2) ans = mult * ans % mod;
            mult = mult * mult % mod;
            B /= 2;
        }
        printf("case #%d:\n%0*d\n",j,N,ans);
    }
    return 0;
}
