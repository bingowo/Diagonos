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
            if(a[x] && y!=b[a[x]-1]) flag = 0;
            a[x] = i + 1;
            b[i] = y;
        }
        for(int i=0; i<n; ++i) {
            if(a[b[i]]){
                flag = 0;
                break;
            }
        }
        if(flag) printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}