#include <stdio.h>
#include <string.h>

#define MAXN 1010

typedef struct bint {
    int n[MAXN];
    int l;
} BI;

void cshn(BI *, int, int);

void pri(BI *);

void cpy(BI *, BI *);

int shuche(BI *, int);

long long f(char *);

char s[MAXN];
BI shu;

int main() {
    scanf("%s", s);
    cshn(&shu, 1, 1);
    long long shu = f(s);
    printf("%d\n", shu);
    return 0;
}

void cshn(BI *a, int l, int n) {
    memset(a->n, 0, sizeof(a->n));
    a->l = l;
    if (l != 0)
        a->n[l - 1] = n;
}

void pri(BI *a) {
    if (a->l == 0)
        printf("0");
    else
        for (int i = a->l - 1; i >= 0; i--)
            printf("%d", a->n[i]);
}

void cpy(BI *d, BI *s) {
    d->l = s->l;
    for (int i = 0; i < s->l; i++)
        d->n[i] = s->n[i];
}

int shuche(BI *a, int k) {
    if (k <= 0)
        return 0;
    int l = a->l;
    int jw = 0;
    for (int i = 0; i < l; i++) {
        a->n[i] *= k;
        a->n[i] += jw;
        if (a->n[i] >= 10) {
            jw = a->n[i] / 10;
            a->n[i] %= 10;
        } else
            jw = 0;
    }
    while (jw >= 1) {
        a->n[l++] = jw % 10;
        jw /= 10;
    }
    a->l = l;
    return 1;
}

long long f(char *s) {
    int len = strlen(s);
    long long a = 1;
    int is = 0;
    if (len == 1)
        return a;
    if (s[is] != s[is + 1])
        a *= 2;
    is++;
    for (; is < len - 1; is++) {
        if (s[is] != s[is - 1] && s[is] != s[is + 1] && s[is - 1] != s[is + 1])
            a *= 3;
        else if (s[is] == s[is - 1] && s[is] == s[is + 1])
            continue;
        else
            a *= 2;
        if (a > 1000000007)
            a %= 1000000007;
    }
    if (s[is] != s[is - 1])
        a *= 2;
    if (a > 1000000007)
        a %= 1000000007;
    return a;
}
