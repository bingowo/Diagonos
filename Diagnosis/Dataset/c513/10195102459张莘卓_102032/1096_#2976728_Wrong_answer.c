#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int n, a[101] = {0}, b[101] = {0};
        scanf("%d",&n);
        int x, y, flag = 1;
        for(int i=0; i<n; ++i) {
            scanf("%d %d",&x, &y);
            if(a[x] || b[x]) flag = 0;
            a[x] = b[y] = 1;
        }
        if(flag) printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}
