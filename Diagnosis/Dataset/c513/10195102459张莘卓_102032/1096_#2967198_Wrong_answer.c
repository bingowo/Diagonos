#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int n, cnt[101] = {0};
        scanf("%d",&n);
        int a, b, flag = 1;
        for(int i=0; i<n; ++i) {
            scanf("%d %d",&a, &b);
            if(cnt[a]) flag = 0;
            cnt[b] = 1;
        }
        if(flag) printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}
