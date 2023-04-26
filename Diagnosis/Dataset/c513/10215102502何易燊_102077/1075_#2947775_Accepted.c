#include <stdio.h>
#include <stdlib.h>

int min(int a,int b)
{
    return (a<b)?a:b;
}

int main()
{
    int m,n; scanf("%d %d",&m,&n);
    int *block[201];
    for (int i=0;i<201;i++) block[i] = (int*)malloc(sizeof(int)*201);
    char ans[501] = {}; int index = 0;
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++) scanf("%d",&block[i][j]);
    for (int i=1;i<n;i++) block[0][i] += block[0][i-1];
    for (int j=1;j<m;j++) block[j][0] += block[j-1][0];
    for (int i=1;i<m;i++)
        for (int j=1;j<n;j++) block[i][j] += min(block[i-1][j],block[i][j-1]);
    printf("%d\n",block[m-1][n-1]);

    int x = m-1, y = n-1;
    while (x||y)
    {
        if (x==0) {ans[index++] = 'R'; y--;}
        else if (y==0) {ans[index++] = 'D'; x--;}
        else if (block[x-1][y]<block[x][y-1]) {ans[index++] = 'D';x--;}
        else {ans[index++] = 'R';y--;}
    }
    for (int i=index-1;i>=0;i--) printf("%c",ans[i]);
    printf("\n");
    return 0;
}