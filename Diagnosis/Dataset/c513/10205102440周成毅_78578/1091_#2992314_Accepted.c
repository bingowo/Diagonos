#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 5000

typedef struct bint {
    int n[MAXN];
    int l;
    int sign;
} BI;

typedef struct complex {
    BI re;
    BI im;
} COM;

void cshn(BI *a, int l, int k);

void cshc0(COM *a);

void pri(BI *a);

void pric(COM *a);

void cpy(BI *d, BI *s);

void cpyc(COM *d, COM *s);

void scac(COM *d, char *s);

void jia(BI *a, BI *b, BI *c);

void de0(BI *a);

void de0com(COM *a);

void jian(BI *a, BI *b, BI *c);

void jiawy(BI *a, BI *b, BI *c);

void shuche(BI *a, int k);

void che(BI *a, BI *b, BI *c);

void checom(COM *a, COM *b, COM *c);

char s[10];
int n;
BI a1, a2, a3;
COM cpx;
COM cpx1;
COM cpx2;

int main() {
    scanf("%s %d\n", s, &n);
    cshc0(&cpx);
    scac(&cpx, s);
    cshc0(&cpx1);
    cshc0(&cpx2);
    cshn(&a1, 1, 1);
    cshn(&a2, 0, 0);
    cshn(&a3, 0, 0);
    //cpy(&a2, &cpx.re);
    //pri(&a2);
    //pric(&cpx);
    //printf("\n");
    cpx1.re.n[0] = 1;
    cpx1.re.l = 1;
    for (int i = 0; i < n; i++) {
        checom(&cpx1, &cpx, &cpx2);
        cpyc(&cpx1, &cpx2);
        de0com(&cpx1);
        cshc0(&cpx2);
        //pric(&cpx1);
        //printf("\n");
        /*pri(&a1);
        printf("\n");
        pri(&a2);
        printf("\n");
        che(&a1, &a2, &a3);
        cpy(&a1, &a3);
        cshn(&a3, 0, 0);
        pri(&a1);
        printf("\n");*/
    }
    pric(&cpx1);
    return 0;
}

void cshn(BI *a, int l, int k) {
    memset(a->n, 0, sizeof(a->n));
    a->l = l;
    if (l != 0)
        a->n[l - 1] = k;
    a->sign = 1;
}

void cshc0(COM *a) {
    cshn(&a->im, 0, 0);
    cshn(&a->re, 0, 0);
}

void pri(BI *a) {
    if (a->l == 0)
        printf("0");
    else
        for (int i = a->l - 1; i >= 0; i--)
            printf("%d", a->n[i]);
}

void pric(COM *a) {
    if (a->im.l == 0 && a->re.l == 0)
        printf("0");
    else if (a->im.l == 0) {
        if (a->re.sign == -1)
            printf("-");
        pri(&(a->re));
    } else if (a->re.l == 0) {
        if (a->im.sign == -1)
            printf("-");
        if (!(a->im.l == 1 && a->im.n[0] == 1))
            pri(&(a->im));
        printf("i");
    } else {
        if (a->re.sign == -1)
            printf("-");
        pri(&(a->re));
        if (a->im.sign == -1)
            printf("-");
        else
            printf("+");
        if (!(a->im.l == 1 && a->im.n[0] == 1))
            pri(&(a->im));
        printf("i");
    }
    printf("\n");
}

void cpy(BI *d, BI *s) {
    d->l = s->l;
    d->sign = s->sign;
    for (int i = s->l - 1; i >= 0; i--)
        d->n[i] = s->n[i];
}

void cpyc(COM *d, COM *s) {
    cpy(&d->im, &s->im);
    cpy(&d->re, &s->re);
}

void scac(COM *d, char *s) {
    int len = strlen(s);
    int i = len - 1;
    if (s[i] == 'i') {
        i--;
        int il = 0;
        while (i >= 0 && s[i] >= '0' && s[i] <= '9') {
            d->im.n[il++] = s[i] - '0';
            i--;
        }
        if (i == -1 && il == 0) {
            d->im.n[0] = 1;
            d->im.l = 1;
        } else if (il == 0) {
            d->im.n[0] = 1;
            d->im.l = 1;
            if (s[i] == '-')
                d->im.sign = -1;
        } else {
            d->im.l = il;
            if (s[i] == '-')
                d->im.sign = -1;
        }
        i--;
    }
    int rl = 0;
    while (i >= 0 && s[i] >= '0' && s[i] <= '9') {
        d->re.n[rl++] = s[i] - '0';
        i--;
    }
    d->re.l = rl;
    if (i == 0 && s[i] == '-') {
        d->re.sign = -1;
    }
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
    if (l == 0)
        return;
    else {
        while (l > 0 && a->n[l - 1] == 0)
            l--;
        a->l = l;
    }
}

void de0com(COM *a) {
    de0(&a->im);
    de0(&a->re);
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
    if (a->l == 0)
        cpy(c, b);
    else if (b->l == 0)
        cpy(c, a);
    else if (a->sign == 1 && b->sign == 1) {
        jia(a, b, c);
        c->sign = 1;
    } else if (a->sign == -1 && b->sign == -1) {
        jia(a, b, c);
        c->sign = -1;
    } else if (a->sign == 1 && b->sign == -1)
        jian(a, b, c);
    else if (a->sign == -1 && b->sign == 1)
        jian(b, a, c);
}

void che(BI *a, BI *b, BI *c) {
    if (a->l == 0 || b->l == 0) {
        cshn(c, 0, 0);
        return;
    }
    int l = 0;
    for (int i = 0; i < a->l; i++) {
        for (int j = 0; j < b->l; j++) {
            c->n[i + j] += a->n[i] * b->n[j];
            //printf("%d ", c->n[i+j]);
            if (c->n[i + j] >= 10) {
                c->n[i + j + 1] += c->n[i + j] / 10;
                c->n[i + j] %= 10;
            }
            //printf("%d\n", c->n[i+j]);
        }
    }
    int len = a->l + b->l - 1;
    int jw = c->n[len];
    while (jw >= 1) {
        c->n[len++] = jw % 10;
        jw /= 10;
    }
    c->l = len;
    if (a->sign == b->sign)
        c->sign = 1;
    else
        c->sign = -1;
    //pri(c);
    //printf("\n");
}

void checom(COM *a, COM *b, COM *c) {
    /*pric(a);
    printf("\n");
    pric(b);
    printf("\n");*/
    BI a11, a22, a12, a21;
    cshn(&a11, 0, 0);
    cshn(&a12, 0, 0);
    cshn(&a21, 0, 0);
    cshn(&a22, 0, 0);
    che(&a->re, &b->re, &a11);
    che(&a->im, &b->im, &a22);
    che(&a->re, &b->im, &a12);
    che(&a->im, &b->re, &a21);
    /*pri(&a11);
    printf("\n");
    pri(&a12);
    printf("\n");
    pri(&a21);
    printf("\n");
    pri(&a22);
    printf("\n");*/
    jiawy(&a12, &a21, &c->im);
    a22.sign *= -1;
    jiawy(&a11, &a22, &c->re);
}