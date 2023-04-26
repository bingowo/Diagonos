#include <stdio.h>
#include <string.h>

#define MAXN 1010

int f[4][MAXN];

int main() {
    memset(f,0,sizeof(f));
    for (int i = 0; i < MAXN; i++)
        f[0][i] = 1;
    for (int i = 0; i < MAXN; i++)
        f[1][i] = i / 2 + 1;
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j <= i; j += 3)
            f[2][i] += f[1][i - j];
    f[2][0] = 1;
    f[2][1] = f[0][1];
    f[2][2] = f[1][2];
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j <= i; j += 4)
            f[3][i] += f[2][i - j];
    f[3][0] = 1;
    f[3][1] = f[0][1];
    f[3][2] = f[1][2];
    f[3][3] = f[2][3];
    int pnum;
    int n;
    scanf("%d", &pnum);
    while (pnum--) {
        scanf("%d", &n);
        printf("%d\n", f[3][n]);
    }
    return 0;
}