#include <stdio.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        long long n;
        scanf("%lld",&n);
        if(n == 1) {
            printf("1 is powerless.\n");
            continue;
        }
        printf("%lld",n);
        int cnt=0, bin=4, i;
        long  long sup = sqrt(n)+1;
        for(int b=2; b<64; ++b) {
            if(b >= bin) {
                bin *= 2;
                sup = sqrt(sup) + 1;
            }
            long long l=1, r=sup, m=(l+r)/2;
            while(l <= r) {
                long long ans = 1;
                for(i=0; i<b && n/ans>=m; ++i) ans *= m;
                if(i < b) r = m-1;
                else if(ans != n) l = m+1;
                else {
                    printf("=%lld^%d",m,b);
                    ++cnt;   break;
                }
                m = (l+r) / 2;
            }
        }
        if(! cnt) printf(" is powerless.");
        printf("\n");
    }
    return 0;
}