#include <stdio.h>

int main() {
    int a[101][101];
    int b[101][101];
    int w, h;
    scanf("%d%d", &w, &h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int v[16];
    for (int i = 1; i < h - 1; i++) {
        for (int j = 1; j < w - 1; j++) {
            if (a[i - 1][j - 1] < a[i][j]) {
                v[0] = v[8] = 0;
            } else {
                v[0] = v[8] = 1;
            }
            if (a[i - 1][j] < a[i][j]) {
                v[1] = v[9] = 0;
            } else {
                v[1] = v[9] = 1;
            }
            if (a[i - 1][j + 1] < a[i][j]) {
                v[2] = v[10] = 0;
            } else {
                v[2] = v[10] = 1;
            }
            if (a[i][j + 1] < a[i][j]) {
                v[3] = v[11] = 0;
            } else {
                v[3] = v[11] = 1;
            }
            if (a[i + 1][j + 1] < a[i][j]) {
                v[4] = v[12] = 0;
            } else {
                v[4] = v[12] = 1;
            }
            if (a[i + 1][j] < a[i][j]) {
                v[5] = v[13] = 0;
            } else {
                v[5] = v[13] = 1;
            }
            if (a[i + 1][j - 1] < a[i][j]) {
                v[6] = v[14] = 0;
            } else {
                v[6] = v[14] = 1;
            }
            if (a[i][j - 1] < a[i][j]) {
                v[7] = 0;
            } else {
                v[7] = 1;
            }
            int min=300;
            for(int x=0;x<8;x++)
            {
                int temp=0;
                for(int y=x,k=0;k<8;y++,k++)
                    temp=temp*2+v[y];
                min=(min<temp)?min:temp;
            }
            b[i][j]=min;
        }
    }
    for(int i=1;i<h-1;i++)
    {
        for(int j=1;j<w-1;j++)
        {
            printf("%d",b[i][j]);
            if(j==w-2)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}
