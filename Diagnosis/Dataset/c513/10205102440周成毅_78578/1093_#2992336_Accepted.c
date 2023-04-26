#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1010

typedef struct bint{
    int n[MAXN];
    int l;
}   BI;

void pri(BI*);
void cshn(BI*, int, int);
void cpy(BI*, BI*);
void jia(BI*, BI*, BI*);
void zhuan(BI*, char *);
void fu0(BI *a, int k);
int fh(BI*);

char s[MAXN];
BI shu, shu1, x;

int main()
{
    scanf("%s\n", s);
    cshn(&shu, 0, 0);
    zhuan(&shu, s);
    int k = 1;
    do{
        cshn(&shu1, 0, 0);
        cpy(&shu1, &shu);
        fu0(&shu1, k-1);
        cshn(&x, k, 1);
        /*pri(&shu);
        printf("\n");
        pri(&x);
        printf("\n");*/
        jia(&shu1, &x, &shu);
    }   while((k = fh(&shu)) != -1);
    pri(&shu);
    printf("\n");
    return 0;
}

void pri(BI *a)
{
    if (a->l == 0)
        printf("0");
    else
        for (int i = a->l-1; i >= 0; i--)
            printf("%d", a->n[i]);
}

void cshn(BI *a, int l, int k)
{
    memset(a->n, 0, sizeof(a->n));
    a->l = l;
    if (l != 0)
        a->n[l-1] = k;
}

void cpy(BI *d, BI *s)
{
    d->l = s->l; 
    for (int i = 0; i < s->l; i++)
        d->n[i] = s->n[i];
}

void jia(BI *a, BI *b, BI *c)
{
    int len = a->l > b->l ? a->l : b->l;
    int jw = 0;
    for (int i = 0; i < len; i++)
    {
        c->n[i] = a->n[i] + b->n[i] + jw;
        if (c->n[i] >= 10)
        {
            jw = c->n[i] / 10;
            c->n[i] %= 10;
        }
        else
            jw = 0;
    }
    if (jw >= 1)
    {
        c->n[len++] = jw;
    }
    c->l = len;
}

void zhuan(BI *d, char *s)
{
    d->l = strlen(s);
    if (d->l == 1 && s[0] == '0')
    {
        d->l == 0;
        return;
    }
    for (int i = 0; i < d->l; i++)
        d->n[i] = s[d->l-i-1] - '0';
}

void fu0(BI *a, int k)
{
    if (k <= 0)
        return;
    for (int i = 0; i < k && i < a->l; i++)
        a->n[i] = 0;
}

int fh(BI *a)
{
    int s = 0;
    for (int i = a->l - 1; i >= 0; i--)
    {
        if (a->n[i] == 9)
            return i+1;
        s += a->n[i];
    }
    if (s % 9 == 0)
        return 1;
    return -1;
}

