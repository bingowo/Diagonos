#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main()
{
    char c;
    int W, H, D, a[200][200] = {0};
    scanf("%d %d %d %c",&W, &H, &D, &c);
    D %= 360;
    if(D == 270) {
        D = 90;
        c = c=='L' ? 'R' : 'L';
    }
    for(int i=0; i<H; ++i)
        for(int j=0; j<W; ++j) scanf("%d",&a[i][j]);
            
    if(D == 90) {
        printf("%d %d\n",H, W);
        if(c == 'R') {
            for(int i=0; i<W; ++i)
                for(int j=H-1; j>=0; --j)
                    printf("%d%s",a[j][i], j?" ":"\n");
        }else {
            for(int i=W-1; i>=0; --i)
                for(int j=0; j<H; ++j)
                    printf("%d%s",a[j][i],j<H-1?" ":"\n");
        }
    }else {
        printf("%d %d\n",W, H);
        if(D) {
            for(int i=H-1; i>=0; --i)
                for(int j=W-1; j>=0; --j)
                    printf("%d%s",a[i][j],j?" ":"\n");
        }else {
            for(int i=0; i<H; ++i)
                for(int j=0; j<W; ++j)
                    printf("%d%s",a[i][j], j<W-1?" ":"\n");
        }
    }
    return 0;
}
