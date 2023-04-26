#include <stdio.h>
#include <string.h>

#define MAXN 40

typedef struct bint {
    int n[MAXN];
    int l;
} BI;

void pri(BI *);

void cshn(BI *, int, int);

void zjia(BI *, BI *);

BI f[110];

int main() {
    int n, k;
    scanf("%d %d\n", &k, &n);
    cshn(&f[0], 0, 0);
    cshn(&f[1], 1, 1);
    for (int i = 2; i < n; i++) {
        cshn(&f[i], 0, 0);
        for (int j = 1; j <= k; j++) {
            if (i - j < 0)
                break;
            zjia(&f[i], &f[i - j]);
        }
    }
    pri(&f[n - 1]);
    printf("\n");
    return 0;
}

void pri(BI *s) {
    if (s->l == 0)
        printf("0");
    for (int i = s->l - 1; i >= 0; i--)
        printf("%d", s->n[i]);
}

void cshn(BI *s, int l, int k) {
    memset(s->n, 0, sizeof(s->n));
    s->l = l;
    if (l == 0)
        return;
    else
        s->n[l - 1] = k;
}

void zjia(BI *d, BI *s) {
    int l = s->l > d->l ? s->l : d->l;
    int jw = 0;
    for (int i = 0; i < l; i++) {
        d->n[i] += s->n[i] + jw;
        if (d->n[i] >= 10) {
            jw = d->n[i] / 10;
            d->n[i] %= 10;
        } else
            jw = 0;
    }
    while (jw >= 1) {
        d->n[l++] = jw % 10;
        jw /= 10;
    }
    d->l = l;
}