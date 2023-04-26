#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    int bits[20001], next[20001];
    int zeronum = 0, zeropos = 0, onepos = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &bits[i]);
        if (bits[i] == 0)
            zeronum++;
    }
    onepos = zeronum;
    for (int i = 1; i <= n; i++) {
        if (bits[i] == 0)
            next[++zeropos] = i;
        else
            next[++onepos] = i;
    }
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (next[next[i]] == i) {
            printf("-1\n");
            k = 1;
            break;
        }
    }
    if (k == 0) {
        int pos = 1;
        for (int i = 1; i <= n; i++) {
            pos = next[pos];
            printf("%d%c", bits[pos], i < n ? ' ' : '\n');
        }
    }
    return 0;
}
