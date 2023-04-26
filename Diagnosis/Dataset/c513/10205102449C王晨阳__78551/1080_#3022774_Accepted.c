#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1010

typedef struct bint {
    int num[MAXN];
    int len;
} BI;

void ql(BI *s) // 去0
{
    int l = s->len - 1;
    while (s->num[l] == 0 && l >= 0)
        l--;
    s->len = l + 1;
}

char shu[MAXN];

void getshu(BI *s) {
    scanf("%s", shu);
    int len = strlen(shu);
    int l = 0;
    for (int i = len - 1; i >= 0; i--) {
        s->num[l++] = shu[i] - '0';
    }
    //printf("\n");
    s->len = len;
}

void reverse(BI *s) {
    int len = s->len;
    for (int i = 0; i < len / 2; i++) {
        int temp;
        temp = s->num[i];
        s->num[i] = s->num[len - 1 - i];
        s->num[len - 1 - i] = temp;
    }
    int l = len - 1;
    while (l >= 0 && s->num[l] == 0)
        l--;
    s->len = l + 1;
}

void pri(BI *s) {
    for (int i = s->len - 1; i >= 0; i--)
        printf("%d", s->num[i]);
    printf("\n");
}

int chu2(BI *d, BI *s) {
    int y = 0;
    for (int i = s->len - 1; i >= 0; i--) {
        d->num[i] = (y * 10 + s->num[i]) / 2;
        y = s->num[i] % 2;
    }
    ql(d);
    return y;
}

void che2(BI *d, BI *s) {
    int jw = 0;
    int len = s->len;
    for (int i = 0; i < len; i++) {
        d->num[i] = jw + s->num[i] * 2;
        if (d->num[i] >= 10) {
            d->num[i] -= 10;
            jw = 1;
        } else
            jw = 0;
    }
    if (jw == 1) {
        d->num[len] = 1;
        len++;
    }
    d->len = len;
}

void csh(BI *s) // initialized
{
    memset(s->num, 0, sizeof(s->num));
    s->len = 0;
}

void cpy(BI *d, BI *s) {
    int len;
    len = d->len = s->len;
    for (int i = 0; i < len; i++)
        d->num[i] = s->num[i];
}

void d2bin(BI *d, BI *b) {
    BI d1, d2;
    cpy(&d1, d);
    cpy(&d2, d);
    int y = 0;
    int l = 0;
    //pri(&d1);
    int k = 0;
    while (d1.len != 0) {
        b->num[l++] = chu2(&d2, &d1);
        //pri(&d2);
        cpy(&d1, &d2);
        //k++;
        //printf("%d\n", d1.len);
    }
    b->len = l;
}

void bin2d(BI *d, BI *b) {
    if (b->len <= 0)
        return;
    BI d1, d2;
    csh(&d1);
    csh(&d2);
    d1.num[0] = 0;
    d1.len = 1;
    for (int i = b->len - 1; i > 0; i--) {
        if (b->num[i] == 1)
            d1.num[0]++;
        che2(&d2, &d1);
        cpy(&d1, &d2);
        //pri(&d1);
    }
    if (b->num[0] == 1)
        d1.num[0]++;
    cpy(d, &d1);
}

BI shu1, shu2, bin1;

int main() {
    int pnum;
    scanf("%d\n", &pnum);
    for (int i = 0; i < pnum; i++) {
        csh(&shu1);
        csh(&shu2);
        csh(&bin1);
        getshu(&shu1);
        d2bin(&shu1, &bin1);
        reverse(&bin1);
        bin2d(&shu2, &bin1);
        printf("case #%d:\n", i);
        if (bin1.len <= 0)
            printf("0\n");
        else
            pri(&shu2);
    }
    return 0;
}