#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define  MAXN 300
typedef struct TERM{
    int coef;
    int exp;
}TERM;
TERM poly[MAXN];

int ah=0,at=0,bh=1,bt,ch,ct;
int freeP;

int append(int c,int e){
    poly[freeP].coef = c;
    poly[freeP++].exp=e;
    return 0;
}

int poly_mul()
{
    int p,q;
    p=ah;
    while(p<=at)
    {
        q=bh;
        while(q<=bt)
        {
            append(poly[p].coef*poly[q].coef,poly[p].exp+poly[q].exp);
            q++;
        }
        p++;
    }
    return 0;
}

void readpoly(char *s, int h,int t) {
    while (*s) {
        int sign = 1, coef = 0, dim = 0;
        if (*s == '+') s++;
        else if (*s == '-') sign = -1, s++;
        while (isdigit(*s)) {
            coef = coef * 10 + *s - '0';
            s++;
        }
        if (coef == 0) coef = 1;
        if (*s != 'x') {
            poly[t].coef=coef * sign;
            poly[t++].exp=0;
            if(h==0)
                at++;
            bt++;
            return;
        }
        else s++;
        if (*s == '^') s++;
        while (isdigit(*s)) {
            dim = dim * 10 + *s - '0';
            s++;
        }
        if (dim == 0) dim = 1;
        poly[t].exp=dim;
        poly[t++].coef = coef * sign;
        if(h==0)
            at++;
        bt++;
    }
}
void line(int h,int t)
{
    int temp;
    for(int i=h;i<t;i++)
    {
        for(int j=i+1;j<=t;j++)
        {
            if(poly[i].exp<poly[j].exp)
            {
                temp=poly[i].coef;
                poly[i].coef=poly[j].coef;
                poly[j].coef=temp;
                temp=poly[i].exp;
                poly[i].exp=poly[j].exp;
                poly[j].exp=temp;
            }
        }
    }
    for(int i=h;i<t;i++)
    {
        int j;
        if(poly[i].exp==poly[i+1].exp)
        {
            j=i;
            while(poly[j].exp==poly[j+1].exp)
            {
                poly[i].coef+=poly[j+1].coef;
                poly[j+1].coef=0;
                j++;
            }
            i=j+1;
        }
    }
}


int main() {
    char s1[101], s2[101];
    while (scanf("%s%s", s1, s2) == 2) {
        ah=0,at=0,bh=1,bt=0;
        readpoly(s1,ah,0);
        readpoly(s2,bh,at);
        bh=at;at--;
        freeP=bt;
        ch=bt;
        bt--;
        poly_mul();
        ct=freeP-1;
        line(ch,ct);
        for(int i=ch;i<=ct;i++)
        {
            if(poly[i].coef!= 0)
                printf("%d%c",poly[i].coef,i==ct?'\n':' ');
        }
    }
    return 0;
}
