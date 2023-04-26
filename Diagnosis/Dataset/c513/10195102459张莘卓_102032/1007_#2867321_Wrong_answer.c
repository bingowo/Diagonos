#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0; t<T; ++t) {
        int n, k=0, bit[32];
        scanf("%d",&n);
        for(; n; ++k) {
            bit[k] = n % 2;
            n /= 2;
        }
        int max=0, len=0;
        for(k=k-1; k>0; --k) {
            if(bit[k] != bit[k-1]){
                ++len;
                if(k==1 && len+1>max) max = len+1;
            }
            else {
                if(len+1 > max) max = len+1;
                len = 0;
            }
        }
        printf("case #%d:\n%d\n",t,max);
    }
    return 0;
}
