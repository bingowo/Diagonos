#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0; t<T; ++t) {
        int n, bit[32], k=0;
        scanf("%d", &n);
        do{
            bit[k++] = n % 2;
            n /= 2;
        }while(n);
        int max=1, len=0;
        for(k=k-2; k>=0; --k) {
            if(bit[k] != bit[k+1]){
                ++len;
                if(k==0 && len+1>max)
                    max = len + 1;
            }
            else {
                if(len+1>max)
                    max = len + 1;
                len = 0;
            }
        }
        printf("case #%d:\n%d\n",t,max);
    }
    return 0;
}
