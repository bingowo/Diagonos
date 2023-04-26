#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; ++i) {
        long long N; int R;
        scanf("%lld %d",&N, &R);
        if(N < 0) {
            N = -N;
            printf("-");
        }else if(N == 0) {
            printf("0\n");
            break;
        }
        char bit[36]; int k = 0;
        for(k=0; N; ++k) {
            int t = N % R;
            N /= R;
            bit[k] = (t<10? '0'+t:'A'+t-10);
        }
        for(k=k-1; k>=0; --k)
            printf("%c",bit[k]);
        printf("\n");
    }
    return 0;
}
