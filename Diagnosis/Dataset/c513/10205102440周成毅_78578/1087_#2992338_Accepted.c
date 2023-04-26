#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1010

typedef struct bint {
    int n[MAXN];
    int l;
} BI;

void pri(BI *a) {
    if (a->l <= 0)
        printf("0");
    for (int i = a->l - 1; i >= 0; i--) {
        printf("%d", a->n[i]);
    }
    printf("\n");
}

void zhuan(char *s, BI *a) {
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        a->n[i] = s[len - 1 - i] - '0';
    a->l = len;
}

void csh(BI *s) {
    memset(s->n, 0, sizeof(s->n));
    s->l = 0;
}

void csh1(BI *s, int k) {
    memset(s->n, 0, sizeof(s->n));
    s->l = k;
    s->n[k - 1] = 1;
}

void cpy(BI *d, BI *s) {
    d->l = s->l;
    for (int i = s->l - 1; i >= 0; i--)
        d->n[i] = s->n[i];
}

void jia(BI *a, BI *b, BI *c) {
    int len = a->l > b->l ? a->l : b->l;
    int jw = 0;
    for (int i = 0; i < len; i++) {
        c->n[i] = a->n[i] + b->n[i] + jw;
        if (c->n[i] >= 10) {
            c->n[i] -= 10;
            jw = 1;
        } else
            jw = 0;
    }
    if (jw == 1) {
        c->n[len] = 1;
        len++;
    }
    c->l = len;
}

int cmp(BI *a, BI *b) {
    if (a->l < b->l)
        return -1;
    else if (a->l > b->l)
        return 1;
    for (int i = a->l - 1; i >= 0; i--)
        if (a->n[i] < b->n[i])
            return -1;
        else if (a->n[i] > b->n[i])
            return 1;
    return 0;
}

void qu9(BI *a) {
    int len = a->l;
    int i;
    int state = 0;
    for (i = len - 1; i >= 1; i--)
        if (a->n[i] == 9 && a->n[i - 1] == a->n[i]) {
            state = 1;
            break;
        }
    if (state == 1) {
        BI z, a1;
        csh1(&z, i + 1);
        csh(&a1);
        cpy(&a1, a);
        jia(&z, &a1, a);
        for (int k = i; k >= 0; k--)
            a->n[k] = 0;
    }
}

int chong1(BI *a) {
    int len = a->l;
    for (int i = len - 1; i >= 1; i--)
        if (a->n[i] == a->n[i - 1]) {
            //if (i == 0 || a->n[i-1] - a->n[i] != 1)
            //    return i;
            //else
            return i - 1;
        }
    return -1;
}

int chong2(BI *a) {
    int len = a->l;
    for (int i = 0; i < len - 1; i++)
        if (a->n[i] == a->n[i + 1]) {
            //if (i == 0 || a->n[i-1] - a->n[i] == 1)
            //    return i+1;
            //else
            return i;
        }
    return -1;
}

void f(BI *s, BI *d) {
    BI s1, s2, s0;
    BI a;
    csh(&s1);
    csh(&s0);
    cpy(&s1, s);
    cpy(&s0, s);
    //pri(&s1);
    while (chong1(&s1) != -1) {
        csh(&s2);
        cpy(&s2, &s1);
        csh(&a);
        a.l = chong1(&s1) + 1;
        a.n[a.l - 1] = 1;
        jia(&s2, &a, &s1);
        for (int i = a.l - 2; i >= 0; i--)
            s1.n[i] = 0;
        //pri(&s1);
    }
    //对010这种类型进行变换待做
    //pri(&s0);
    /*while (chong2(&s0) != -1)
    {
        csh(&s2);
        cpy(&s2, &s0);
        csh(&a);
        a.l = chong2(&s0) + 1;
        a.n[a.l-1] = 1;
        jia(&s2, &a, &s0);
        //pri(&s0);
    }
    if (cmp(&s0, &s1) == -1)
        cpy(d, &s0);
    else*/
    cpy(d, &s1);
}

char shu[MAXN];
BI shu1, shu2, shu3;

int main() {
    int pnum;
    scanf("%d\n", &pnum);
    for (int i = 0; i < pnum; i++) {
        scanf("%s\n", shu);
        csh(&shu1);
        //csh(&shu2);
        csh(&shu3);
        zhuan(shu, &shu1);
        //f(&shu1, &shu2);
        {
            BI a, k;
            csh1(&a, 1);
            csh(&k);
            cpy(&k, &shu1);
            jia(&k, &a, &shu1);
            f(&shu1, &shu3);
            //pri(&shu3);
            //printf("\n");
        }
        printf("case #%d:\n", i);
        //printf("%d\n", cmp(&shu2, &shu1));
        //if (cmp(&shu3, &shu2) == -1 || cmp(&shu2, &shu1) <= 0)
        pri(&shu3);
        //else
        //    pri(&shu2);
    }
    return 0;
}