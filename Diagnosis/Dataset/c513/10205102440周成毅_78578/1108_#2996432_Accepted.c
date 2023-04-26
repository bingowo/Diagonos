#include <stdio.h>
#include <string.h>

#define MAXN 1010

int gcd(int a, int b) {
    return b > 0 ? gcd(b, a % b) : a;
}

char shu[MAXN];
int beic[MAXN];

int chong(int *b, int len) {
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++)
            if (b[i] != 0 && b[i] == b[j])
                return i + 1;
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    int fz, fm;
    for (int i = 0; i < T; i++) {
        memset(shu, 0, sizeof(shu));
        memset(beic, 0, sizeof(beic));
        fz = fm = 0;
        scanf("%d %d\n", &fz, &fm);
        int g = gcd(fz, fm);
        fz /= g;
        fm /= g;
        int i1 = 0;
        while (!chong(beic, i1)) {
            fz *= 10;
            beic[i1] = fz;
            shu[i1] = fz / fm + '0';
            fz %= fm;
            if (fz == 0)
                break;
            i1++;
        }
        if (chong(beic, i1))
            shu[i1 - 1] = '\0';
        printf("case #%d:\n0.%s\n", i, shu);
        if (fz != 0)
            printf("%d-%d\n", chong(beic, i1), i1 - 1);
    }
    return 0;
}