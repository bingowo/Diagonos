#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0; t<T; ++t) {
        int a[11][11] = {0};
        int r, c, n, k, cnt=0;
        scanf("%d %d %d %d",&r, &c, &n, &k);
        for(int i=0; i<n; ++i) {
            int x, y;
            scanf("%d %d",&x, &y);
            a[x][y] = 1;
        }
        for(int i=1; i<=r; ++i){
            for(int j=1; j<=c; ++j) { // a[i][j]
                for(int h=0; h+i<=r; ++h)
                    for(int w=0; w+j<=c; ++w) { // set width and height
                        int tcnt = 0;
                        for(int pi=i; pi<=i+h; ++pi)
                            for(int pj=j; pj<=j+w; ++pj) // sub points
                                if(a[pi][pj]) ++tcnt;
                        if(tcnt >= k) ++cnt;
                    }
            }
        }
        printf("case #%d:\n%d\n",t,cnt);
    }
    return 0;
}
