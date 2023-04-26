#include <stdio.h>

void lightSwitch(int (*a)[5], int i, int j) {
    a[i][j] = ! a[i][j];
    a[i+1][j] = ! a[i+1][j];
    a[i-1][j] = ! a[i-1][j];
    a[i][j+1] = ! a[i][j+1];
    a[i][j-1] = ! a[i][j-1];
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int k=0; k<T; ++k) {
        int light[5][5] = {0}, cnt[5][5];
        for(int i=1; i<=3; ++i)
            for(int j=1; j<=3; ++j){
                scanf("%d",&cnt[i][j]);
                cnt[i][j] %= 2;
                light[i][j] = 1;
            }
        for(int i=1; i<=3; ++i)
            for(int j=1; j<=3; ++j)
                if(cnt[i][j])
                    lightSwitch(light, i, j);
        printf("case #%d:\n",k);
        for(int i=1; i<=3; ++i)
            for(int j=1; j<=3; ++j)
                printf("%d%s",light[i][j],j<3?" ":"\n");
    }
    return 0;
}
