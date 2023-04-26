#include <stdio.h>

int a[101][101];

long getvalue(int x,int y)
{
    char s[16];
    int n = a[x][y];
    s[0]=a[x-1][y-1]>=n,s[1]=a[x-1][y]>=n,s[2]=a[x-1][y+1]>=n;
    s[3]=a[x][y+1]>=n,s[4]=a[x+1][y+1]>=n,s[5]=a[x+1][y]>=n;
    s[6]=a[x+1][y-1]>=n,s[7]=a[x][y-1]>=n;
    for (int i=0;i<8;i++) s[i] += '0';
    for (int i=0;i<8;i++) s[i+8] = s[i];
    long min = 255;
    for (int i=0;i<8;i++)
    {
        char t[9] = {};
        for (int j=0;j<8;j++) t[j] = s[i+j];
        if (strtol(t,NULL,2)<min) min = strtol(t,NULL,2);
    }
    return min;
}

int main()
{
    int W,H; scanf("%d %d",&W,&H);
    for (int i=1;i<=H;i++)
        for (int j=1;j<=W;j++) scanf("%d",&a[i][j]);
    int ans[101][101] = {};
    for (int i=2;i<=H-1;i++)
    {
        for (int j=2;j<=W-1;j++)
        {
            printf("%ld ",getvalue(i,j));
        }
        printf("\n");
    }
    return 0;
}