#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1010
#define MAXS 10010

typedef struct bint {
    int n[MAXN];
    int l;
    int sign;
} BI;

typedef struct complex {
    BI re;
    BI im;
} COM;

void cshn(BI *a, int k, int n) {
    memset(a->n, 0, sizeof(a->n));
    a->l = k;
    if (k != 0)
        a->n[k - 1] = n;
    a->sign = 0;
}

void cpy(BI *d, BI *s) {
    d->l = s->l;
    d->sign = s->sign;
    for (int i = s->l - 1; i >= 0; i--)
        d->n[i] = s->n[i];
}

void pri(BI *a) {
    if (a->l == 0)
        printf("0");
    else
        for (int i = a->l - 1; i >= 0; i--)
            printf("%d", a->n[i]);
}

void pric(COM *s) {
    if (s->re.l == 0 && s->im.l == 0)
        printf("0");
    else if (s->re.l == 0) {
        if (s->im.sign == -1)
            printf("-");
        if (!(s->im.l == 1 && s->im.n[0] == 1))
            pri(&(s->im));
        printf("i");
    } else if (s->im.l == 0) {
        if (s->re.sign == -1)
            printf("-");
        pri(&(s->re));
    } else {
        if (s->re.sign == -1)
            printf("-");
        pri(&(s->re));
        if (s->im.sign == -1)
            printf("-");
        else
            printf("+");
        if (!(s->im.l == 1 && s->im.n[0] == 1))
            pri(&(s->im));
        printf("i");
    }
    printf("\n");
}

void jia(BI *a, BI *b, BI *c) {
    int len = a->l > b->l ? a->l : b->l;
    int jw = 0;
    for (int i = 0; i < len; i++) {
        c->n[i] = a->n[i] + b->n[i] + jw;
        if (c->n[i] >= 10) {
            jw = c->n[i] / 10;
            c->n[i] %= 10;
        } else
            jw = 0;
    }
    while (jw >= 1) {
        c->n[len] = jw % 10;
        jw /= 10;
        len++;
    }
    c->l = len;
}

void de0(BI *a) {
    int l = a->l;
    while (l > 0 && a->n[l - 1] == 0)
        l--;
    if (l < 0)
        a->l = 0;
    else
        a->l = l;
}

void jian(BI *a, BI *b, BI *c) {
    int len = a->l > b->l ? a->l : b->l;
    c->l = len;
    BI a1;
    cshn(&a1, 0, 0);
    cpy(&a1, a);
    for (int i = 0; i < len; i++) {
        c->n[i] = a1.n[i] - b->n[i];
        if (c->n[i] < 0) {
            c->n[i] += 10;
            a1.n[i + 1]--;
        }
    }
    if (a1.n[len] == -1) {
        cshn(&a1, len + 1, 1);
        BI c1;
        cshn(&c1, 0, 0);
        cpy(&c1, c);
        jian(&a1, &c1, c);
        c->sign = -1;
        de0(c);
        return;
    }
    de0(c);
    c->sign = 1;
    return;
}

void jiawy(BI *a, BI *b, BI *c) {
    if (a->l == 0) {
        cpy(c, b);
    } else if (b->l == 0) {
        cpy(c, a);
    } else if (a->sign < 0 && b->sign < 0) {
        jia(a, b, c);
        c->sign = -1;
    } else if (a->sign > 0 && b->sign < 0) {
        jian(a, b, c);
    } else if (a->sign < 0 && b->sign > 0) {
        jian(b, a, c);
    } else {
        jia(a, b, c);
        c->sign = 1;
    }
}

void shuche(BI *a, int k) {
    int len = a->l;
    int jw = 0;
    for (int i = 0; i < a->l; i++) {
        a->n[i] *= k;
        a->n[i] += jw;
        if (a->n[i] >= 10) {
            jw = a->n[i] / 10;
            a->n[i] %= 10;
        } else
            jw = 0;
    }
    while (jw >= 1) {
        a->n[len] = jw % 10;
        jw /= 10;
        len++;
    }
    a->l = len;
}

char s[MAXS];
COM cpx;
COM coms[16];

void cshcoms(int k, int pos) {
    if (pos < 0)
        return;
    int d = 1;
    d <<= pos;
    BI re, im, x1;
    cshn(&re, 0, 0);
    cshn(&im, 0, 0);
    //if (pos <= 2)
    //printf("%d\n", coms[k].re.sign);
    cpy(&re, &coms[k].re);
    cpy(&im, &coms[k].im);
    //printf("%d %d\n", re.sign, im.sign);
    re.sign *= -1;
    im.sign *= -1;
    jiawy(&re, &im, &coms[k].re);
    re.sign *= -1;
    jiawy(&re, &im, &coms[k].im);
    /*if (coms[k].re.l == 0)
        coms[k].re.sign = 1;
    if (coms[k].im.l == 0)
        coms[k].im.sign = 1;*/
    //printf("%d %d\n", coms[k].re.sign, coms[k].im.sign);
    if (d & k) {
        cshn(&re, 0, 0);
        cpy(&re, &coms[k].re);
        cshn(&x1, 1, 1);
        x1.sign = 1;
        //printf("%d %d\n", coms[k].re.sign, x1.sign);
        //printf("%d\n", coms[k].re.sign);
        jiawy(&x1, &re, &coms[k].re);

        //printf("%d\n", coms[k].re.sign);
    }
    //printf("\n");
    cshcoms(k, pos - 1);
}

int main() {
    for (int i = 0; i < 16; i++) {
        cshn(&coms[i].re, 0, 0);
        cshn(&coms[i].im, 0, 0);
        coms[i].re.sign = coms[i].im.sign = 1;
        cshcoms(i, 3);
    }
    scanf("%s\n", s);
    cshn(&cpx.re, 0, 0);
    cshn(&cpx.im, 0, 0);
    cpx.im.sign = cpx.re.sign = 1;
    int len = strlen(s);
    int z = 0;
    BI re, im;
    for (int i = 2; i < len; i++) {
        if (i > 2) {
            shuche(&cpx.re, 4);
            shuche(&cpx.im, 4);
            cpx.re.sign *= -1;
            cpx.im.sign *= -1;
        }
        if (s[i] >= '0' && s[i] <= '9')
            z = s[i] - '0';
        else
            z = s[i] - 'A' + 10;
        cshn(&re, 0, 0);
        cshn(&im, 0, 0);
        cpy(&re, &cpx.re);
        cpy(&im, &cpx.im);
        jiawy(&re, &coms[z].re, &cpx.re);
        jiawy(&im, &coms[z].im, &cpx.im);
    }
    pric(&cpx);
    return 0;
}