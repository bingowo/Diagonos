#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0; t<T; ++t) {
        int x, y, cnt = 0;
        scanf("%d %d",&x, &y);
        int tmp = x ^ y;
        for(int p=0; p<32; ++p) {
            if((tmp>>p) & 1) ++cnt;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
