#include <stdio.h>

int findMin(int n) {
    n += n << 8;
    int t = 255, min = 256;
    for(int i=0; i<8; ++i) {
        if((n>>i) % 256 < min)  min = (n>>i) % 256;
    }
    return min;
}

int main()
{
    int W, H, a[100][100]={0};
    scanf("%d %d",&W, &H);
    for(int i=0; i<H; ++i)
        for(int j=0; j<W; ++j) scanf("%d",&a[i][j]);
    for(int i=1; i<H-1; ++i)
        for(int j=1; j<W-1; ++j) {
            int m = a[i][j];
            int n = (a[i-1][j-1]>=m)*128+(a[i-1][j]>=m)*64+(a[i-1][j+1]>=m)*32+(a[i][j+1]>=m)*16+(a[i+1][j+1]>=m)*8+(a[i+1][j]>=m)*4+(a[i+1][j-1]>=m)*2+(a[i][j-1]>=m);
            printf("%d%s",findMin(n),j<W-2?" ":"\n");
        }
    return 0;
}
