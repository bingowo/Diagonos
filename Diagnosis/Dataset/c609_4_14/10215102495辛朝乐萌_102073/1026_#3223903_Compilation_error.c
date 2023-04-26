#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct str{
    char s[10000];
    int num;
}Strr;

int solve(Strr s[])
{
    int len= strlen(s);
    int res=0;
    int a[10000];
    for (int i = 0; i < len; ++i) {
        a[i]=-1;
    }
    for (int i = 0; i < len; ++i) {
        if (a['s[i]'']==-1) {
            res++;
            s[i].num++;
            a['s[i]'']++;
        } else continue;
    }
    return res;
}

int cmp(const void *a,const void *b)
{
    Strr *m,*n;
    m=(Strr *)a;
    n=(Strr *)b;
    if (m->num!=n->num) return m->num-n->num;
    else return strcmp(m->s,n->s);
}


int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        Strr str[n];
        for (int j = 0; j < n; ++j) {
            scanf("%s",str[j].s);
        }
        qsort(str,n, sizeof(str),cmp);
        for (int j = 0; j < n; ++j) {
            printf("%s",str[j].s);
        }
    }
    return 0;
}